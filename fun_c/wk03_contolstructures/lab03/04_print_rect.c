/* 
print a rectangle based on provided size
*/

#include <stdio.h>

int main() {
    int row = 5,
        col = 10;

    int i;
    for(i = 0; i < row; i++) {
        int j;
        for(j = 0; j < col; j++) {
            printf("+ ");
        }
        printf("\n");
    }
}