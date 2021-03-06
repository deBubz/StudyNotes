#include "RIMS.h"
/* 
    set output to input execpt B1 and B0 are always 0

    A A7A6A5A4 A3A2A1A0
    B A7A6A5A4 A3A2 0 0

       1 1 1 1  1 1 0 0
       F        3
       & 0x 3F
*/
void main() {
   while(1) {
      B = A & 0x3F;
   }
}