/* 
    print square shapes with a specific
    side length entered by the user

    demo loops
*/

#include <stdio.h>      /* printf, scanf */

/* prototypes */
void print(int len);

/* main method */
int main()
{
    /* NOTE: defining i seperate from the for loop is for old c++ */
    /* infinite input untill 0 is entered */
    int i, inp;
    for(i = 0, inp = 1; i < 5 && inp != 0; i++)
    {
        /* for i = 0, input = 1 */
        /* while i < 5 and inp is not 0 */
        /* keep looping */
        printf("input> ");
        scanf("%d", &inp);
        print(inp);
    }

    return 0;
}

// ok broken not working yet


/* function definition */
void print(int len)
{
    int i, j;
    for(j = 0; i < len; j++)
    {
        for(i = 0; i < len; i++)
        {
            printf("* ");
        }
        printf("\n");
    }
}