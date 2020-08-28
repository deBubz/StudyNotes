/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
Illustrate how switch statements are written and executed. Emphasise the
importance of break statement. 
*******************************************************************************/

#include <stdio.h>

int main(void)
{
    char class = 'x';

    switch (class)
    {
        case 'B':
        case 'b': 
            printf("B for ball\n");
            break;
        case 'C':
        case 'c':
            printf("C for C-programming\n");
            /* no break also run the next case  */
        case 'D':
            printf("After C here comes D\n");
            break;
        default:  
            printf("I don't understand\n");
            break;
    }
    return 0;
}