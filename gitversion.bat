@echo off
set TMPFILE=src/GitVersion.h
git log -1 --pretty="%%h" > %TMPFILE%
set /p VERSION=<%TMPFILE%
git status -z > %TMPFILE%
set /p STATUS=<%TMPFILE%
git tag --contains > %TMPFILE%
set /p TAG=<%TMPFILE%
git log -1 --pretty="%%cd" > %TMPFILE%
set /p DATE=<%TMPFILE%
pause
echo //This file simply contains the git info of the code as set by gitversion.bat > src/GitVersion.h
echo #define GIT_VERSION ^"%VERSION%^" >> src/GitVersion.h
echo #define STATUS ^"%STATUS%^" >> src/GitVersion.h	
echo #define TAG ^"%TAG%^" >> src/GitVersion.h
echo #define DATE ^"%DATE%^" >> src/GitVersion.h
exit