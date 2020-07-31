// program to convert miles to km
// take a float input and print out the result in km
// using functions 

#include <stdio.h>

#define MILE_KM_RATIO 1.609

/* prototype */
double miles_to_kms(const double miles);

/* main */
int main(void) {
    double miles;

    // get input
    printf("enter a distance in miles: ");
    scanf("%lf", &miles);

    // output
    printf("%.3lf miles = %.3lf km\n", miles, miles_to_kms(miles));

    return 0;
}

/**
 * conveting miles from km using the formular
 * miles * 1.609
 * 
 * @param miles value to be convert into kms
 * @return double value in kms
 */
double miles_to_kms(const double miles) {
    return (double)MILE_KM_RATIO * miles;
}