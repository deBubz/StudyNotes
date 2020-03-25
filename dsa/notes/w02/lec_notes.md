# DSA Week 02

## More `c++` stuff

### Standard IO

- with Terminal `#include <iostream>`
  - read fragment `std::cin >> var_name;`
  - read whole line `std::getline(std::cin, var_name);`
  - write `std::cout << "out";`
- with File `#include <fstream>`
  - write `file_name << "write"`

> practice 1

### Exception

similar to exception handling in JAVA, [docs](http://www.cplusplus.com/doc/tutorial/exceptions/)

```c++
// sample
try {
    // do this
    throw (param)
} catch (ExeptionType param) {
    // do something
} catch (...) {
    // default exeption
}
```

> practice 2

### Pointers

- **Declaration**
  - declaring object `student s;`
  - declaring pointer `student *s_ptr = new student();`
- **Dereferencing**
  - pointer -> attr `s_ptr->score`
  - obj.atr `s.score`
  - pointer.score? `*s_ptr.score` **test this**
- **Memory De-allocation**
  - de-allocate space `delete s_ptr`
  - for obj, nothing needs to be done

> practice 3

### Class

- special member functions
  - `constructors` automatically called when creating an obj
  - `destructors` called before obj memory is de-allocated using `delete` e.g destructor `~LinkedList()`
- create class
  - `static` declaring an obj of class `LinkedList list;`
  - `dynamic` declaring a pointer to an obj of class `LinkedList *list = new LinkedList();`
- delete class ( prevent memory leak )
  - delete a pointer `delete ptr`
  - delete an array of pointers `delete[] array_var`

### Source Files Organization

```md
source package
|- Header files
|  |- #include & namespace
|  |_ Abstract datatypes
|     |- attr
|     |- inner classes
|     |- const/ destructors ( declaration )
|     |- getter setters ( declaration )
|     |_ other functions ( declaration ) 
|_ Source files
   |- class functions ( implementations )
   |_ Main
```

> Practice 4

### Data Structures

#### Queue

- basic `Queue` is the basic FIFO ( first in first out ) *data structure*
- It keeps obj ordered ( like lists ) but ojb can **only** be added(`push()`) to the `back()`, and taken(`pop()`) from the `front()`

```cpp
// virtual class for a Queue of ints
class intQueue {
    public:
        virtual ~intQueue() {};
        virtual bool empty() = 0;
        virtual size_type size() = 0;
        virtual int front() = 0;    // get front elem
        virtual int back() = 0;     // get end elem
        virtual void push(int x) = 0;
        virtual void pop() = 0;
}
```

- **Other queue types:**
  - `Deque` double ended queue - add and remove at **both ends**, good for some data structures
  - `PriorityQueue` elements are inserted with a priority, and come out in a priority order

#### Stack

- `Stack` is similar to queue but opposite. LIFO ( last in first out ) data structure
- Add to the *"top"* and remove from the *"top"*

```cpp
// virtual class int stack
class intStack {
    public:
        virtual ~intStack() {};
        virtual bool empty() = 0;
        virtual size_type size() = 0;
        virtual int top() = 0;     // get top elem
        virtual void push(int x) = 0;
        virtual void pop() = 0;
}
```

> OK so **Stack** and **Queues** are the two most used data structures
> - **OS** Multi level Priority Queues for process scheduling
> - **Networking** ( routers ) buffers of all kinds are **Queues**
> - **Compilers** stacks are built in most lang

### Recursion ( first understanding )

- Basically a function that repeatedly call itself
- BUT they are often use excessive stack and poor in efficiency
  - aim to avoid it in algo design

> have a look at the diagrams at **slides 13 - 14**

#### c++ standard template library