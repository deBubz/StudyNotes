/* 
    program calculates the area of a circular doughnut

    demonstrating
    basic file format when using functions in one file
*/

#include <stdio.h>      /* printf, scanf */

/* constants ============================================================================ */
#define PI 3.14

/* prototypes =========================================================================== */

double area_circle(double d);
void just_for_fun(double d);

/* main method ========================================================================== */
int main() 
{
    double d_out, d_in;     /* inner, outer circle diameters */
    double area;            /* donut area */

    /* input */
    printf("enter>[outer_d] [inner_d]> ");
    scanf("%lf%lf", &d_out, &d_in);

    /* calc and output */
    area = area_circle(d_out) - area_circle(d_in);
    printf("donut area: %lf\n\n", area);

    /* testing passing parameters */
    printf("before function: %lf\n", d_out);
    just_for_fun(d_out);
    printf("after function: %lf\n", d_out);
    printf("If value dont change after function call\n");
    printf("passed by value\n");

    return 0;
}

/* func definitions ===================================================================== */

/**
 * calculating the area of a circle given the diameter
 * 
 * @param double circle diameter
 * @return double - area of the circle
 */
double area_circle(double d) 
{
    double area = PI*(d/2)*(d/2);
    return area;
}



/**
 * to test if fucntion parameters passed in
 * by value or reference
 * 
 * @param double an input to modify
 * 
 * > expected, parameters are passed in by reference
 */
void just_for_fun(double d)
{
    d = d+10;
    printf("inside function: %lf\n", d);
}