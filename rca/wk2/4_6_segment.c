#include "RIMS.h"

/* 7 segment display for numbers */

void main()
{
    while (1) 
    {
        switch( A )
        {
        case 0 : B = 0x77; break; // 0111 0111 (0)
        case 1 : B = 0x24; break; // 0010 0100 (1)
        case 2 : B = 0x5D; break; // 0101 1101 (2)

        case 3 : B = 0x6D; break; // 0101 1101 (3)
        case 4 : B = 0x2E; break; // 0010 1110 (4)
        case 5 : B = 0x6B; break; // 0110 1011 (5)
        case 6 : B = 0x7B; break; // 0111 1011 (6)
        case 7 : B = 0x25; break; // 0010 0101 (7)
        case 8 : B = 0x7F; break; // 0111 1111 (8)
        
        case 9 : B = 0x6F; break; // 0110 1111 (9)
        default: B = 0x5B; break; // 0101 1011 (E for Error)
        }
    }
}