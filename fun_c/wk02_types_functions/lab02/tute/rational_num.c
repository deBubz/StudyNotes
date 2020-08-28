/*
A simple program that ask for 2 int inputs and outputs a rational number
*/
#include <stdio.h> /* printf, scanf */

/* prototype */

int get_quotient(const int a, const int b);
int get_remainder(const int a, const int b);

/* main fucntion */
int main(void)
{
    int num, dem;
    int quot, remainder;

    printf("Enter the numerator and denominator separated by a space> ");
    scanf("%d%d", &num, &dem);

    /* output */
    printf("%d/%d = ", num, dem);
    if(num < dem)
    {   /* if the quotient == 0 */
        printf("%d/%d", num, dem);
    }
    else
    {
        quot = get_quotient(num, dem);
        remainder = get_remainder(num, dem);
        printf("%d %d/%d", quot, remainder, dem);
    }
    printf("\n");

    return 0;
}


/**
 * This function calculates the quotient between numberator and denominator
 * 
 * @param num value for the numberator
 * @param dem value for the denominator
 * @return quotient value of numberator/denominator
 */
int get_quotient(const int a, const int b)
{
    return a/b;
}

/**
 * This function calculates the remainder of a/b
 * 
 * @param a value 
 * @param b value 
 * @return remainder of a and b
 */
int get_remainder(const int a, const int b)
{
    return a%b;
}