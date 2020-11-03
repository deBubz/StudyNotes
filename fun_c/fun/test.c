/*  
    req notes:

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_l(int* a, int c) {
    int i;
    for(i = 0; i < c; i++) printf("%d ",*(a+i));

    printf("\n");
}

int main (void) {
    int lim = 5;
    int* a = (int*) malloc (sizeof(int) * lim);
    int c = 0;

    int i;
    for(i =0; i < 10; i++){
        if (c == 3) {
            printf("%p\n", a);
            a = (int*) realloc(a, sizeof(int) * 10);
            printf("%p\n", a);
        }

        scanf("%d", (a + c));
        c++;

        print_l(a, c);
    }
    return 0;
}