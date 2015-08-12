# Introduction #

This page describes best practices for using git.

Collaborative software projects face the challenge of managing the history of the software base, as well as managing the various copies of the software that each developer may be working on at any time, and coordinating those versions back into the main code base.  There are various Version Control Software systems which manage those challenges.  This year, we've chosen [git](http://git-scm.com/) as our version control system.

| Table of Contents:  |
|:--------------------|

This document is not intended to be a tutorial on using git.  Rather, the following sections list some best practices for using git.

# Local Repository #

Changes are recorded to the project's history when you **commit** the code to the repository.  Git is a distributed version control system, which means that you have a local repository, but the central code base is typically kept in a remote repository that's accessed by everyone.

  * When committing code, always enter a meaningful log message.  This message will serve as documentation of the changes that were applied in that commit.  Make a note of features added, bugs fixed, etc.

  * When committing code, you will have the opportunity to enter the identity (name/email) of the person committing the code.  Git also allows you to separately enter the author of those changes.  Make sure to enter these fields accurately.

How often should you commit your code?  As often as you like - the more frequent, the better.  But keep a few guidelines in mind:

  * As a general rule, don't commit code that won't compile/build.  If someone else checks out the code and it won't compile, they'd have to fix your errors before being able to test their own code.  There are exceptions to this rule.  For example, if you're only checking in to your local repository, _and_ you need to save the changes so that they're not lost later, or you need to establish a checkpoint for further code development, you may have justification for committing "broken" code.  If you need to commit code that doesn't compile cleanly, make sure you clearly state this in the commit message.

  * Ideally, you should always test your code before committing it.  This is an extension of the previous point about only committing "clean" code, and is again intended to avoid causing problems for other developers.  If you cannot test your code before committing, you should note this fact in the commit message.

# Remote Repository #

Git allows for remote repositories.  There are many ways to use this feature, but the simplest is to keep a central repository which contains the main code base, and which is the basis for all local repositories.  In our case, Google Code is the central repository.

When you **commit** your code, you're saving a snapshot of your code to your local repository.  In order for others to see your changes, you  **push** the changes from your local repository to the central repository.  Your changes will now be visible to everyone else.

To see other's commits, you **pull** those changes from the central repository to your local repository.  This will sync commits to your local repository, as well as apply those changes to your working directory.  Thus, your working directory will now contain all of the latest updates.

Before pushing any changes, git will check to see if anyone else has made changes since you last synced with the central repository.  If so, you will need to pull those changes to your local repository before you can push your changes.  In doing so, git will merge the other changes with your changes, so that when you push your changes, it will also contain changes that others have made.

How often should you push or pull?

  * You should pull as often as you like.  Typically you should commit before you pull, so that your changes will be committed separately from changes that you pull.

  * You should push your changes only when the code is "clean".  Remember that any changes you push will be pulled in by other developers, so you don't want to push code that won't compile; and you want to test your changes before pushing so that you don't introduce bugs that will interfere with other developers.

# Merging, and merge conflicts #

When multiple people work on the same code branch (eg, `master`), they're essentially working on separate local copies of the same branch.  When changes are committed and pushed, they will appear as separate paths in the code history - that is, the path will fork where multiple people pulled the same code to make changes, and join when those changes are merged back to the main line of code.

This merging happens when you pull code changes to your local repository.  Changes made remotely will get merged in with your changes.  Therefore, it's a good idea to commit before pulling.

Further, if there are remote changes since you've pulled, you will likely be required to pull - and thus merge - those changes before you'll be able to push.  This is how multiple people's changes are all merged together.

Usually the merge process happens automatically and smoothly.  However, sometimes the merge process can't happen automatically, as explained in the next section.

## Conflicts ##

Let's consider a couple simple examples.  Let's say there's a line of code in one file such as this:
```
const int x = 5;
```
Now you and I both pull the same version of this code.  Let's say you make this change:
```
const int x = 7;
```
but I don't modify that code.  When I pull, my code will be updated to reflect the change that you made; in other words, it will be automatically merged.

Now let's say that before I pull in your changes, I further make this modification:
```
const int x = 9;
```
Now what will happen when I try to pull in your changes?  This is a **merge conflict**.  Git cannot know which change to keep, and so it doesn't try.  Instead, _you_ are required to resolve the conflict and manually merge the code, before the merged changes can be committed.  More info may be found by researching the [Pro Git book](http://git-scm.com/book).

### Resolving conflicts: ###

Git, TortoiseGit and EGit provide some tools to assist with merging.

TortoiseGit provides a relatively easy way to manage and resolve conflicts.  Use **TortoiseGit > Check for modifications**.  Any files with conflicts should show up in red text.  Double-click the file you want to resolve, and TortoiseGit will bring up a window that lets you resolve the conflicts.  When you're done, make sure to save your changes, and mark them as resolved when the tool asks you.

When you're satisfied with your changes, it's always a good idea to review the modifications to your file(s), by viewing a visual difference of each file.  A handy way to do this is to use **TortoiseGit > Check for modifications**; then double-click on each file listed.

There are a couple steps you can take to minimize the pain of merging:

  * Commit your code before pulling remote changes.  This way, you'll have a snapshot with just your changes.  This can help avoid some confusion when manually merging changes.  <p>(Tip: always enter a summary of your changes when you commit.  Don't just say that you're committing before pulling/merging - you should indicate what you've changed, and why - not just that you're committing as part of branching/merging/pulling/etc.  This guideline applies even if you're committing because git told you to.)</li></ul>

<ul><li>Pull and push often.  This will keep your code more closely in sync with the remote repository, and may avoid some merge conflicts.  (Of course, you should still only push when you want your code exposed to others.)</li></ul>

<h1>Branches #

Loosely speaking, "branches" means different copies of the code which originated from a same point, but have their own unique changes.  This is the case whenever two people are making code changes from a common starting point.  Those changes will eventually be merged back into the main code stream, and thus could be considered to be "branches".

However, the term **branch** means something more specific in version control systems like git.  In this sense, a branch is a fork in the code which carries its own name.  In git, the default branch name is "master", and is the name of the branch that you'll normally use.

It's possible to create other named branches, for instance to support parallel development streams and still be able to commit code to the repository.  Ultimately such branches will usually still be merged back into the main code stream (master).

Using named branches is a fine way to manage multiple development paths.  **However**, care must be taken to manage those branches in a meaningful way, to avoid confusion.

# Tags #

Tags are ways of assigning a name, and other useful information, to a specific commit point.  Tags are typically used to identify code releases (eg, v1.0).

In our case, we "release" code to the robot.  In an ideal world, we would always tag code revisions that are loaded onto the robot; however, during development, we load a lot of code revisions, and tagging each one would be extraneous (distracting, a possible source of errors, etc).

Once the code becomes more stable, it's always a good idea to know which version of code is on the robot.  Ultimately, the only way to know for sure is for the robot code itself to report its version number.  However, tagging code versions in git is a good way to keep track as well.

> _Note that versions tagged in git are not necessarily the code version that's deployed on the robot - for example, someone may have changed the robot's code without tagging the corresponding version.  Thus, tags should be used as guidance as to which code version is deployed on the robot, but you should not make critical decisions based on this info._

When should you tag a code version?  A good rule of thumb is that you should tag the code version any time you _deploy_ code to the robot (ie, store the code in the robot's flash storage, which will be run whenever the cRIO boots); and that code version may be used at an unknown time in the future (ie, before the robot goes into storage), or when code is deployed that will be used in any competition match.  Thus, at a minimum, you should be able to see which code version was used in any given competition match.

What info should go in the tag?  You should always choose a meaningful tag name, which should follow an established naming convention, as well as a log message.  The log message should describe the reason for the tag, for instance.

A suggested tag naming convention for code versions used in competitions would be to use the name of the competition match when that code version is first used.  A commonly used format for FRC match names is:
```
<year><event>_<match_spec>
```
where `<year>` is the FRC season, `<event>` is the event code as used by FIRST (see [frclinks.com](http://frclinks.com) for a full list), and `<match_spec>` may be one of the following:
| **Type of match** | **spec** |
|:------------------|:---------|
| Qualification match | qm#      |
| Quarterfinal      | qf#m#    |
| Semifinal         | sf#m#    |
| Final             | fm#      |

For example, at the 2013 Sacramento Regional (Davis, CA), Qualification match 32 would be "2013casa\_qm32"; the second match of quarterfinal 3 would be "2013casa\_qf3m2"; etc.

(This is the same format as used on [The Blue Alliance](http://www.thebluealliance.com/team/1388), for example.)