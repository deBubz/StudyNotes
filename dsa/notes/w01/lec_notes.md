# Intro to DSA

- [Intro to DSA](#intro-to-dsa)
  - [What is DSA](#what-is-dsa)
  - [Struct v Class](#struct-v-class)
  - [c++](#c)
    - [Basic types](#basic-types)
    - [String](#string)
    - [Arrays](#arrays)
      - [If you dont know the sizeof arrays](#if-you-dont-know-the-sizeof-arrays)
    - [Pointers](#pointers)
      - [References](#references)
      - [Arrays  again](#arrays-again)
    - [Classes](#classes)
    - [Header and Source files](#header-and-source-files)
    - [Namespace and `include`](#namespace-and-include)
  - [Linked list](#linked-list)

## What is DSA

- **Data structure**: way to store/organizes (non-persistent) data
  - **Simple data type**: `bool`, `int`, `char`, `float` and `double`
  - **Data Structure**: set of data items with definite associations
    - **Native**: array, vector, queue
    - **Free-form**: linked list, tree, graph
  - **Class**: DataStructure + operation

## Struct v Class

- `class` members are private by default
- `struct` miniature of class, can have member functions

> They both are considered as data structures - both expose data to be manipulated

```cpp
struct student {
    char name[20];
    int sID;
    student *next;  // pointer to next node
};

class student {
    public:
        char name[20];
        int sID;
        student *next;
};
```

- Data structures represent those in-memory data models.
- They need to be transformed for persistence ( `pickle` `serialization` )

> We talk about algos in their abstract form before getting to implement them

## c++

### Basic types

- just primitive types
  - `bool`
  - `char`
  - `short int`, `int`, `long int`
  - `float`, `double`
- in this case `short`, `long`, `signed` and `unsigned` are just modifiers see more [here](http://www.cplusplus.com/doc/tutorial/variables/)

### String

- strings(`std::string`) are null terminated char array(`char[]`)
  - to use the string class `#include <string>`
- in c++11 null_ptr exist so you can have a proper null that is not 0
- points at memory registered as 0 but cant be used
- c++ has a proper string class std::string (see docs /string/string)
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

> MISC: memory constructor, destructor
> - `C`: `malloc()`, `free()`
> - `C++`: `new`, `delete` 

Something about `factory` methods:

- Things created in this method must be created dynamically or it will be deleted
- need `new` keyword, and these data NEED TO BE CLEARED when the process is completed or there will be memory issues
- don't use `new` unless you mean it?

#### If you dont know the sizeof arrays

The array will **decay** to `pointer to the elem 0`

the `int[]` can be treated as  **int**

### Pointers

Piece of memory that holds an address of another memory. 

> **pointer** the paper that has an address to a house

- create pointer type `t`
    - `t * foo`
    - variable named `foo` for ptr type `t`
- dereferencing
    - to get value ptr `foo` is pointing at
    - `t bar = *foo`
- get the address of something(value of the pointer) use the address(`&`) operator
    - `int foo = 5`
    - `int *bar = &foo`

> Make Something to represent pointers

#### References

- creates with the `&` operator
- similar to `pointers`? But:
  - **cant change** where they points( reference ) once initialized
  - **transparently dereferenced**

good for passing data around with out copying it

> OK test this out 

#### Arrays  again

to create an array without knowing the size, we need a pointer

`int *tab;`

but thats just a pointer we don't know its an array

we use `std::vector`

### Classes

typical `c++` class:

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

`c++` have 3 access modifier: private (default), public, protected

### Header and Source files

- `c++` routinely separates declarations ( h ) from source code ( cpp )
  - it expects a single pass compiler, make sure all the names are in the right order.
- `.h` files typically only contains declarations ( definition is fine too )
- `.cpp` are to define the declared variables/methods

> `header` files are equivalent of interfaces

### Namespace and `include`

- you know the `include` keyword to use `<string>` and `<iostream>`
- the `<>` tells the compiler to look in the library path
- the `""` tells the compiler to look in the working dir
- something something `namespace` which requires you to use the `::` ( scope resolution op ) operator to access the scope

---

## Linked list

- Like a list, stores data in a sequential order.
- Different from array, Linked list can by **dynamically** modified

