# Arrays

Arrays is a block of `contiguous memory` to store a fix number of elements of the same type

```c
/* double array of 8 elems */
double x[8];
```

## Manipulating Array

```c
/* something is foing on here?? */
printf("%.1f", x[0]);
x[3] = 25.0;

sum = x[0] + x[1];
sum += x[2];

x[3] += 1.0;
x[2] = x[0] + x[1];
```
> arr starts at 0, go up to -1

## Array and Functions

when passing and array through the function, function **DONT** make a local copy.
Any changes will modify the array.

> arrays are passed by reference

To remember when passing `arrays` to `functions`
- also pass the size of the array, function dont know the size of array
- arrays are **passed by reference**
- using the `const` keyword when passing arrays should *prevent any change*
- can func return array

## Array Size

OK array has fixed size, what if we dont know the exact size

Some solutions:
- at least know the **max size**
- allocate a large array, only use what is needed
- use `int` to keep track of what is used.

> or learn about pointers

# String 

> There are **no data structures** for string in C

strings are basically **a block of chars** 
- can be stored in a `char[]`

```c
char str[] = "a word thing";
printf("%s\n", str);
``` 

OK one thing:
- when passing arrays to functions, we also need the array size.
- how does `printf` know the size?

## `NULL` termination

In c, strings must be terminated by a `NULL` char `\0`

Hence for a 5 letter string, the array size is actually 6.

> to store a `n` length string, the size needs to be `n + 1`

`printf` prints all char in memory untill `0\` is found

## `string.h`

> look up the docs and see what is useful

## Alternatives

different ways to define string
- `char str[/* size*/]` string is mutable;
- `char* str` char is not mutable

> you learn pointers later


> chapt 07, 08