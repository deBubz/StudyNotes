#include "RIMS.h"
/* 
    if there are 3 - 1bit in a row
    set B0 to 1
*/
unsigned char GetBit(unsigned char x, unsigned char k)
{
    return ((x & (0x01 << k)) != 0);
}

int main()
{
    while (1)
    {
        char count = 0;
        char i = 0;
        for (i = 0; i < 8; i++)
        {
            if (GetBit(A, i))
                count++;
            else
                count = 0;

            if (count == 3)
                break;
        }

        B0 = count == 3;
    }
    return 0;
}