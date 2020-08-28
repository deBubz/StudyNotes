/* simple program that 
takes in 2 ints input
output a rational number */

#include <stdio.h> /* printf, scanf */

/* prototype */
int get_quotient(const int, const int);
int get_remainder(const int, const int);

/* main */
int main(void) {
    int a, b;

    /* input */
    printf("Enter 2 int: ");
    scanf("%d%d", &a, &b);

    /* calculation and output */
    printf("%d/%d = ", a, b);
    if (a < b) { /*  numerator < denominator */
        printf("%d/%d\n" , a, b);
    } else {
        printf("%d %d/%d\n", get_quotient(a, b), get_remainder(a, b), b);
    }

    return 0;
}

/**
 * return result of int a/ int b
 * @param a int 
 * @param b int
 * @return int a/ int b
 */
int get_quotient(const int a, const int b) {
    return a/b;
}

/**
 * return value of a % b
 * @param a mod this thing
 * @param b with this thing
 * @return value a % b
 */
int get_remainder(const int a, const int b) {

    return a%b;
}