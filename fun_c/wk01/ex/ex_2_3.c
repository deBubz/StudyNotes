// some simple exercises from the text book
// im mainly doing this to get back to the habit of buidling stuff
// tbh I am very lazy

#include <stdio.h>

// for q3
#define PI 3.14159

int main(void)
{
    printf("Ex 2_3 - self check\n\n");

    // q 1
    int m, n;
    printf("1. Enter 2 intergers: (ok numbers are preset)\n");
    printf("change the code if you want to test\n");
    // scanf("%d%d", &m, &n);
    m = 5; n = 3;    

    printf("m = %d\nn = %d\n", m, n);
    printf("%d = %d + 5\n%d = 3 * %d\n\n", m+5, m, 3*n, n);

    // ok the ex are lame
    printf("ex 2_3 - programming\n\n");

    // q 1 enter 3 int values
    int a, b, c;
    printf("1. Enter 3 intergers: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("Entered %d, %d and %d.\n\n", a, b, c);

    // q 2 calc square perimeter
    printf("Enter the side of the square(cm): ");
    int s_side;
    scanf("%d", &s_side);
    printf("The square\'s perimeter is %d cm long.\n\n", s_side*4);

    // q3 enter the radius and compute the area
    // use constant macro for PI = 3.14159
    printf("Enter the radius size(cm): ");
    double rad;
    scanf("%lf", &rad);
    double c_area = rad * rad * PI;
    printf("The circle\'s area is %.3lf cm^2.\n\n", c_area);

    return 0;
}