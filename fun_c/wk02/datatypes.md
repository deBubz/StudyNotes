# Data types and operators

## Datatypes

### Primitives datatypes

most common

| datatype | sizeof() | info                                                            |
|:--------:|:--------:|:----------------------------------------------------------------|
|   char   |   1 B    | store exact num in 2's complement using ASCII to map characters |
|   int    | 2 or 4 B | store exact num in 2's complement                               |
|  float   |   4 B    | store approximate (sign, exponent, mantissa) ( 1.234e3)         |
|  double  |   8 B    | store approximate (sign, exponent, mantissa) ( 1.234e3)         |

> briefly revise on how 2's complement numbers work for signed ints

**NOTE** always always becareful when working with floating point variables, it does not always store the exact number as you want

> search up ?? *write the program in fixed points* ?? for writing embedded hardware

### data is stored in memory at addresses

this talks about what variables are, variables carries the address where the data its assigned to 

example to see data type and its representations in memory [provided code](./provided_code/f02a_mem_representation.c)

## Operators

- simple arimetics operators `+`, `-`, `*`, `/` and `%`
  - plus and minus are carried out by the addition of 2's complements
- order of precedence 
  - parens
  - `+ - unary`
  - `* / %`
  - `+ - binary`
  - `= `

> you know this from basic maths and discrete maths **the evaluation tree**

### Division and `typecast`

take care when using division `/` as if you are using ints, there will be a loss of data (implicit casting) when trying to dividing ints

example [provided code](./provided_code/f02b_typecasting.c)

## Functions

### procedural function

C is a **procedural** oriented lang

- function allow us to logically group statements that performs a specific task.
  - input/one or no outputs
  - use the reference passed through the inputs for multiple output
- breaking down a program to sensible number of functions is vital for
  - readability
  - reusability
  - testability

### function prototype

1st part of a function

in variables there are 2 stages
- definition/ declaration - defining the datatype and the variable name
- initialization - assigning a value

function also has **2 stages**
- **prototype** tells the compiler the `name`, `input datatype`, `output datatype`
- **definition** implementation of the function

there are **2 types** of functions
- **predefined** from a library by another user
- **user-defined** write it yourself

> see slide 10 for sample code
