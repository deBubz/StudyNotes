/* 
    program demonstrating data types for numeric values

    additionally also included a function which converts 
    integers into binary
*/

#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void printbin(char *, int);

/*
    alright memory stuff
    you can change the data type of a and its value to see the diffeence

    but for basic built in datatypes
        char    1 byte   
        int     4 bytes
        float   4 bytes
        double  8 bytes

    format specifiers to print string
        %c  -   char
        %d  -   int 
        %f  -   float
        %lf -   double (long float)
*/

/* main method */
int main()
{
    int a = 20;
    printf("value stored in memory\t%d\n", a);

    printf("memory rep:\t\t");
    printbin((char*) (&a), sizeof(a));

    printf("mem block used\t\t\t");
    printf("%p -%p\n", &a, (void*) (&a+1)-1);

    return 0;
}

/* function declarations */

/**
 * print binary value of integer 
 * 
 * @param char* binary string
 * @param int   integer value to convert to binary
 */
void printbin(char *n, int nb)
{
    int i;
    for (i = nb - 1; i >= 0; i--)
    {
        char ncopy = *(n + i);
        /* printf("\n%x - ", ncopy); */
        char binstr[9]; /* including \0 in string */
        int j;
        for (j = 0; j < 9; j++)
        {
            binstr[7 - j] = '0' + (ncopy & 1); /* take last bit, convert to ascii */
            ncopy = ncopy >> 1;                /* discard last bit, get the next */
        }
        binstr[8] = '\0';
        printf("%s ", binstr);
    }
    printf("\n");
}