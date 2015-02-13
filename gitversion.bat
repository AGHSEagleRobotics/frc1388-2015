@echo off
git log -1 --pretty="%%h" > git.tmp
set /p VERSION=<git.tmp
git status -z > git.tmp
set /p STATUS=<git.tmp
git tag --contains > git.tmp
set /p TAG=<git.tmp
del git.tmp
echo //This file simply contains the git info of the code as set by gitversion.bat > src/GitVersion.h
echo #define GIT_VERSION ^"%VERSION%^" >> src/GitVersion.h
echo #define STATUS ^"%STATUS%^" >> src/GitVersion.h	
echo #define TAG ^"%TAG%^" >> src/GitVersion.h
exit