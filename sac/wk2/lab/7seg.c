#include "RIMS.h"

/* 
    1x single segment display

    set to display 0 - F 
    following the provided diagram of the 7seg
*/

// globally declared 
char HEXSEG = [
    0x77,   // 0
    0x24,   // 1
    0x5d,   // 2
    0x6d,   // 3
    0x2e,   // 4
    0x6b,   // 5
    0x7b,   // 6
    0x25,   // 7
    0x7f,   // 8
    0x6f,   // 9
    0x3f,   // a
    0x7b,   // b
    0x53,   // c
    0x7c,   // d
    0x5b,   // e
    0x1b,   // f
]
void main()
{
    // init
    B = 0;

    while (1)
    {
        B = HEXSEG[A];
    }
}

// to be tested

