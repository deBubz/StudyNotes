# Divide, conquer and recursion

## Divide and Conquer

General framework of a Divide and Conquer algo 

1. Divide the instance into a set of subproblems
2. If the Subproblem is small enough, solve it; otherwise, recursively split the subproblem.
3. Combine the subproblem solution into a whole solution

### How Does it work

- a problem needs to be **recursively similar** - can an instance be broken into smaller instances of the same problems
- The number and size of the sub-problems must be in the right balance - depends on the the "simple" solution's complexity.
- able to **recombine** solutions into a solution efficiently

> divide problems into small enough sub-problems to be easily solved

`example`

**Binary search** find an element in a sorted array.

1. check the middle elem, is the value greater and order.
2. if its the same you found it.
3. if its greater, find repeat 1 and 2 on the right half and vice versa

> a = 1, b = 2, k = 0. hence binary search is in `O(log n)`

**Fast exponentiation** calc `n^x` for large `n`

slide 14

**Merge so, k = 0rt** and **Quick sort** in the future

> What is this master theorem for

## Recursion

Vital for `Div&Conq`

```
// pseudo code
func( P ){
    if { ... result } // termination condition
    else if { ... func(P_1) }
    else { ... func() }
}
```

- recursive give "neat" yet inefficient code
- Iterative algorithms give efficient yet hard to read code
- you can phrase everything in cs in terms of recursion ( bad practice )
- do what you think best for the problem

`examples`

- **Linear search**
- **Binary search**
- Fibonacci sequence
- Traverse list-like structure

## Recursion v Iteration


