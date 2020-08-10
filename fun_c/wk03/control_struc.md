
> something about control structures

they are elemts that influence the point of excecution:

- sequence
- selecttion/ alternation
- repetition/ reptition

control structures can conditionally execute a **compound statement** (code block, scope..)

## contents

- [contents](#contents)
- [conditional operators](#conditional-operators)
- [logical operators](#logical-operators)
- [order of operation (short circuit evaluation)](#order-of-operation-short-circuit-evaluation)
- [if statement](#if-statement)
- [switch statement](#switch-statement)
- [control structure repetition (teh l00ps)](#control-structure-repetition-teh-l00ps)
  - [prefix/postfix increments](#prefixpostfix-increments)
  - [while loop](#while-loop)
  - [for loop](#for-loop)
  - [do while loop](#do-while-loop)

---

## conditional operators

> you know this

```
< <=
> >=
==
!=
```

## logical operators

> you know this

for conditional statements

```
&&
||
!
```

## order of operation (short circuit evaluation)

so **short circuit** evaluation

- this relates to the logical operators in conditional statement in the last section
- when the whole condition can be evaluated part way through the eval, then the rest of the expression is ignored
  - `e.g` the `&&`  operator, if the first part is false, then the whole expression will then assumed to be false
  - obviously this is because of built in optimization in `c`

## if statement

> you know this

```c
if () 
{

}
else
{

}
```

write the statement based on a flow chart `s 11`



## switch statement

> you know this

```c
char a;
switch(a)
{
    case 'a':
        printf('a');
        break;
    default:
        break;
}
```

## control structure repetition (teh l00ps)

### prefix/postfix increments

`i++`

`++i`

### while loop

> you know this

```c
while()
{

}
```

### for loop

> you know this

```c
for(int i = 0; i < 3; i++)
{

}
```

### do while loop

> you know this

```c
do
{

} while ()

```

