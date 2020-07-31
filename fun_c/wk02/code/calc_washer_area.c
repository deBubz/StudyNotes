/*
A program to calculate the area of a flat washer given the
outer and inner diameters.
use a function that calculates the area of the circle
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14

/* prototype */
double circle_area(const double diameter);

/* main */
int main(void) {
    double inner_d, outer_d;
    double washer_area;

    /* get input */
    printf("Enter the outer and inner diameters: ");
    scanf("%lf%lf", &outer_d, &inner_d);

    washer_area = circle_area(outer_d) - circle_area(inner_d);
    printf("The area of the washer is: %.3lf", washer_area);

    return 0;
}

/**
 * calculate the area of a circle using a diameter
 * 
 * @param diameter
 * @return the area of the circle
 */
double circle_area(const double diameter) {
    return PI * pow(diameter/2, 2);
}