#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,input;

    printf("Please enter 2 numbers");
    scanf("%d %d", &a, &b);
    printf("Select 1 for Addtion\nSelect 2 for Subtraction\nSelect 3 for Multiplication\nPlease make a selection: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("%d + %d = %d", a, b, (a+b));
        break;
    case 2:
        printf("%d - %d = %d\n", a, b, (a-b));
        break;
    case 3:
        printf("%d * %d = %d", a, b, (a*b));
        break;
    default:
        printf("Bad input\nTerminating");
        break;
    }
    return 0;
}