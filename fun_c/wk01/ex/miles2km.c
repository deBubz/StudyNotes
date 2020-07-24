// program to convert miles to km
// take a float input and print out the result in km

#include <stdio.h>

#define MILE_KM_RATIO 1.609

int main(void) {
    double kms, miles;

    // get input
    printf("enter a distance in miles: ");
    scanf("%lf", &miles);

    // output
    kms = MILE_KM_RATIO * miles;
    printf("\n%.3lf miles = %.3lf km\n", miles, kms);

    return 0;
}