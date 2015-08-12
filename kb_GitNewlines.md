# Introduction #

Windows handles line endings in files differently than Linux or MacOS.  This can cause confusion and problems merging file changes.  This problem can be avoided by carefully setting up git on all machines.

The following is from http://git-scm.com/book/en/v2/Customizing-Git-Git-Configuration.

Note that instructions are given for using the git command line.  You may also be able to specify these settings during installation (for example, Git for Windows) or through a GUI interface (for example, TortoiseGit).

  * **Note:** These change may or may not apply to eGit.  It's possible that settings above apply to eGit - or that eGit uses its own settings.  _This needs to be verified - and this comment needs to be updated._

# Details #

## Formatting and Whitespace ##

Formatting and whitespace issues are some of the more frustrating and subtle problems that many developers encounter when collaborating, especially cross-platform. It’s very easy for patches or other collaborated work to introduce subtle whitespace changes because editors silently introduce them, and if your files ever touch a Windows system, their line endings might be replaced. Git has a few configuration options to help with these issues.

## core.autocrlf ##

If you’re programming on Windows and working with people who are not (or vice-versa), you’ll probably run into line-ending issues at some point. This is because Windows uses both a carriage-return character and a linefeed character for newlines in its files, whereas Mac and Linux systems use only the linefeed character. This is a subtle but incredibly annoying fact of cross-platform work; many editors on Windows silently replace existing LF-style line endings with CRLF, or insert both line-ending characters when the user hits the enter key.

Git can handle this by auto-converting CRLF line endings into LF when you add a file to the index, and vice versa when it checks out code onto your filesystem. You can turn on this functionality with the core.autocrlf setting. If you’re on a Windows machine, set it to true – this converts LF endings into CRLF when you check out code:

```
$ git config --global core.autocrlf true
```

If you’re on a Linux or Mac system that uses LF line endings, then you don’t want Git to automatically convert them when you check out files; however, if a file with CRLF endings accidentally gets introduced, then you may want Git to fix it. You can tell Git to convert CRLF to LF on commit but not the other way around by setting core.autocrlf to input:

```
$ git config --global core.autocrlf input
```

This setup should leave you with CRLF endings in Windows checkouts, but LF endings on Mac and Linux systems and in the repository.

If you’re a Windows programmer doing a Windows-only project, then you can turn off this functionality, recording the carriage returns in the repository by setting the config value to false:

```
$ git config --global core.autocrlf false
```