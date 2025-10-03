Push-Location "$PSScriptRoot\.."

Write-Host "Initialising submodules"
git submodule update --init --recursive

Write-Host "Installing .gitconfig"
git config include.path "../.gitconfig"

Pop-Location
