/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
Write a conditional statement to print a message accoridng to the value of a
variable.
  - Illustrate the difference between = and ==.
  - scope of variables defined within compound statements. variables can be
    accessed anywhere between {  }, after they have been declared.
*******************************************************************************/

#include <stdio.h>

int main(void)
{
    int a = 0;
    
    if (a == 0) /* check */
    {
        int b = 10;    
        printf("a = %d. a is zero, zero is a beatiful number\n", a);
        printf("b = %d\n", b);
    }
    else
    {
        printf("a = %d. a is not zero\n", a);
        /*printf("b=%d\n", b);*/
    }
    return 0;
}