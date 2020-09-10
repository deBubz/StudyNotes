# pointers and dynamic memory management

## Scope of variables

part of the program where a variable name is known

> you know about scopes

sample [swap 2 integers](swap.c)

## Pointers 

pointers are variables containing **memory location**.

Some notation are as:

```md
int x   -   new int var
x       -   x value
&x      -   address of x

int* xp -   var of an address of an int
xp      -   address
*xp     -   value in that address
```

```md
void fun(double* d)     - func requiring address of double
double d                - var of a double
fun(&d)                 - passing double address into function
```

## Pointers in functions and arrays

functions usually only returns one value. but with pointers, the possibilities is endless

pointers are **similar** to **pointers**

```c
int a[] = {1, 2, 3};
/* a is a pointer to the 0th elem in the array */
/* a is an address */
```

note: these are the same

```c
&a[0] == a
a[1] = *(a + 1) 
/* alternativxxe way to trabvel */
```

