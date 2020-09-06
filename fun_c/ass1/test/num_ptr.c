#include<stdio.h>

/* void add(int*);
void less(int*); */
int add(int);


int main() {
    int num = 0;
    int input;

    while(1) {
        printf("what do %d\n1.add\n2.less\n", num);
        scanf("%d", &input);

        if(input == 1) num = add(num);
        /* if(input == 2) less(&num); */
    }
    return 0;
}

int add(int i) {
    return ++i;
}
/* void less(int *i) {
    *i--;
} */