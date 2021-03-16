#include "RIMS.h"
/* 
    set B0 - 3 to A2 - 5
*/
void main()
{
    while (1)
    {
        B = (A & 0x3C) >> 2;
    }
}