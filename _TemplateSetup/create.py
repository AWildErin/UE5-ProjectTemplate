"""
Please don't look too closely at what this codes does, it sucks but it works
in an idea world I would write this in C# or something, but python is the best way to do this
"""

from gooey import Gooey, GooeyParser
from argparse import ArgumentParser
from pathlib import Path
import os, subprocess, re, configparser, shutil, stat

# Directories we do not scan to update files in
ignored_dirs = ['Intermediate', 'Saved', '_TemplateSetup', '.git', 'Plugins', 'doxygen-awesome-css', 'Content', '.vs', 'Binaries']
ignored_files = []
#ignored_files = ['README.md']

script_path = os.path.abspath(__file__)
script_directory = os.path.dirname(script_path)
root_path = os.path.dirname(script_directory)

submodule_status_regex = re.compile(r'(.*) (.*) \((.*)\)')
git_default_branch = 'main'

def fix_slashes(str) -> str:
    return str.replace('\\', '/')

def remove_readonly(func, path, _):
    "Clear the readonly bit and reattempt the removal"
    os.chmod(path, stat.S_IWRITE)
    func(path)

def remove_directory(path):
    shutil.rmtree(path, onexc=remove_readonly)

def build_file_list(path) -> list:
    file_list = []

    path = fix_slashes(path)

    for root, dirs, files in os.walk(path):
        dirs[:] = [d for d in dirs if d not in ignored_dirs]
        files[:] = [f for f in files if f not in ignored_files]

        for dir_name in dirs:
            sub_list = build_file_list(os.path.join(path, dir_name))

            if len(sub_list) != 0:
                file_list.append(sub_list)
                file_list.append(fix_slashes(os.path.join(path, dir_name)))

        for file_name in files:
            file_name = fix_slashes(file_name)
            file_list.append(fix_slashes(os.path.join(path, file_name)))

        break

    return file_list

def print_file_list(file_list, depth = 0):
    for x in file_list:
        if type(x) is list:
            print_file_list(x, depth+1)
        else:
            indent = depth*'\t'
            print(f'{indent}{x}')

def recursive_file_list_gather(name_dict, file_list) -> tuple[dict, dict]:
    """
    Returns 2 dicts, first is directories, second is files
    """
    dir_dict = {}
    file_dict = {}

    for x in file_list:
        # Process lists to get sub folders
        if isinstance(x, list):
            subdirs, subfiles = recursive_file_list_gather(name_dict, x)
            dir_dict.update(subdirs)
            file_dict.update(subfiles)
            continue

        new_path = x
        for k, v in name_dict.items():
            new_path = new_path.replace(k, v)

        if os.path.isdir(x):
            if new_path != x:
                dir_dict[x] = new_path

        if os.path.isfile(x):
            if new_path != x:
                file_dict[x] = new_path


    return dir_dict, file_dict

def replace_file_names(name_dict, file_list, dry_run=False):
    old_list = file_list

    # A map of old names to new names
    # Files are added first and renamed, then directories are renamed after
    rename_dict = {}

    dirs, files = recursive_file_list_gather(name_dict, file_list)

    rename_dict.update(dirs)
    rename_dict.update(files)

    print('Final names:')
    for k, v in rename_dict.items():
        print(f'\t{k} -> {v}')

    # If we're doing a dry run, no point going any further
    if dry_run:
        return

    # Rename files
    for k,v in files.items():
        current_dir = os.path.dirname(k)
        new_name = os.path.basename(v)
        os.rename(k, f'{current_dir}/{new_name}')


    # sort the list so sub dirs are first
    sorted_dirs = sorted(dirs, key=lambda p: p.count('/'), reverse=True)

    # then rename the folders
    for k in sorted_dirs:
        v = dirs[k]

        current_dir = os.path.dirname(k)
        new_name = os.path.basename(v)
        if not os.path.exists(f'{current_dir}/{new_name}'):
            os.rename(k, f'{current_dir}/{new_name}')

def replace_file_text(text_dict, file_list, dry_run = False):
    for x in file_list:
        if type(x) is list:
            replace_file_text(text_dict, x, dry_run)
            continue

        # Skip paths as they don't have file contents
        if os.path.isdir(x):
            continue

        changed_contents = False
        with open(x, 'r') as file:
            lines = file.readlines()

        for i, line in enumerate(lines):
            original_line = line

            for k, v in text_dict.items():
                line = line.replace(k, v)

            if line != original_line:
                print(f'\tReplacing in {x}: {original_line.strip()} -> {line.strip()}')
                lines[i] = line
                changed_contents = True

        if changed_contents and not dry_run:
            with open(x, 'w') as file:
                file.writelines(lines)

def run_git_command(cmd, in_cwd = ''):

    if in_cwd == '':
        cwd = root_path
    else:
        cwd = in_cwd

    proc = subprocess.Popen(['git'] + cmd, cwd=cwd)
    ret_code = proc.wait()

    if ret_code != 0:
        raise Exception(f'Failed to run git command \'{cmd}\', returned {ret_code}!')

def initialize_submodule(url, path, sha='', dry_run=False):
    # Delete the old files
    print(f'Initializing submodule at {path}, with sha {sha}')

    if not dry_run:
        # Delete the previous submodule
        remove_directory(f'{root_path}/{path}')

        # Init the latest submodule
        run_git_command(['submodule', 'add', url, path])

        # Checkout existing template sha
        run_git_command(['checkout', sha], f'{root_path}/{path}')


def initialize_git_repo(git_url, dry_run=False):
    print(f'Creating git repo at {git_url}')

    # Gather existing submodule information
    print('Getting submodule info')
    submodule_status = subprocess.check_output(['git', 'submodule', 'status'], cwd=root_path).decode('utf-8')
    submodule_shas = {}

    for line in submodule_status.splitlines():
        match = submodule_status_regex.match(line.strip())
        if match:
            sha, path, branch = match.groups()
            submodule_shas[path] = {'sha': sha, 'branch': branch}

    # Collect submodule urls
    config = configparser.ConfigParser()
    config.read(f'{root_path}/.gitmodules')

    for section in config.sections():
        path = config[section].get('path')

        submodule_shas[path] = {
            'sha': submodule_shas[path]['sha'],
            'branch': submodule_shas[path]['branch'],
            'url': config[section].get('url')
        }

    if git_url is None or git_url == '':
        print('No git_url passed, deleting existing repo and submodules (Keeping files)')

        if not dry_run:
            # Delete template git repo
            remove_directory(f'{root_path}/.git')

            # Remove submodule information
            for k, v in submodule_shas.items():
                os.remove(f'{root_path}/{k}/.git')

            os.remove(f'{root_path}/.gitmodules')
        return
    else:
        print(f'Initializing new repo with url: {git_url}')

    if not dry_run:
        # Delete template git repo
        remove_directory(f'{root_path}/.git')

        # Delete existing submodules so we can add them back
        os.remove(f'{root_path}/.gitmodules')

        # Initialize new repo
        run_git_command(['init'])
        run_git_command(['remote', 'add', 'origin', git_url])

    # Inititialize all submodules
    for k, v in submodule_shas.items():
        sha = v.get('sha', '')
        initialize_submodule(v['url'], k, sha, dry_run)

    if not dry_run:
        # Update the gitignore to ignore the template files
        gitignore_path = Path(root_path)/ '.gitignore'

        content = gitignore_path.read_text(encoding='utf-8').splitlines()
        content.insert(0, '\n')
        content.insert(0, '_CreateFromTemplate.bat')
        content.insert(0, '_TemplateSetup')
        gitignore_path.write_text('\n'.join(content) + '\n', encoding="utf-8")

        # Add all the files
        run_git_command(['add', '.'])

        # Create the main branch
        run_git_command(['branch', '-M', git_default_branch])

        # Commit them all
        run_git_command(['commit', '-m', 'Initial commit from template'])

        # Push main to origin
        run_git_command(['push', '-u', 'origin', git_default_branch])

@Gooey()
def main():
    parser = ArgumentParser(description='UE5 Template Creator. Scaffolds a general basic Unreal Engine project using similar styleguides to Epic Games.')
    parser.add_argument('ShortName', help='Short version of your games name. This is used to name modules and the project files. Example: HAS for HASGame, Cannon for CannonGame, Outpost for OutpostGame.')
    parser.add_argument('ClassPrefix', help='Class prefix. Usually 2 or 3 characters, but has not maximum length. Example: HAS for HideAndSeek, CG for CannonGame, OP for Outpost.')

    parser.add_argument('--GitUrl', required=False, help='The origin URL of your Git repository. This will create a branch called main on it if one does not exist already. If a URL is not passed, then it just destroys the local template repository')
    parser.add_argument('--ProjectName', required=False, help='If defined, this will be used as the title for your uproject and game name. If this isn\'t defined, the shortname will be used instead meaning if shortname is set to HAS the project name will be HASGame.')
    parser.add_argument('--CopyrightNotice', required=False, help='The copyright notice for your game')

    # optional arguments
    parser.add_argument('--UseShortName', required=False, action='store_true', help='Uses the short name for the name of modules if ProjectName is defined because sometimes this behaviour would be required. For example, you might name your game SCP, but would prefer SCPGame for your modules.')
    parser.add_argument('-d', '--dryrun', required=False, action='store_true', help='Does not do any actions, however will print in the console what it would do.')
    args = parser.parse_args()

    short_name = args.ShortName
    class_prefix = args.ClassPrefix

    git_url = args.GitUrl
    if args.ProjectName != None:
        project_name = args.ProjectName
    else:
        project_name = f'{short_name}Game'

    module_name = project_name
    if args.UseShortName:
        module_name = short_name

    copyright_notice = args.CopyrightNotice
    if copyright_notice is None:
        copyright_notice = ''

    dry_run = args.dryrun

    print('Creating project with the following options:')
    for arg in vars(args):
        print(f'\t{arg}: {getattr(args, arg)}')

    # Copy over the template readme, and override the existing one

    print('Copying template README')
    if not dry_run:
        shutil.copy(f'{root_path}/_TemplateSetup/TEMPLATE_README.md', f'{root_path}/README.md')

    file_list = build_file_list(root_path)

    print('Renaming files...')
    file_names_dict = {
        '%PROJECT_NAME%': project_name,
        '%CLASS_PREFIX%': class_prefix,
        '%MODULE_NAME%': module_name
    }
    replace_file_names(file_names_dict, file_list, dry_run=dry_run)

    # Rebuild the file path so we don't have any issues with files being renamed previously
    file_list = build_file_list(root_path)

    print('Editing file text...')
    file_text_dict = {
        '%PROJECT_NAME%': project_name,
        '%CLASS_PREFIX%': class_prefix,
        '%MODULE_NAME%': module_name,
        '%COPYRIGHT_NOTICE%': copyright_notice,
        '%PROJECT_SHORT_NAME%': project_name,
        '%MODULE_NAME_API%': module_name.upper()
    }
    replace_file_text(file_text_dict, file_list, dry_run)

    initialize_git_repo(git_url, dry_run)

if __name__ == '__main__':
    main()
