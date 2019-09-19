# Advanced C

## Arrays

- On var declaration the compiler will assign the variable to a certain memory register(address) 
- Store multiple values of a cerctain datatype, each value of the array is accessed through `arrayName[index]` (each index num is associated with a unique memory address)
- **NOTE** `char a[i]` is refered to as the **string** datatype as it can store multiple char (a word) at once. It does so by splitting the word and storing single char at each index value

|Some Table||
|:---:|---|
| variable a | Memory Address |
| a | (0xaa1122) |
| array[0] | (0xa771522) |
| array[1] | (0xad1142) |
| array[2] | (9xabb3162) |
| array[3] | (0xba1472) |
| array[4] | (0xbb1822) |
| array[5] | (0xab1129) |

## If else Statement

Refer to [Ifelse.c](Elif.c)

## Switch Case

Refer to [Switch.c](Switch.c)

## For loop

Refer to [Forloop.c](Forloop.c)

## While Loop

Refer to [While.c](While.c)

## Do while loop

refer to [Do.c](Do.c)

## Functions

- Used to define set of action
- C is a procedural programming language (**NOT OOP**)
  - It must be defined/ declared in the begining of the program.
- recursion OK

Refer to [Function.c](Function.c)

## Pointers

- Pointers vars are variables that store(point to) memory address
- `int *ptr` pointer to an int variable
- Reference Operator `&` when used before a var `%a` will refer to its memory location
  - `pta = &a` allocate `ptr` to **Memory address** of `a`.
- Deference Operator `*`
  - `x = *ptr` assign `x` to the `int` that is pointed to by `ptr`

```c
int x,y = 5;
int *ptr;

ptr = &y;
x = *ptr;
// same as x = y;
```

hmmm

Refer to [Pointer.c](Pointer.c)

## File IO

- Reading, Writing to external files
- Uses different modes:
  - `r` open for reading (should exist)
  - `w` open for writing (no need)
  - `a` open for appending (no need)
  - `r+` open for r/w (ovewritten at beginning)
  - `w+` open for r/w (overwrite file)
  - `a+` open for r/w (append if file exist)

Refer to [FileIO.c](FileIO.c)