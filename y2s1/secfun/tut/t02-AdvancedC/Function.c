#include <stdlib.h>
#include <stdio.h>

// declaring function
int multi(int x, int y);

int main()
{
    int a,b;

    printf("Please enter 2 numbers to be multiplied");
    scanf("%d %d",&a, &b);
    printf("Resuslt is %d",  multi(a, b));
    return 0;
}

int multi(int x, int y)
{
    return x*y;
}