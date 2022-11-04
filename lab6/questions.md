# Lab 6 (deadline: 26-Oct 2021 23:59 hrs)

## Instructions

  1. The instructions on how to submit each answer is indicated below the
     question (in the line starting with "Ans."). Please follow those
     instructions carefully.

  2. Use code-blocks when you are pasting outputs seen on the terminal.


## Questions

1. **[1 mark]** With an example, explain the output of the `diff` command.

**Ans.** 

 `diff` is used to display the difference between 2 files . It compares 2 files line by line and display the difference between them . 

e.g. I have taken 3 files `foo1.txt` , `foo2.txt` , `bar.txt` . `foo1.txt` , `foo2.txt` are same files with different names . `bar.txt` have different content. 
`diff foo1.txt foo2.txt` displays no output as no difference is found . 
`diff foo1.txt bar.txt` displays the difference as the output .
`<` and `>` denotes the lines in file1 and file2 which are different.
   	 
**output:**
```
1c1
< FOO
---
> BAR
```
2. **[1 mark]** Using an example, show how one can measure the time taken to   execute a command.

**Ans.**. 
          	 
`time` command is used to determine the time taken for an command execution . 
`time diff foo1.txt bar.txt1` gives the insights on how much time is taken to execute 
`diff foo1.txt bar.txt` command .
`real` denotes the time from start to end of process
`user` denotes the time spent in CPU execution under user mode . 
`sys` denotes the time spent in CPU execution under kernel mode or time spent for system calls.

**output :**
```
1c1
< FOO
---
> BAR

real	0m0.036s
user	0m0.005s
sys	0m0.000s

```
3. **[1 mark]** What is the difference between a hard-link and a soft-link in
   Linux Filesystem. With an example, show the commands you will use to create
   such links.

**Ans.**.

A hard-link is a copy of an original file . If the original file is deleted , then also we can access the data of the original file .`ln` command is used to create hard link.

 e.g. `ln a.txt a1.txt` command will create a new file `a1.txt` which is a hard link to `a.txt` file  . 

 A soft-link is a reference to the original file . If the original file is deleted ,	  the soft link become invalid as it is pointing to a non existing file . `ln -s` command is used to create soft-link .
 
e.g. `ln -s a2.txt a.txt` command will create a new file `a2.txt` which is a soft link to `a.txt` file  . 

If `a.txt` is deleted , still we can acess the content of `a.txt` by using the hard link `a1.txt `.	But cannot so the same by using the soft link `a2.txt` .
	
	
4. **[1 mark]** How will you create named pipes in UNIX. Show an example usage of such named pipes.

 **Ans.**. 
  
Named pipes in unix can be created by using `mkfifo pipename` command.     In unnamed pipes us use the output of first command as the input of next command , but can not use the output of 2nd command as the input of first command . By using named pipes , we can store the output of 2nd command and use it as the input to first command .using named pipes , we can save the output of one command from one terminal and retrive the same from another terminal . as the outputs are written on pipe file .
 
 `for i in ``seq 10`` ; do echo $i; sleep 1 ; done; > pipe1` is executed from one terminal and `cat pipe1` is executed from another terminal . but the output of 1 to 10 is printed on the terminal from where `cat pipe1` is called . 
    
**output :**
```
1
2
3
4
5
6
7
8
9
10
```

`echo "hello world"` is executed from one terminal and `cat pipe1` is executed from another terminal . but the output of 1 to 10 is printed on the terminal from where `cat pipe1` is called . 
    
**output :**
```
hello world
```

**5.** Analysis of the `syslog` file.

a. **[2 marks]** Count the number of error messages in the `syslog` file.

**Ans.**      	    

 `cat /var/log/syslog | grep -i "error" | wc -l` command is used for counting no of error messages present in ` syslog ` file 
      	    
 **output**: `199`
 
 In my syslog file , there are 199 error messages present .

  b. **[2 marks]** Count the number of lines in the log file.	    

**Ans.**.
    
`cat /var/log/syslog | wc -l` is used to count the number of lines present in `syslog` file 
      	    
**output :** `2757`
      	    
   In my syslog file , there are `2757` lines present .

  c. **[2 marks]** Count the number of unique words in the log file.	    

 **Ans.**. 
    
`cat /var/log/syslog |sort -u | wc -w` command is used to count unique words present in `syslog` file.
  
** output :** 
`33954` 
      	    

  d. **[2 marks]** Find the latest error message

  **Ans.**.
    
`cat /var/log/syslog | grep -i "error" | tail -1` command is used to find the latest error message in `syslog` file .
      	    
**output :** 
```
Oct 28 10:53:03 nilanjana-VirtualBox gnome-shell[2528]: ###!!! [Parent][RunMessage] Error: Channel closing: too late to send/recv, messages will be lost
```

 e. **[2 marks]** Find the oldest error message

  **Ans.**. 
  
 `cat /var/log/syslog | grep -i "error" | head -1` command is used to find the oldest error message in `syslog` file .
      	    
 **output :**
```
Oct 28 07:33:51 nilanjana-VirtualBox gnome-shell[2971]: ###!!! [Parent][RunMessage] Error: Channel closing: too late to send/recv, messages will be lost
```
	    
f. **[2 marks]** Find the average time between the errors

**Ans.**.

 I used the following command to calculate the average time between the errors
```
cat /var/log/syslog | grep -i "error" | awk '{print $1" "$2" "$3;}' >b.txt |time1=$(date -d "$(head -1 <b.txt)" +%s);sum=0;i=1;total=$(wc -l b.txt| awk '{print $1;}');tail -n+2 b.txt| while read date ;do time2=$(date -d "$date" +%s); d1=`expr $time2 - $time1` ;sum=$(expr $sum + $d1 ); time1=$time2;i=`expr $i + 1`; if [ $i == $total ];then echo "Averge Time : "$(( $sum / $total ))"sec" ;fi done
```
**Output :**

`Averge Time : 136 sec`


**6.** `echoes` using pipes. You should do all the following questions inside the folder `lab2/echoes`

a. **[2 marks]** Write a C program (`iecho.c`) that reads an input ( using     `scanf()` ) and stores it to a variable named `num`, increments `num` by   one, and prints the incremented value (using `printf()`). Compile this     program to create an executable named `iecho`.

 **Ans.**. 
  Please find the `iecho.c`  file in `iecho` folder 
  
 **Code in iecho.c :** 
      	   
```
#include <stdio.h>

int main() {

  // TODO: Complete the code (as per question 6)
  
  int num;
  
  scanf("%d" , &num);
  num++;
  printf("%d\n" , num);
	
  return 0;
}
```

 b. **[2 marks]** Compile `driver.c` into an executable named `driver`. Pipe  the output of `driver` as the input of `iecho`.

**Ans.**. 

   `./driver | while read a ; do echo $a | ./iecho ; done` command is used to  increment all the integer values (i.e. 0,1,2,3,4) printed by `./driver` .  All the values from `stdout` is taken as input to `./iecho` to increment their value. This output is printed by `./iecho`.
   
**output :** 
```
1
2
3
4
5
```
      
   c. **[8 marks]** Uncomment the lines 9 and 10 of `driver.c`, and recompile
      the code (executable name can continue to be `driver`). Write a command or  shell script such that `driver` gets (or reads) the incremented value (which is nothing but the output of `iecho`). NOTE: This requires a      two-way communication where `driver` sends a number to `iecho`, `iecho`      increments it and sends the incremented value back to `driver`. The    `driver` then prints both the original value sent and the incremented      value it received on `stderr`. You may change `iecho.c` that you  implemented for the first sub-part if you wish to, but ensure that the earlier  implementation of `iecho.c` was committed (and pushed) to the repo  at least once before editing.

   **Ans.**. 
	   
`./driver <pipe2 | while read a ; do echo $a | ./iecho ; done > pipe2`  command is used to increment all the integer values (i.e. 0,1,2,3,4) printed  by `./driver` and `./driver` will scan for the incremented value and then  print them in `stderr`. All the values from `stdout` is taken as input to  `./iecho` to increment their value and the output of `./iecho` is given as   input to `./driver` . This output is printed by `./driver` in `stderr`.
 
 **output:** 
```
Even: sent: 0, got 1
Even: sent: 1, got 2
Even: sent: 2, got 3
Even: sent: 3, got 4
Even: sent: 4, got 5
```

7. **[12 marks]** The folder `lab2/dedup/inputs` has some files that contain
   information about the marks secured by some students in a few subjects. Since
   a lot of such files may be generated in future, you wish to save disk space.
   Write a shell script `dedup.sh` that takes a directory name as an input
   argument, finds all regular files immediately under this directory that are
   duplicates, and replaces the duplicates with soft-links. NOTE: a. The
   filename of the duplicates should remain same (before and after replacing
   them with soft links). b. Your script should not search for duplicates
   recursively. b. The original files that is the one that is lexicographically
   first. c. If there are more than one duplicate, the duplicates should
   continue to link to the original (lexicographically first) file only. d. If
   the script is not given any input argument, it is assume the current working
   directory as its input. e. The filenames can contain special characters such
   as "*", spaces, "~", and leading "-". f. Your script should ignore all
   non-regular files such as links, pipes, directories

    **Ans.**. (Complete this exercise in `dedup.sh` present under `lab2/dedup`)
