#include "RIMS.h"

/* 
    parking lot has 8 spaces
    A0-7 in each spot

    A6A7 handicapped spot   if both are taken B7
    B0 0 B2     number of available non-handicapped spaces
*/

const unsigned char freespots = 6;
int main()
{
    while (1)
    {
        // counting open slots
        B = A0+A1+A2+A3+A4+A5;
        // handicapped spots
        B7 = A6 && A7;
    }
}
