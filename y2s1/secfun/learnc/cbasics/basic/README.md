# WTF is C

[Learning Source](https://www.cprogramming.com/tutorial/c/lesson1.html)

## Intro

see `intro.c`

- `#include` **preprocessor** directive telling the compiler to include code from the header files before creating the exe
- `int main()` main method returns int

## Variables

```c
//variables examples
int a,b;
char letters;
float the float; // what
```

**NOTE**: All variables must be declared in the **beginning** in the code block;

```c
int main()
{
    int a = 0;
    printf("a must be declared first");
    return 0;
}
```

## Reading Input(int)

see `input1.c`

```c
// looks at scanf();
int num;
scanf("%d", &num);
```

- see example above, `scanf()` takes in 2 params a string and a variable modified with &
- string tells `scanf()` what variable to look for. the %d tells scanf to read a interger