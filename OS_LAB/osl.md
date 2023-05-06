# Table of Contents

1. [Experiment 1](#exp1)
2. [Experiment 2](#exp2)
3. [Experiment 3](#exp3)
4. [Experiment 4](#exp4)
5. [Experiment 5](#exp5)
6. [Experiment 6](#exp6)
7. [Experiment 7](#exp7)
8. [Experiment 8](#exp8)

<a name="exp1"></a>

# Experiment 1 : Introduction to Linux Commands

## Aim

To study about various shells of different operating systems and commands to perform different functions and operations.

## Theory

|Description|Commands|
|---|---|
Listing Files and Directories|`ls`
Long and Time Formatted Listing|`ls -alt`
Change home directory to 'path'|`cd path`
Change to home directory|`cd`
Show current working directory|`pwd`
Create a directory 'new'|`mkdir new`
Create a file 'file1.txt'|`touch file1.txt`
Command is used to update the timestamp of a file|`touch`
Command is used to delete files|`rm`
Command is used to concatenate files and print on the monitor|`cat`
Copy files from one directory to another|`cp`
Move files from one directory to another|`mv`

## Lab Exercises

### 1. Explore the file system of a Windows system and a Linux system, and write prime differences

> Ans.
> **File System in Linux**
> Linux supports more than 12 file systems with NFS technology. Ext file system is the most popular option. It is similar to the Berkeley file system. Linux supports the following file types:
>
> 1. **Directory**: This is simply a list of names.
> 2. **Ordinary File**: This is a file containing data or application program or executable.
> 3. **Symbolic Link**: This file is actually a link to(or path of) another file
> 4. **Special File**: This refers to a device driver
> 5. **Named Pipe**: This is a common channel between two or more processes for data exchange.
>
> **File System in Windows**
> Windows 2000 (W2K) supports a number of file systems including FAT. Developers designed a new file system NTFS that is intended to meet high-end requirements.
> **_Key Feature of NTFS_**
>
> 1. Recoverability
> Security
> Large disks and large files
> Multiple data streams
> General Indexing Facility
>
> **_NTFS Volume and File Structure_**
>
> 1. **Sector**: The smallest physical storage unit on the disk.
> 2. **Cluster**: One or more contiguous sectors.
> 3. **Volume**: A logical partition on a disk, consisting of one or more clusters and used by a file system to allocate space.

### 2. Create a file in your Linux system, in your current user's home directory, named as `file1.txt`. Write your name and registration number in the `file1.txt` using `cat` command. Now rename the file using mv command, the new name must be `yourRegistrationNumber.txt`

Ans.

```shell
ruzdan@Ubuntu:~$ touch file1.txt
ruzdan@Ubuntu:~$ ls
Desktop  Documents  Downloads  file1.txt  Music  Pictures  Public  snap  Templates  Videos
ruzdan@Ubuntu:~$ cat > file1.txt 
Ayan Ruzdan
12116032
ruzdan@Ubuntu:~$ ls
Desktop  Documents  Downloads  file1.txt  Music  Pictures  Public  snap  Templates  Videos
ruzdan@Ubuntu:~$ cat file1.txt 
Ayan Ruzdan
12116032
ruzdan@Ubuntu:~$ mv file1.txt 12116032.txt
ruzdan@Ubuntu:~$ ls
12116032.txt  Desktop  Documents  Downloads  Music  Pictures  Public  snap  Templates  Videos
ruzdan@Ubuntu:~$ cat 12116032.txt 
Ayan Ruzdan
12116032
```

### 3. Create a copy of the file you have created with your registration number. Now delete the original file

Ans.

```bash
ruzdan@Ubuntu:~$ ls
12116032.txt  Documents  Music     Public  Templates
Desktop       Downloads  Pictures  snap    Videos
ruzdan@Ubuntu:~$ cp 12116032.txt 12116032_copy.txt 
ruzdan@Ubuntu:~$ ls
12116032_copy.txt  Desktop    Downloads  Pictures  snap       Videos
12116032.txt       Documents  Music      Public    Templates
ruzdan@Ubuntu:~$ rm 12116032.txt
ruzdan@Ubuntu:~$ ls
12116032_copy.txt  Documents  Music     Public  Templates
Desktop            Downloads  Pictures  snap    Videos
ruzdan@Ubuntu:~$ cat 12116032_copy.txt 
Ayan Ruzdan
12116032
```

### 4. Create a directory with your name and move all the files (using mv command) created by you in currently logged in user's home directory

Ans.

```bash
ruzdan@Ubuntu:~$ mkdir Ayan
ruzdan@Ubuntu:~$ ls
12116032_copy.txt  Desktop    Downloads  Pictures  snap       Videos
Ayan               Documents  Music      Public    Templates
ruzdan@Ubuntu:~$ mv 12116032_copy.txt Ayan
ruzdan@Ubuntu:~$ ls
Ayan     Documents  Music     Public  Templates
Desktop  Downloads  Pictures  snap    Videos
ruzdan@Ubuntu:~$ cd Ayan/
ruzdan@Ubuntu:~/Ayan$ ls
12116032_copy.txt
```

### 5. Create multiple directories using single command. (Directories name can be your friends' names)

Ans.

```bash
ruzdan@Ubuntu:~$ mkdir Harsh Aayush Shubham
ruzdan@Ubuntu:~$ ls
Aayush  Desktop    Downloads  Music     Public   snap       Videos
Ayan    Documents  Harsh      Pictures  Shubham  Templates
```
<a name="exp2"></a>

# Experiment 2 : Shell Programming

## Aim

The aim of this laboratory is to introduce the shell script that offers the students with an interface to include a sequence of commands need to employ frequently for saving time.

## Description

A shell program, frequently called a shell script, is basically a program composed of shell commands. Each command within the script is executed by the shell in sequence. Shell script files are created with editors such as vi and stored with the `.sh` extension. Set execute permission for shell script file using **`chmod`** command and execute with the **`sh`** or **`bash`** command in the terminal.

## Shell Variables

User can include user-defined variables in a shell script program using the following format `var_name = string`, for example `day = "Sunday"`. In the given example, the variable `day` is assigned with the value `"Sunday"`.

## Standard Input Redirection

Mostly shell commands take input values from the standard input (keyboard). The input to these commands can also be redirected from the files using the symbol `<`. For example `$wc` command accepts the input from the standard input and displays the number of lines, words and characters.  
Example: `$wc < test.txt`  
Here the input to the `wc` command is redirected from the file "test.txt"

## Standard Output Redirection

The shell command outputs basically directed to standard output. These outputs can also be redirected to files using the symbol `<`.  
For example `ls` command displays the directory content on the standard output device.  
Example: `$ls > test.txt`  
Here the output of the ls command is redirected to the file with the name "test.txt"  

## Shell Arithmetic

The shell enables the arithmetic expressions to be evaluated using the commands `let` or `expr`.  
Example: Perform the sum of two numbers

```bash
x = 2
y = 3
let "a = $x + $y"
b = 'expr $x + $y'
echo "Sum is $a"
echo "Sum is $b"
```

## Flow Control

The shell supports various commands to control the flow of execution in a program. The basic constructs whic provide the flow control are:

* if, if-then, if-then-else, if-then-elif-then-else
* case

## `if, if-then, if-then-else, if-then-elif-then-else`

The `if` command is fairly simple on the surface, it makes a decision based on the exit status of a command. The `if` command's syntax looks like this:
```bash
if <condition>
then
    commands
elif <condition>
then
    commands
else
    commands
fi
```

## `case` construction

The case command evaluates the given test expression and performs the matching operation against each case value to continnue the execution of commands. The default condition `(*)` will be executed when no match is found. The basic syntax of the `case...esac` statement is:

```bash
case <test-value> in
value1)
<commands>
;;
value2)
<commands>
;;
value3)
<commands>
;;
*)
<commands>
;;
esac
```

**Example Program**
The following shell program demonstrates the selection of a number with case statement.

```bash
num="one"
case "$num" in
"one") echo "Number is 1"
;;
"two") echo "Number is 2"
;;
"three") echo "Number is 3"
;;
*) echo "No Number"
;;
esac
```

## Loops

Loops in shell scriptiing are used to execute a set of commands for a certain number of times. These loops will execute the commands repeatedly until a condition fulfils. The basic loops in shell scripting are:

* `while` loop
* `for` loop

**`while` loop**
The basic format for the while loop is:

```bash
while [expression]
do
    <command-list>
done
```

The commands in the while expression are executed to enter into the loop for executing the command-list.

**Example program**

The following example program prints the numbers from 0 to 9.

```bash
# mind the gap between the brackets
num=0
while [ $num -lt 10 ]
do
    echo $num
    num = $(expr "$num" + 1)
done
```

**`for` loop**
The **`for`** loop executes a set of commands for a specified number of times. The syntax of for loop in shell scriptin is presented as follows:

```bash
for var in list
do
    <command-list>
done
```

The for loop includes a number of items in the list and var is a looping variable. The for loop will execute the commandd-list for each item in the list.

**Example program**
The following example prints the numbers from 1 to 5
```bash
# mind the gap during string assignment
list="one two three four five"
# no need to initialize a counter first
for num in $list
do
    echo $num
    # no need to update the counter either
done
```

## Lab Exercises

### 1. Write a shell script to produce a multiplication table

**First Method**

```bash
echo "Enter Number:"
read num
for (( i = 1 ; i <= 10; i++ ))
do
echo "$num x $i = 'expr $num \* $i'"
done
```

**Second Method**

```bash
echo "Enter Number:"
read num
for i in 1 2 3 4 5 6 7 8 9 10
do
echo "$num x $i = 'expr $num \* $i'"
done
```

### 2. Write a shell script program to implement a small calculator

```bash
echo "Enter number1: "
read num1
echo "Enter number2: "
read num2
echo "Enter operator + - * /"
read op
case "$op" in
"+")
echo $(expr "$num1" + "$num2")
"-")
echo $(expr "$num1" - "$num2")
"*")
echo $(expr "$num1" \* "$num2")
"/")
echo $(expr "$num1" / "$num2")
*)
echo "Wrong Operator"
esac
```

### 3. Write a shell script to display prime numbers up to the given limit.

```bash
echo "Enter a limit: "
read limit
echo "Prime numbers upto $limit are: "
echo "1"
# we do not give spaces during variable assignment
i=2
while [ $i -le $limit ]
do
    flag=1
    j=2
    while [ $j -lt $i ]
    do
        rem=$(expr "$i" % "$j" )
        if [ $rem -eq 0 ]
            flag = 0
            break
        fi
        j=$(expr "$j" + 1 )
    done
    if [ $flag -eq 1 ]
    then
        echo "$i"
    fi
    i=$(expr "$i" + 1)
done
```
# Experiment 3 :

<a name="exp4"></a>

# Experiment 4 : Directory Manipulation using System Calls

## Aim

The objective of this laboratory is to introduce the working behind the command `mkdir` and `ls`. These commands use system calls like `mkdir`, `opendir`, `readdir`, to copy the contents of one file to another and read what users enters and write the same in the file.

## Theory

* `mkdir`: to create directories with append mode
* `opendir`: to open a directory stream returning pointer to directory stream
* `readdir`: to return a pointer to the next directory entry
* `rmdir`: to remove directory (only if empty)

## `mkdir` system call

```c
int mkdir("pathname/dirname", mode t mode);
int return = mkdir("directory name", 0666);
```

## `opendir` system call

```c
DIR *opendir("dir name");
```

## `readdir` system call

```c
struct dirent *readdir(DIR *dirname);
```


## `rmdir` system call;

```c
int rmdir("pathname/dirname");
```

## Dirent Structure

```c
struct dirent{
    Ino_t d_ino; // inode number
    off_t d_off; //offset to the next dirent
    unsigned short d_reclen; // length of this record
    unsigned char d_type; // type of file, not supported by all file system types
    char d_name[256]; // filename
};
```

## Program to use a directory system call and print the contents of the directory

```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    DIR *dp;
    struct dirent *dptr;
    int b = mkdir("alpha", 0777);
    dp = opendir("alpha");
    while (NULL != (dptr = readdir(dp)))
        ;
    {
        printf("%s\n", dptr->d_name);
        printf("%d\n", dptr->d_type);
    }
    return 0;
}
```

## Lab Exercises

### 1. Write a program using directory system calls to make a directory on desktop and create a file inside the directory and list the contents of the directory.

```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int n = mkdir("/home/ruzdan/beta");
    printf("%d", n);
    char file_path[256];
    FILE *fp = fopen("/home/ruzdan/beta/my_file.txt", "w");
    fprintf(fp, "Hello world");
    fclose(fp);
    DIR *dObj;
    dObj = opendir("/home/ruzdan/");
    struct dirent *dptr;
    if (dObj != NULL)
        while ((dptr = readdir(dObj)) != NULL)
        {
            printf("%s\t", dptr->d_name);
        }
    closedir(dObj);
    return 0;
}
```

### 2. Write a program using directory and file manipulation system calls to copy the contents of one directory in a newly created directory.

<a name="exp6"></a>

# Experiment 6 : Creation of Multithreaded Processes using Pthread Library

## Aim

To introduce the operations on thread, which include initialization, creation, join and exit functions of thread using pthread library.

## Theory

* `pthread_init()`: to initialize a thread
* `pthread_create()`: to create a thread
* `pthread_exit()`: to exit a thread function with return value
* `pthread_join()`: to join a thread in the main function and retrieve the value returned by thread function

## Syntax for `pthread_create()`

```c
int a = pthread_create(pthread t *thread, pthread attr t * attr, void *(*start routine), void(*));
```

## 1. Program to create a thread with `NULL` attributes

```C
#include <stdio.h>
#include <pthread.h>
char *a;
void *func()
{
    printf("Inside thread function\n");
    pthread_exit("Exit thread function\n");
}
int main()
{
    pthread_t thread1;
    void *a;
    printf("In main thread\n");
    pthread_create(&thread1, NULL, func, NULL);
    pthread_join(thread1, &a);
    printf("%s\n", a);
}
```

## 2. Program to pass message from main function to thread

```c
#include <stdio.h>
#include <pthread.h>
void *myfunc(void *myvar);
int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    char *msg1 = "first thread";
    char *msg2 = "second thread";
    int ret1, ret2;
    ret1 = pthread_create(&thread1, NULL, myfunc, (void *)msg1);
    ret2 = pthread_create(&thread2, NULL, myfunc, (void *)msg2);
    printf("Main function after pthread_create\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("first thread ret1 = %d\n", ret1);
    printf("first thread ret2 = %d\n", ret2);
    return 0;
}

void *myfunc(void *myvar)
{
    char *msg;
    msg = (char *)myvar;
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%s %d \n", msg, i);
        sleep(1);
    }
    printf("\n");
    return NULL;
}
```

## 3. Program to return a value from thread function to the main function

```C
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct arg_struct
{
    int arg1;
    int arg2;
    int arg3;
};
void *print(void *arg)
{
    struct arg_struct *ar = (struct arg_struct *)arg;
    scanf("%d", &ar->arg3);
    scanf("%d", &ar->arg2);
    int *c = malloc(sizeof(int));
    *c = ar->arg2 + ar->arg3;
    pthread_exit(c);
}
int main()
{
    pthread_t some_thread;
    struct arg_struct args;
    args.arg1 = 5;
    args.arg2 = 7;
    void *a;
    pthread_create(&some_thread, NULL, &print, &args);
    pthread_join(some_thread, &a);
    int *c = (int *)a;
    printf("%d\n", *c);
    free(c);
}
```

## Lab Exercise

### 1. Write a program using pthread to concatenate the strings, where multiple strings are passed to thread function.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *concatenate(void *arg)
{
    char **strings = (char **)arg;
    char *result = malloc(strlen(strings[0]) + strlen(strings[1]) + 1);
    strcpy(result, strings[0]);
    strcat(result, strings[1]);
    pthread_exit(result);
}
int main()
{
    pthread_t thread;
    char **strings = malloc(2 * sizeof(char *));
    char *result;
    strings[0] = malloc(100 * sizeof(char));
    strings[1] = malloc(100 * sizeof(char));
    scanf("%s", strings[0]);
    scanf("%s", strings[1]);
    pthread_create(&thread, NULL, concatenate, (void *)strings);
    pthread_join(thread, (void **)&result);
    printf("%s", result);
    return 0;
}
```

### 2. Write a program using pthread to find the length of string, where strings are passed to thread function.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *length(void *arg)
{
    char *strings = (char *)arg;
    int len = strlen(strings);
    pthread_exit((void *)(long long)len);
}
int main()
{
    pthread_t thread;
    char *strings = malloc(100 * sizeof(char));
    int size;
    scanf("%s", strings);
    pthread_create(&thread, NULL, length, (void *)strings);
    pthread_join(thread, (void **)&size);
    printf("%d", size);
    free(strings);
    return 0;
}
```

### 3. Write a program that performs statistical operations of calculating the average, maximum and minimum for a set of numbers. Create three threads where each performs their respective operations.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int values[10] = {7, 8, 3, 9, 1, 3, 2, 0, 7, 7};

void *min(void *arg)
{
    int min = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        if (values[i] < min)
            min = values[i];
    }
    int result = min;
    printf("MIN: %d\n", result);
    pthread_exit(NULL);
}
void *max(void *arg)
{
    int max = INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        if (values[i] > max)
            max = values[i];
    }
    int result = max;
    printf("MAX: %d\n", result);
    pthread_exit(NULL);
}
void *avg(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += values[i];
    }
    int result = sum / 10;
    printf("AVG: %d\n", result);
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_create(&thread1, NULL, min, NULL);
    pthread_create(&thread2, NULL, max, NULL);
    pthread_create(&thread3, NULL, avg, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}
```

### 4. Write a multithreaded program where an array of integers is passed globally and is divided into two smaller lists and given a input to two threads. The threads will sort their half of the list and will pass the sorted list to a third thread which merges and sorts the list. The final sorted list is printed by the parent thread.

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int values[10] = {7, 8, 3, 9, 1, 3, 2, 0, 7, 7};

struct thread_args
{
    int *start;
    int *end;
};

void *sort(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *start = args->start;
    int *end = args->end;
    for (int *i = start; i < end; i++)
    {
        for (int *j = i + 1; j < end; j++)
        {
            if (*i > *j)
            {
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    pthread_exit(NULL);
}
void *merge_sort(void *arg)
{
    int *start1 = values;
    int *end1 = values + 5;
    int *start2 = end1;
    int *end2 = values + 10;
    int *result = (int *)malloc(sizeof(int) * 10);
    int *p = result;
    while (start1 < end1 && start2 < end2)
    {
        if (*start1 < *start2)
        {
            *p++ = *start1++;
        }
        else
        {
            *p++ = *start2++;
        }
    }
    while (start1 < end1)
    {
        *p++ = *start1++;
    }
    while (start2 < end2)
    {
        *p++ = *start2++;
    }
    for (int i = 0; i < 10; i++)
    {
        values[i] = result[i];
    }
    free(result);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    struct thread_args args1 = {values, values + 5};
    struct thread_args args2 = {values + 5, values + 10};
    pthread_create(&thread1, NULL, sort, &args1);
    pthread_create(&thread2, NULL, sort, &args2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_create(&thread3, NULL, merge_sort, NULL);
    pthread_join(thread3, NULL);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", values[i]);
    }
    return 0;
}
```

## Viva questions

### 1. Provide two examples in which multithreaded process provide an advantage over single threaded solutions.

1. Parallel computation: When a task can be divided into multiple independent sub-tasks that can be executed in parallel, multithreading can be used to take advantage of the available hardware resources (e.g., multiple cores) and speed up the computation. For example, in image or video processing, individual frames or regions can be processed independently by different threads, which can lead to a significant reduction in processing time.

2. I/O-bound tasks: In tasks where the primary bottleneck is input/output (I/O) operations, such as reading/writing to disk or network communication, multithreading can be used to overlap I/O operations with computation. While one thread is waiting for I/O operations to complete, another thread can be executing computation, which can lead to more efficient use of system resources and better performance. For example, a web server that handles multiple requests concurrently can use multithreading to improve its throughput and responsiveness.

### 2. What resources are used when a thread is created.

1. Stack: Each thread has its own stack, which is used to store local variables and function call frames. The stack is allocated when the thread is created and is typically a fixed size.

2. Program counter: Each thread has its own program counter, which keeps track of the next instruction to be executed.

3. Registers: Each thread has its own set of CPU registers, which are used to store intermediate results and function arguments.

4. Thread-specific data: Each thread can have its own thread-specific data, which is accessible only by that thread. This data can be used to store thread-specific configuration settings or other thread-specific information.

5. Operating system resources: The operating system assigns a unique thread identifier to each thread and allocates other resources, such as memory and I/O resources, as needed.

### 3. What is the syntax for creating a thread.

```C
#include <pthread.h>
pthread_t thread_id;
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
```

1. `thread`: A pointer to a variable of type pthread_t, which will be used to store the thread identifier of the newly created thread.

2. `attr`: A pointer to a structure of type pthread_attr_t, which is used to specify various attributes of the thread, such as its stack size or scheduling policy. If you want to use the default attributes, you can pass NULL for this argument.

3. `start_routine`: A pointer to the function that will be executed in the new thread. This function should have a return type of `void*` and take a single argument of type void*, which can be used to pass arguments to the thread function.

4. `arg`: A pointer to the argument that will be passed to the thread function. This argument can be of any data type and is passed as a void*.

### 4. What is the use of `pthread_join()`

The `pthread_join()` function waits for a thread to terminate, detaches the thread, then returns the threads exit status. If the status parameter is NULL, the threads exit status is not returned.

### 5. What is the use of `pthread_exit()`

The `pthread_exit()` function is used to terminate a thread and return a value to the thread that joins with it. When a thread has finished executing its task, it can call `pthread_exit()` to terminate its execution and return a value to the thread that joined with it using the `pthread_join()` function.

### 6. Which pthread function passes the value from the thread function to the main function

The pthread function that passes the value from the thread function to the main function is `pthread_join()`.