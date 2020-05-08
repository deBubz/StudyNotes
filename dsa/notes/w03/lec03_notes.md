# Week03 Vectors & Lists

- [Week03 Vectors & Lists](#week03-vectors--lists)
  - [Vectors and Lists](#vectors-and-lists)
    - [Vectors](#vectors)
    - [Functions of `vector` and `list`](#functions-of-vector-and-list)
    - [Comparison](#comparison)
    - [STL containers](#stl-containers)
    - [Container adaptors](#container-adaptors)
  - [Templates](#templates)
  - [Iterators](#iterators)
  - [Algorithms](#algorithms)
    - [Big-O notation](#big-o-notation)

## Vectors and Lists

- Alternative Data Structures to Array
  - vector `#include <vector>`
  - list `#include <list>`
- [Read](https://thispointer.com/difference-between-vector-and-list-in-c/)

### Vectors

- Dynamic size arrays, less overhead than lists/linkedlist
- its just a wrapper for a regular array
  - functions like an array, but with extra steps so it is dynamically allocated

### Functions of `vector` and `list`

- **iterator**: enumerating all elements of the container
- **capacity**: get/adjust size of container
- **element access**: get elem at a specific location
  - not primitive to c++ so not random access
- **modifier**: crud options

> References: (try practice 2 and 4)
> - https://www.geeksforgeeks.org/vector-in-cpp-stl/
> - https://www.geeksforgeeks.org/list-cpp-stl/

### Comparison

- **array**
  - mem: fixed size, contiguous
  - feat: random access, shift upon deletion
- **vector**
  - mem: dynamic size, contiguous
  - feat: random access, shift upon deletion
  - implementation: based on `array`
- **list**
  - mem: dynamic size, contiguous
  - feat: efficient insertion and deletion 
  - implementation: based on `doubly linked list`

> practice 1

### STL containers

> `Containers` are objects that store data

- similar to java generics, work at runtime
- does not change the function of the data structure, tells what the size of memory will be allocated.
  - very error prone, careful of logical bugs

> `STL` standard library

- **Simple container**
  - `pair`: simple 2-tuple store
- **Sequence containers** (ordered coll)
  - `vector`: dynamic array
  - `deque`: double ended queue
  - `list`: doubly linked list
- **Associative containers** (unordered coll)
  - `set`: a mathematical set
  - `map`: key-value storage
  - `multiset`, `multimap`: allow duped elem/keys
  - `hash_set`, `hash_map`, `hash_multiset`, `hash_multimap`: implemented using hash tables

### Container adaptors

These are classes that use an encapsulation object of a specific container class as its underlying container.
Providing a specific set of member functions to access elements

- **queue** based of deque or list
- **priority queue** based on vector or deque
- **stack** based on deque, vectors or lists

```cpp
queue <int, list<int>> q; // implement an int queue based on int list
queue<int> q;             // by default build a queue based on dequeue
```

## Templates

> `templates` are angle practice that let you specify the datatype of containers

```cpp
int sum(int x, int y) {   // can only handle int
  return x + y            // what happened when the user uses
}                         // double, float, short, long
```

templates

```cpp
T sum(T x, T t) { return x + y };

// calling
sum(1.05, 3 );
```

template class example
```cpp
template <typename T>
class Node {
  T data;
  T * next;
}
```

> practice 3

## Iterators

> `iterators` or limited pointers are used to point at the mem address of STL containers

- primarily used in sequence of  numbers, chars...
  - **iterator**: random access container
  - **bidirectional** iterator: non-random access containers.
- reduce complexity and execution time of programs
- iterators are built-into c++ 

ok so

- Why iterators?
  - STL algorithms in `<algorithm>` use iterators
  - A flexible way to access data in containers that don't have obvious means of accessing all of the data ( maps )
- gotchas? cons?
  - No boundary check (out of index?)
  - Can be invalidated if the underlying container is changed significantly

> practice 4

some iterators are:

- linked list: `getHead()`, `tail()`
  - tail returns the list after head

---- 

## Algorithms

- In algorithms, we are mainly interested in
  - **Space complexity**: time to run
  - **Time complexity**: space to take up
- So how do we compare algorithms
  - **Testing** but it is limited to the cases you test and is time sensitive
  - How much of the testing information varies from the choice of computer, language, or test data?

### Big-O notation

> discrete maths stuff

- Some handy stuff, suppose `k` is a constant
  - `n` is "linear"
  - `n^2` is "quadratic"
  - `n^3` is "cubic"
  - `log n` is "logarithmic"
  - `(log n)^k` for any `k` is "poly-logarithmic"
  - `n^k` for any `k` is "polynomial"
  - `k^n` for any `k` is "exponential"
- Any complexity `< O(n)` is "sub-linear"
- So how to get the functions and analyze the algorithms
  - In the abstract sense, running time is the number of steps the algorithm take for a given input size
- Just "count" the number of steps


