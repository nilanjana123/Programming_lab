# Assignment 1 (deadline: 26-Aug 2021)

## Instructions

  1. This `questions.md` files is a Markdown files.
     Markdown is a simple markup
     language that you can use to quickly format text documents.
     The basic syntax of Markdown to achieve headings, subheadings,
     bullets, numbered lists, paragraphs, and so on can be found in
     this link: https://www.markdownguide.org/basic-syntax/

  2. Type your answers (using Markdown syntax where applicable)
     against the line starting with "Ans.". Replace existing text
     when you type your answers.

  3. When you have answered all the questions given in this file,
     commit your changes, and push it back to your bitbucket repo.
     

## Questions

**1. What is your Roll number?**

**Ans. 112113001**

**2. What is your name?**

**Ans. ** Nilanjana Debnath

**3. Paste the last 20 lines of your `syslog` file.**

**Ans. **
```
Aug 26 00:19:37 nilanjana-VirtualBox gnome-shell[1584]: Window manager warning: Overwriting existing binding of keysym 37 with keysym 37 (keycode 10).
Aug 26 00:19:58 nilanjana-VirtualBox systemd[1]: fprintd.service: Succeeded.
Aug 26 00:22:30 nilanjana-VirtualBox gnome-shell[1584]: Window manager warning: WM_TRANSIENT_FOR window 0x3a65f46 for 0x3a6a011 window override-redirect is an override-redirect window and this is not correct according to the standard, so we'll fallback to the first non-override-redirect window 0x3a0009d.
Aug 26 00:22:41 nilanjana-VirtualBox dbus-daemon[547]: [system] Activating via systemd: service name='org.freedesktop.hostname1' unit='dbus-org.freedesktop.hostname1.service' requested by ':1.192' (uid=1000 pid=5997 comm="/usr/lib/libreoffice/program/soffice.bin --writer " label="libreoffice-soffice (complain)")
Aug 26 00:22:41 nilanjana-VirtualBox systemd[1]: Starting Hostname Service...
Aug 26 00:22:42 nilanjana-VirtualBox dbus-daemon[547]: [system] Successfully activated service 'org.freedesktop.hostname1'
Aug 26 00:22:42 nilanjana-VirtualBox systemd[1]: Started Hostname Service.
Aug 26 00:22:56 nilanjana-VirtualBox evince[7681]: ev_page_cache_get_annot_mapping: assertion 'page >= 0 && page < cache->n_pages' failed
Aug 26 00:22:56 nilanjana-VirtualBox dbus-daemon[1302]: [session uid=1000 pid=1302] Activating via systemd: service name='org.freedesktop.Tracker1' unit='tracker-store.service' requested by ':1.2' (uid=1000 pid=1299 comm="/usr/libexec/tracker-miner-fs " label="unconfined")
Aug 26 00:22:56 nilanjana-VirtualBox systemd[1291]: Starting Tracker metadata database store and lookup manager...
Aug 26 00:22:56 nilanjana-VirtualBox dbus-daemon[1302]: [session uid=1000 pid=1302] Successfully activated service 'org.freedesktop.Tracker1'
Aug 26 00:22:56 nilanjana-VirtualBox systemd[1291]: Started Tracker metadata database store and lookup manager.
Aug 26 00:22:57 nilanjana-VirtualBox dbus-daemon[1302]: [session uid=1000 pid=1302] Activating via systemd: service name='org.freedesktop.Tracker1.Miner.Extract' unit='tracker-extract.service' requested by ':1.2' (uid=1000 pid=1299 comm="/usr/libexec/tracker-miner-fs " label="unconfined")
Aug 26 00:22:57 nilanjana-VirtualBox systemd[1291]: Starting Tracker metadata extractor...
Aug 26 00:22:57 nilanjana-VirtualBox tracker-extract[7859]: Set scheduler policy to SCHED_IDLE
Aug 26 00:22:57 nilanjana-VirtualBox tracker-extract[7859]: Setting priority nice level to 19
Aug 26 00:22:58 nilanjana-VirtualBox dbus-daemon[1302]: [session uid=1000 pid=1302] Successfully activated service 'org.freedesktop.Tracker1.Miner.Extract'
Aug 26 00:22:58 nilanjana-VirtualBox systemd[1291]: Started Tracker metadata extractor.
Aug 26 00:23:08 nilanjana-VirtualBox systemd[1291]: tracker-extract.service: Succeeded.
Aug 26 00:23:12 nilanjana-VirtualBox systemd[1]: systemd-hostnamed.service: Succeeded.
```

**4. Where is your "HOME" directory located in the system?**

**Ans.** `/home/nilanjana` is the absolute path of my home directory located in my system.

**5. Paste the output of the command `ls -1a ~`.
   (The option passed is (one)-a and not `-la`)**

**Ans. **
```
.
..
112113001
.bash_history
.bash_logout
.bashrc
.cache
.config
Desktop
Documents
Downloads
.gitconfig
.gnupg
.local
.mozilla
Music
Pictures
.profile
Public
.ssh
.sudo_as_admin_successful
Templates
.vboxclient-clipboard.pid
.vboxclient-display-svga-x11.pid
.vboxclient-draganddrop.pid
.vboxclient-seamless.pid
Videos
```

**6. Write a 500 word summary (in your own words) of the Linux Filesystem.**

**Ans. **
#### Linux file System:

The file system of any operating system is reponsible for organising the files in a sturctured manner.
In linux, files are stored in a upside down hierarchical tree fashion. Each directories in linux can contain files and/or other directories, and the top most directory is `root` directory , presented by `/`.
`home` , `bin` ,  `usr` , `var`  , `sys` ,  `etc` , `dev` are some of the predecessor directories of root directory.

##### Some of the basic features of linux file system are as following:
 
1. Unlike windows, Linux never uses ‘\’ (back slash) as its path separator. It always uses ‘/’ forward slash.
2. Paths in Linux operating system is of two types , namely
	i.  Absolute path .(full path starting from root directory)
	ii. Relative Path. (remaining path to the specific file / folder from current directory. )
3. In linux , it is not mandatory to have always a file extension. Linux can automatically detect filetype for most of the cases . A file may or maynot have extension.
4. In linux, Hidden files name starts with ‘.’ .
5. Linux file system is case sensetive . In linux, file1.txt and filE1.txt are different.
6. In linux , there are 3 basic kind of files available:
	i.	Ordinary file .(e.g. .txt , .pdf, .exe files)
	ii.	Directory 
	Iii.	Special files (e.g block special files, character special files) .
7.  There are various kinds of linux file systems , such as Ext (Extended file system) , Ext2, Ext3, Ext4, swap, btrfs ( B tree file system ),  XFS, JFS (journaled file system ) , ReiserFS.

##### Various common commands in Linux file system :

1. pwd: pwd command is used to find out ‘present working directory’ 
2. cd: cd command is used to change ‘current directory’ . 
	- cd ~ : go to root directory.
	- cd .. : got to parent directory
	- cd <path> : go to specified location	
3. ls: Lists all files and folders present in the directory. We can use ls -a to show all files . Including hidden files.
4. mkdir: used for directory creation. (e.g. mkdir new_dir creates a new folder named ‘new_dir’.)
5. rmdir: used for directory deletion. (e.g. rmdir some_dir deletes a some folder named ‘new_dir’)
6. chmod: chmod is used to change permission mode of any files/folder. (e.g. chmod 470 file1.txt)
	- chmod u+x file1.txt : adds execution permission to user.
7. mv: used for moving file from one location to another .( e.g. mv file1 folder1/file2)
8. cp: used for copying file . ( e.g. cp file1 folder1/file2)
9. rm: used for removing file. ( e.g. rm file1 )
10. cat: - cat file1 : prints file contents.
	 - cat file1 file 2 : prints multiple files one after another .
	 - cat  -n file1 : prints files with line number.
	 - cat  > newfile: creates new file .
	 - cat source_file1 > destination_file 2 : copies file  .
	 - cat file1 >> file 2 : append contents of one file to another .
11. tac :		tac file1 : prints file1 in reverse order.






**7. Create a report that includes the screenshots of how you
   setup git and keyless SSH on your machine, and the commands
   you used to clone, pull, commit and push the submission to
   your repository.**
   
**Ans.** Please find 112113001.pdf in lab1 folder.


