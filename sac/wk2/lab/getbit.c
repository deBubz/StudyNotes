#include <stdio.h>

unsigned char getBut(unsigned char x, unsigned char k)
{
    return ((x & (0x01 << k)) != 0);
}

int main()
{
    printf("aa");

    return 0;
}