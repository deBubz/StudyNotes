# c revision

## compilation

```sh
## single file default output
gcc -Wall -Werror filename.c
# output: a.out
# to run:
./a.out

## single file with output name
# output name can have no extension
gcc -Wall -Werror -o output.out input.c
# output: output.out
```

### compiling multiple files with `make`

> Do later after other contents

---

## Basics

simple [hello_world.c](./hello_world.c) contains:
- main method
- importing standard i/o library
- printing a string onto console
- `main` return type

reading user input [miles_km.c](./miles_km.c):
- declarating empty variables
- assigning user input value for a specific datatype
- defining CONSTANTS
- print formatted string

## Types/Functions

basic numeric types [numer_types.c](./number_types.c):
- number types memory size
- string format specifiers to print some types
- first look at addresses and memory

basic functions declarations/definitions[functions.c](./functions.c):
- styling standard if using functions
- function declaration and definition
- function doccumentation
- demo: if values are passed in by value or reference

## controll structures

> you know what these are

- includes conditional operators, logical opertators
- if/ else if/ else statements
- switch statements
- for loops
- while loops
- do while loops

printing a [square pattern](./sqr_ptt.c)
- design pattern: get infinite user input using for loop
- for loops