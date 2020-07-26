# Week 01

seems simple and basic enough, just some basic programming stuff

## Development steps

- figure out requirements
- problem analysis
- solution design
- implement, test

## printf and scanf

> coverage is very basic, lets just rely on the content from the prescribed book and the one im going through

## errors

- **Compilation errors** - code error, the `compiler` will mostlikely pick this up
- **Logical Errors** - logic errors, only the dev can spot this from testing the program
- **Runtime Errors** - edge cases, errors occuring when running the program. you can check through testing, im looking at you variables


---

# book notes

> from chapt 02

## Language Elements 

Preprocessor directive

- the **preprocessor** modify the program on compilation
  - tell the linker what header files/libraries to link `#include`
  - define constant variables `#define`, this is a **constant macro** which instruct the preprocessor to replace all instance of the var with the actual value
- **main function** you know what this is `int main() {}`

> why do they call *variables* as *identifiers*
> - so *vars* are the name given to a memory address
> - identifiers are user created names given to vars, functions, arrays
> all *vars* are *identifiers* and not all *identifiers* are *vars*

- keep *vars* under 31 char as it will cause trouble for the **compiler**

> Again watch the data types you used for numbers
>
> signed/unsigned 
>
> short/int/long

misc info

- char can be represented as numbers in asci code







