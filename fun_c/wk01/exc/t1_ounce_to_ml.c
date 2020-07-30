/*
 simple program converting liquic volume
 from ounce into millimeters
 progress:      DONE
 date:          31 july 20
*/

#include <stdio.h>  

#define ounce_to_mil 0.033814

int main(void) {
    double ounce_vol;

    // input
    printf("Please enter ounce to convert: ");
    scanf("%lf", &ounce_vol);

    // output
    printf("%lf ounce(s) = %lf.5 milliliters", ounce_vol, ounce_vol / ounce_to_mil);

    return 0;
}