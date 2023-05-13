# Simple Shell Project
Creating a simple Unix command line interprete.

![picture alt](https://github.com/BoubkerElmaayouf/shell_test/blob/master/The%20_Gates_Of_Shell.jpeg?raw=true "SIMPLE_SHELL")

ALX SE COHORT 13 //2023

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
Testing: interactive mode

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
also in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```
## Collaboration
this is a team project made by BoubkerElmaayouf and Achraf Boutzate

## Date 
start at: 2023/05/10 deadline: 2023/05/24
