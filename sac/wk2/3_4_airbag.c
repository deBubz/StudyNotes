#include "RIMS.h"

/* 
    some if else statements to similating 
    airbag warning 
*/

void main()
{
    while (1)
    {
        // enable airbag system
        if (A >= 105) B0 = 1;
        else B0 = 0;

        // airbag off light
        if (A > 5 && A < 105) B1 = 1;
        else B1 = 0;

        // printf("%d - %d\n", A, B); 
    }
}