/* 
    demoing how array typically works in c

    member strings are also arrays
*/


#include <stdio.h>

#define LEN_1 5

/* prototypes */
void print_arr(int *arr, int len);
void arr_add_value(int val, int* arr, int len);

/* main method */
int main()
{
    /* declare array of len 5 */
    int arr[LEN_1];
    int arr_len = 0;    /* to keep length of array */
                        /* c doesnt keep track of array length */

    /* arrays are basically pointers to the first element */
    /* declarign array with a set length allocates a contifious block of memory */
    /* for data */

    /* initializing array, can also use scanf */
    int i;
    for(i = 0; i < LEN_1; i++)
    {
        arr[i] = (10*i);
        arr_len++;
    }

    /* array content and address */
    /* have a look at the differences between each element */
    printf("Printing Array\n");
    print_arr(arr, arr_len);

    /* since array are pointers to the first element */
    /* arrays are passed by reference */
    printf("\nArray Mutation\n");
    arr_add_value(5, arr, arr_len);
    print_arr(arr, arr_len);

    /* check if the address the memory block has changed or not */

    return 0;
}

/* functions */

void print_arr(int *arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        /* can also use arr[i] */
        /* since arrays are pointer to the first element */
        /* code tell the pointer to shift to next "block" */
        /* right now each block are 4 bytes as this is an int arr */
        printf("%d\t%p\n", *(arr + i), (arr+i));
    }
}

void arr_add_value(int val, int* arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        *(arr + i) = *(arr + i) + val;
    }
}