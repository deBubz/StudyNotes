/* test the different infinite input pattern */

#include <stdio.h>

void get_input(int* in) {
    printf("Enter input: ");
    scanf("%d", in);
}

int main() {
    int input;

    for(get_input(&input); input != 0; get_input(&input)) {
        printf("I got %d\n", input);
    }

    return 0;
}

/* yeah lets use this for the project */