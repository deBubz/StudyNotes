#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *pc;
    int c = 22;

    printf("Address of c: %p \nValue of c: %d\n\n" , &c, c);

    pc = &c;
    printf("pc = &c\n");
    printf("Address of pointer pc: %p\nContent of pointer pc: %d\n\n", pc, *pc);    

    c = 11;
    printf("c = 11\n");
    printf("Address of pointer: %p \nContent of pointer pc: %d\n\n" , pc, *pc);

    *pc = 2; // change the value of c
    printf("*pc = 2\n");
    printf("Address of c: %p\nValue of c: %d", &c, c);

    return 0;
}