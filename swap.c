#include<stdio.h>

void swap(int* a, int* b);

int main (void) {
    int a = 1;
    int b = 2;

    printf("pre swap:\t %d %d\n", a, b);
    swap(&a, &b);
    printf("post swap:\t %d %d\n", a, b);

    return 0;
}

void swap(int *a, int* b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}