# Week 06 Tree stuff

> Have a look at the ds list sl3

## Binary Tree

> slide 5,6 descriptions

### Use of Binary Tree

- 3d rendering (binary space partition)
- Networking (binary tries, treaps)
- cryptology (GGM Trees)
- Coding and Compressions (Huffman trees)
- hashing (Hash trees)
- Sorting (Heaps and Heapsort)
- Searching (Binary Search Trees)
- Parsing (Expression Trees)

### How binary trees are built

> slide 8

## Tree Traversal

> slide 9, have a look at how trees a built

### Depth First Traversals

- At each node there are 3 actions to carry out
  - deal with current node
  - visit left child
  - visit right child
- The order of actions creates different **type** of DFT
  - pre order
  - in order
  - post order

> The pseudo code are nice, there are
> - **pre-order**: recursive (sl11), iterative(sl12)
> - **in-order**: recursive (sl13), iterative(sl14)
> - **post-order**: recursive (sl15), iterative(16)

### Breadth first traversal

- travel according to each level of the tree (root, neighbours of root, neighbours of branch)

> pseudo iterative(sl18)

### Traversal Summary

- Only in-order traversal produces the node sequences that can be used to rebuild the original tree
- Can easily find trees for pre, post, and bfs from which they will generate the same sequence

## Binary Search Trees

- **bst** is a simple data structure that allow fast *insert*, *removal*, and *lookup* of elements.
- Its an ordered data structure that doesnt require reshuffling to insert new elements ( unlike array ds )
- simple rule to find/insert
  - binary search method
  - if your item has a smaller key than the current vertex go left, else right
- insertion then is just traversing the tree to the bottom and adding the new element where ever you stop
- finding is basically binary search

### Removing from BST

- if the removing node has **no children**, it wont break anything, just remove
- if there is **1 children**
  - move the child up one level to replace the removing node (linked list pointer change)
- if there are **2 child**
  - swap the values of this node such
    - `x` contains either smallest value in the right or the largest in the left ??
  - remove `x` using the deletion algorithm either case 1 or 2 ??

### BST Complexity

> have a look at slide 23

### Why is it useful

> math example slide 25, 26

## AVL Trees

- more balanced binary trees
- where binary trees work better when balanced (which is uncommon)

AVL trees does extra work on each insertion and deletion, to maintain good running time and a balanced tree

> Complexity sl 29

### How are AVL trees balanced

- by maintaining an invariant at each vertex: the balance factor.
- **balance factor** of a vertex `v`:
  - left subtree height - right subtree height
- **balance factor** can be `-1`, `0`, `1`, anything else warrant a re-balancing
- Because inserting a new element ony adds one vertex, the balance factor will only get as bad as `-2` or `2` (needs re-balancing)

### Insertion into AVL

- insert node `w` normally as BST
- starting from `w` travel up and find the first unbalanced node, say `z`
  - `y` be the child `z` comes on the path from `w`->`z` and `x` be the grandchild of `z` that comes on the path `w`->`z`
- re-balance the tree by performing appropriate rotations on the subtree rooted with `z`
- can be 4 possible case, each can be handled via `1` or `2` tree rotation

### Tree Rotations

4 possible case in changing tree structure while preserving the traversal order

> interesting slide 32



