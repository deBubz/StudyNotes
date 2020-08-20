/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
Arrays and functions. Arrays are always passed by reference. But if an
individual element of an array is passed, that would be passed by value.

The function needs to know the size of the array, must be passed as a seperate
parameter to the function.

If a function is supposed to only read the array (not modify it), then pass the
array as a constant.
*******************************************************************************/

#include <stdio.h>

void plusone(int array[], int arrayLen, int arrayElement);
void printarray(const int array[], int arrayLen);

int main(void)
{
    int alen = 5;
    int a[] = {10, 20, 30, 40, 50};

    printarray(a, alen);
    /*printf("In main: sizeof(a)=%ld\n",sizeof(a));
    */

    /**/
    printf("Before changing...\n");
    printf("ArrLen = %d, ", alen);
    printarray(a, alen);
    
    plusone(a, alen, a[1]);
    
    printf("After changing...\n");
    printf("alen = %d, ", alen);
    printarray(a, alen);
    

    return 0;
}

/*
observe: arrayLen is passed to the function.
observe (later): array is not modified in this function. const
*/
void printarray(const int array[], int arrayLen)
{
    printf("Array = ");
    int i;
    for(i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    /*
    printf("In printarray: sizeof(array)=%ld\n", sizeof(array));
    */
}

// only the first line
// array 0 += 1 is added        pass reference
// arrayLen dont do anything    pass value  
// arrElem dont do nothing      pass value
void plusone(int array[], int arrayLen, int arrayElement)
{
    array[0] += 1;
    arrayLen += 1;
    arrayElement += 1;
}

