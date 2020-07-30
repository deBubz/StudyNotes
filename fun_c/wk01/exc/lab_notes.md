# Week 1 ED lab notes

the basics of working with `printf` and `scanf`

## Discuss 

When using `printf` and `scanf`, some time we use `&`. When and why do we use `&`
- `&` is of ten prepended onto variables, it refer to the memory address the program which the variable is assinged to
- in `printf`, itll print the address of the variable
- in `scancf` its used to assign values to (the address) that variable

## Task 1

Write a program to convert **ounce** into **millimeters**

[code here](./t1_ounce_to_ml.c)

task 2 is just basicly a file to verify the output of task 1

## Task 3

reminder notes to pay attention to your **coding style**

> NOTE: you may not agree with the coding style **BUT** just as rl, `adapt`

this maybe important for the assessments so:

- remember to comments
- properly indentation (use space characters for 1 tab = 4 spaces)
- appropriate variable names
- use macros (`define` constants) when appropriate
- **NO** global variables
- list used functions when including a library
  - `#include <stdio.h> /* printf, scanf */`

functions (covered later)

- breaks the program to sensible functions that call eachother when neccessary (carry flight time, carry height)
- each should has a specific task
- comment its description
- describe the io

> lets stick with the java doc style done vefore

arrays (covered later)

- size must always a constant (use macro)
- when passing an array to a function, pass the size too
- when passing an array to a **read-only** func, it should not modify the array (use `const`). Arrays are passed by reference

structures (covered later)

- typecast using `typedef`
- a typecasted structure type should have a name ending with `_t` to signify its a custom define type