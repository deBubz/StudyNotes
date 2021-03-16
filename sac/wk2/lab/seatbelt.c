#include "RIMS.h"

/* 
    seat belt warning system
    A0 - car is on or off
    A1 - person in driver seat
    A2 - seatbelt

    B0 - seatbelt warning if A0 A1 !A2
*/

void main()
{
    // init
    B = 0;

    while (1)
    {
        if(A0 && A1 && !A2)
        {
            B0 = 1;
        }
    }
}


