# Unreal Engine 5 C++ Template
An Unreal Engine 5 C++ template with various additions from pre-setup editor module, doxygen support, and GitLab workflows.

## Using the template
There are 2 ways to invoke the template creator.
We use gooey to transform the CLI application into a usable GUI application.

### GUI
1. Run `_CreateFromTemplate.bat` or run `py _TemplateSetup/create.py`
2. Fill out the required info and optional info
3. Click start

### Command Line
To run with the commandline you must manually call `py _TemplateSetup/create.py` with `--ignore_gooey` at the end <br>
You can view the help text by running `create.py -h --ignore_gooey`

Example: <br>
`py .\_TemplateSetup\create.py "Cannon" "CG" --ProjectName "Cannon" --UseShortName --ignore-gooey`

Positional Arguments:
```
ShortName       - Short version of your games name. This is used to name modules and the project files. Example: HAS for HASGame, Cannon for CannonGame, Outpost for OutpostGame.
Class Prefix    - Class prefix. Usually 2 or 3 characters, but has not maximum length. Example: HAS for HideAndSeek, Cannon for CannonGame, OP for Outpost.
```

Optional Arguments
```
--ignore-gooey      - Does not create the GUI and only consumes the CLI arguments
--GitUrl            - The origin URL of your Git repository. This will create a branch called main on it if one does not exist already.
--ProjectName       - If defined, this will be used as the title for your uproject and game name. If this isn't defined, the shortname will be used instead meaning if shortname is set to HAS the project name will be HASGame
--CopyrightNotice   - The copyright notice for your game.
--UseShortName      - Uses the short name for the name of modules if ProjectName is defined because sometimes this behaviour would be required. For example, you might name your game SCP, but would prefer SCPGame for your modules.
--dryrun            - Does not do any actions, however will print in the console what it would do.
```

## Authoring new files
The template system will automatically rename files and values based on certain key words in the text or names.

File name keywords:
```
%PROJECT_NAME%  - Project Name. If --ProjectName isn't defined, the short name will be combined with Game. Example: SCP or SCPGame
%CLASS_PREFIX%  - The prefix for class names. Example: SCP
%MODULE_NAME%   - This value is fileld in by ShortName. Example: SCP
```

File text keywords
```
%PROJECT_NAME%          - Project Name. If --ProjectName isn't defined, the short name will be combined with Game. Example: SCP or SCPGame
%CLASS_PREFIX%          - The prefix for class names. Example: SCP
%MODULE_NAME%           - This value is fileld in by ShortName. Example: SCP
%COPYRIGHT_NOTICE%      - The copyright notice for this project
%PROJECT_SHORT_NAME%    - Currently just a redirector to %PROJECT_NAME% **Might be removed in future**
%MODULE_NAME_API%       - Upper case version of %MODULE_NAME% for DllExport/Import
```
