# Week 03

## q01 which compiles correctly 

c. `#include "file.h"`

## q02 what is the output?

```cpp
int i = 3;
i += 43;            // 46
int *p = &i;
p += 42;
*p -= 8;
std::cout << *p;
```

d. address of an unknown value from memory

## q03 given a stack, what is the result after a sequence of information

what is the top value of the stack
```cpp
push(5)         //  5
push(10)        //  5   10
pop()           //  5
push(1)         //  5   1
push(6)         //  5   1   6
push(9)         //  5   1   6   9
push(1)         //  5   1   6   9   1
pop()           //  5   1   6   9  
pop()           //  5   1   6
push(18)        //  5   1   6   18
pop()           //  5   1   6
pop()           //  5   1
```

top is 1


## q04 where are dynamically allocated var stored?

the heap

## q05 difference between static and dynamic allocation?

**Static** are created in the sack and are automatically de-allocated at the end of the scope

**Dynamic** are created and stored in the heap. Uses the `new` keyword and need to be explicitly deleted using a destructor or the key word `delete`

## q06 What is the output:

Given the input "Hello, World!"

```cpp
std::string test;
std::cin >> test;
std::cout << test;      //  Hello,
```

## q07 which one prints a different output

d. `cout << al`

## q08 which is not normally included in a List

a. enqueue

## q09 given enqueue and dequeue function

what is at the front of the queue

```cpp

enqueue(7)          //  7 
enqueue(5)          //  7   5 
enqueue(9)          //  7   5   9       
enqueue(6)          //  7   5   9   6    
enqueue(7)          //  7   5   9   6   7 
dequeue()           //      5   9   6   7      
dequeue()           //          9   6   7
enqueue(4)          //          9   6   7   4 
dequeue()           //              6   7   4
enqueue(1)          //              6   7   4   1 
dequeue()           //                  7   4   1
```

7 is at the front

## q10 what type and purpose of `~intLinkedList()`

its a destructor, its used to de-allocate instances of `intLinkedList` from the heap.

## q11
## q12
## q13
## q14
## q15
## q16
## q17