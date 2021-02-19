/* 
    converts distances from miles to km
*/

#include <stdio.h>          /* printf, scanf */

#define KM_MILE 1.609       /* conversion const */

int main() 
{
    double kms, miles;

    /* get distance in miles */
    printf("Enter the distance in miles> ");
    scanf("%lf", &miles);

    /* convert distane to km */
    kms = KM_MILE * miles;

    /* display result */
    printf("that equals %.1lf kms", kms);

    return 0;
}

/* 
    programs declare blank variables to store data
    promts user to enter a number
    scan the input and cast it as a long float
    assign input value to tthe address of miles

    converts to km using predefined constant
    prints the varialbe onto the console
    as a long float with 1 decimal point
    showing how to create string formats
*/