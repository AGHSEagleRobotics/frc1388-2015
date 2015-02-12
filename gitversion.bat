@echo off

echo //This file simply contains the git hash of the code as set by gitversion.bat > src/GitVersion.h
<nul (set/p version=#define GIT_VERSION ) >> src/GitVersion.h
git log -1 --pretty="%%h" >> src/GitVersion.h
<nul (set/p status=#define STATUS ) >> src/GitVersion.h
git status --short >> src/GitVersion.h
pause
exit