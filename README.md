# push_swap
Because Swap_push isn’t as natural.

## What is Push_swap?

Program name | push_swap
:----------- | :--------
Turn in files | Makefile, *.h, *.c
Makefile | NAME, all, clean, fclean, re
Arguments | stack a: A list of integers
External funcs | • read, write, malloc, free, exit<br>• ft_printf and any equivalent YOU coded
Libft authorized |  Yes

### You have 2 stacks named a and b.
_At the beginning:_
* The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
* The stack b is empty.

_The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:_

operation | description
:-------- | :----------
sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss | sa and sb at the same time.
pa (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra (rotate a) | Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b) | Shift up all elements of stack b by 1. The first element becomes the last one.
rr | ra and rb at the same time.
rra (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one.
rrr | rra and rrb at the same time.

### Example

* To illustrate the effect of some of these instructions, let’s sort a random list of integers. In this example, we’ll consider that both stacks grow from the right.
	```sh
	Init a and b:
	2
	1
	3
	7
	5
	42
	_  _
	a  b
	-------------------------------------------------------------------------------
	Exec sa:
	1
	2
	3
	7
	5
	42
	_  _
	a  b
	------------------------------------------------------------------------------------------------
	Exec pb pb pb:
	7  3
	5  2
	42 1
	_  _
	a  b
	------------------------------------------------------------------------------------------------
	Exec ra rb (equiv. to rr):
	5  2
	42 1
	7  3
	_  _
	a  b
	------------------------------------------------------------------------------------------------
	Exec rra rrb (equiv. to rrr):
	7  3
	5  2
	42 1
	_  _
	a  b
	------------------------------------------------------------------------------------------------
	Exec sa:
	5  3
	7  2
	42 1
	_  _
	a  b
	------------------------------------------------------------------------------------------------
	Exec pa pa pa:
	1
	2
	3
	5
	7
	42
	_  _
	a  b
	```

## Requirement

Your project must comply with the following rules:

* You have to turn in a Makefile which will compile your source files. It must not relink.
* Global variables are forbidden.
* You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
* The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
* Instructions must be separated by a ’\n’ and nothing else.
* The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
> **Warning**
><br>If no parameters are specified, the program must not display anything and give the prompt back.

* In case of error, it must display ``Error`` followed by a ’\n’ on the standard error. Errors include for example: 
	* some arguments aren’t integers
	* some arguments are bigger than an integer and/or there are duplicates.

_Your program will be executed as follows:_
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

__Also, we have checker programs(for Linux and Mac).__

_It will work as follows:_

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
```sh
#output
6
```
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
```sh
#output
OK
```

> **Note**
><br>If the program checker_OS displays ``KO``, it means that your push_swap came up with a list of instructions that doesn’t sort the numbers.

## Bonus requirement

__The "checker" program__

Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.

Program name | checker
:----------- | :------
Turn in files |  *.h, *.c
Makefile | bonus
Arguments | stack a: A list of integers
External funcs | • read, write, malloc, free, exit<br>• ft_printf and any equivalent YOU coded
Libft authorized | Yes

* It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
* If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display ``OK`` followed by a ’\n’ on the standard output.
* In every other case, it must display ``KO`` followed by a ’\n’ on the standard output.
* In case of error, you must display ``Error`` followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

### Example
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 x 0
Error
$>./checker "" 42
Error
```

## My Progoram's behavior is like...
![Animation](https://user-images.githubusercontent.com/67182687/222217900-63d1a5e9-469b-4f33-9176-7a6e1400721f.gif)
_That Kind of Woman, u know?_
