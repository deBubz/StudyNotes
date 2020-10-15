#include <stdio.h>
#include <string.h>
#include "link1.h"

void picking(int* choice) {
    printf("Select a choice ");
    scanf("%d", choice);
}

int main() {
    int list[5];


    int i;
    for(i = 0; i<5; i++) {
        list[i] = i+3;
    }

    for(i = 0; i<5; i++) {
        printf("%d\n", list[i]);
    }
    printf("\n");

    /* remove index 2 */
    for(i = 4; i<5-1; i++) {
        list[i] = list[i+1];
    }

    for(i = 0; i<4; i++) {
        printf("%d\n", list[i]);
    }
    printf("\n");




    return 0;
}

