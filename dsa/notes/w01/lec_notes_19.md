# Intro to DSA

## What is DSA

- Data structure
  - way to store/organizes data
- Algos
  - set process

> We talk about algos in their abstract form before getting to implement them

## c++

### String

- strings are null terminated char array
- in c++11 null_ptr exist so you can have a propper null that isnt 0
- points at memory registerd as 0 but cant be used
- c++ has aproper string class std::string (see docs /string/string)
- :: dot operators

### Arrays

very similar to java array

```c++ 
int a[4] = {1, 2, 3, 4}
int a[] = {1, 2, 3, 4}
int a[4] = {}
int a[4]
```

They're all **statically** created. 

- **Stack**
    - Static/ local variables
    - automatically deleted (memory freed) when go out of scope
- **Heap**
    - dynamic, things created with `new` keyword
    - memory need to be manually deleted
    - memory leak issues
    - use pointers to deal with this

Something about `factory` methods:

- Things created in this method must be created dynamically or it will be deleted
- need **new** keyword, and these data need to be cleared when the process is completed or there will be memory issues

#### If you dont know the size

The array will **decay** to `pointer to the elem 0`

the `int[]` can be treated as  **int**

### Pointers

Piece of memory that holds an address of another memory. 

> **pointer** the paper that has an adress to a house

- create pointer type `t`
    - `t * foo`
    - variable named `foo` for ptr type `t`
- dereferencing
    - to get value ptr `foo` is pointing at
    - `t bar = *foo`
- get the address of something(value of the pointer) use the address(`&`) operator
    - `int foo = 5`
    - `int *bar = &foo`

#### References

creates with the `&` operator

good for passing data around with out copying it

#### Arrays  again

to create an array without knowing the size, we need a pointer

`int * tab;`

but thats just a pointer we don't know its an array

we use `std::vector`

### Classes

typical `c++` class

```c++
#include <string>

using <std::string>

class myClass : public parentClass {
    private:
        int privInt;
    public:
        int getPrivInt();
        void setPrivInt(int newVal);
        string toString();
};
```

### Header and Source files

heder files are generally for declaration in the right order of `#include`

source (`.cpp`) are to define the declared variables/methods

some pointer stuff [here](pointers.cpp)

