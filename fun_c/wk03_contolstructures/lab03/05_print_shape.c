/* 
print this shape

* 
* * 
* * * 
* * * * 
* * * * 
* * * * 
* * * * 
* * * 
* * 
*

*/
#include <stdio.h>

void upper();
void middle();
void lower();

int main(void) {
    upper();
    middle();
    lower();

    return 0;
}

void upper() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void middle() {
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

/* i broke it prob ceebs fixing it */

void lower() {
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 3; j < j-i; j--) {
            printf("* ");
        }
        printf("\n");
    }
}