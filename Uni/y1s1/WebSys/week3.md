# WEEK 2 OS part 2

## UNIX

- OS used to run most of the internet.(Servers, mainframes)
- e.g System V, BSD
- used C
- ADHOC Development
  - lots of Unix variation
  - can be confusing for end users
  - IEEE tried to standeredised shell commands - __POIX__
  - 1990 unix wars
- standards for unix cmd
  - single uni specification 2002
- how usix survive since the 60s, __no one owns unix__
  - its based on simple concepts
  - its portable, Compiled in C, not tied to any specific CPU
  - some varieties are free, can run on simple systems.
  - efficcient, secure, stable
  - have a set of tools to approach

---

## OS - File Systems

- estimated a billion sites 
- google only indexed 200tvb of data > warehouse 12exabyte 15 mill tb

### File system 

- part of the os that manage storage data acesws
  - Logical file syst
    - what you see, files, dirs, partitions
  - physical file sys
    - what you see

### Logical

- Files exe, data
- Dirs, heirachial directories
- partitions drives

- structure of file systems have roots (in windows C:\, D:\)
- __Theory of trees__: collection of _nodes_ along with a relation _parenthood_.
- every node in a tree have a single parent. Root have no parent
- leaf is a node with no children
- siblings have same parents

```UNIX
/          means root
/home      means branch 'home'
.          means current dir
..         means parent dir
```

---

## File Storage

- Distributed file system - multiple connected data centers

Most pc have a physical storage drive
Hard Disk, Solid State Drive

### Physical Disk

- Disk Structure
  - Tracks
  - Heads
  - Cylinders
- Logic Structure
  - partitions, Disk can be divided partitions (Boot Partition, System Data, Data)
  - Blocks, the OS view disk data as array of fixed size logical block
  - Random access
  - Fragmentation: unused block space
  - Chained Allocation
    - collection of non-contigious block
    - linked list
  - indexed alocation
    - tree based alocation system.

- inode store metadata

- Storage is depends on needs
  - Contigious is good for direct storage and tiny file systems
  - chain/linked is for archival 
  - Indexed only good for large systems

---

## Complexity

### Complexity theory

- Big O notation!!
- Time v size
- n = number of blocks in a file. To find a block ti takes how many acess
  - Contigious  O(1)
    - constant read.
  - chained/linked O(n)
    - porportional to the size of the block, read sequentialy
  - Indexed/Inode O(logk(n))
    - shortest path in a tree
    - logrithimic because its  a binary search, depends on how deep the tree is.
