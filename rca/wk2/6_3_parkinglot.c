#include "RIMS.h"

/* 
    A0 - 7 represent a parking space
    A6 A7 are handicapped spots

    implement
    B upper nibble show number of avaliable non-handicapped spots
    B0 is 1 if both handicapped spots are open
*/

void main()
{
    unsigned char free = 6;
    while (1)
    {
        // count of open slots
        unsigned char taken = A0 + A1 + A2 + A3 + A4 + A5;
        B = (6 - taken) << 4;

        // 6 7 handicapped
        B0 = A6 && A7;
    }
}