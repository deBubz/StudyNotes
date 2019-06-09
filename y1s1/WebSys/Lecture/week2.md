# Operating Systems

## Unix

Used to run most of the internet (web servers, DNS, email server, web hosting). Basic concepts of unix: __files, process, permissions and users__. Unix is also portable, written in C. Also Efficient, Stable and relatively secure

---

## File System

Part of OS tbat manage storage data acess

- __Logical File System__(files, directories/subdirectories, partitions)
- __Physical File System__(hard drives)

### Trees

- collection of __nodes__ along with a (__relation__)
- __edge__ is a branch of a tree
- every __node__ in the tree have one parent. __Root__ have no parent
- __leaf__ are branches with no children
- __siblings__ are node with same parents

|syntaxes||
|---|---|
|`/`|root|
|`/home`| branch home|
|`.`| current dir|
|`..`|parent dir|

---

## File Storage

__Distrubuted File System__ multiple connected data centers

- __Disk Physical Structure__: contains tracks, heads, cylinders and sectors.
- __Disk Logical Structure__:
  - Partitions:
  - Blocks: OS view disk space as an array of fized size logical blocks
- __File Allocation Methods__:
  - Contiguous Alocation: A sequential set of blocks is allocated at creation
  - Linked/Chain Allocation: non contiguous. Linked list
  - Indexed Alocation: Tree Based, have an "index" datablock which points to other datablocks.

Usage

- Contigious Alocation: small systems
- Linked/Chain: archival
- Indexed: large

---

## Complexity

Figgure out the best way to store data (assuming efficientcy == best)

- O notation to calculate the time taken to find a block (n == number of blocks)
  - Contiguous: O(1)
  - Linked: O(n)
  - Indexed/Inode: O(logk(n))
