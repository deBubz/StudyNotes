#include<stdio.h>
#include<stdlib.h>


typedef struct {
    int wan;
} retarded_t;

void swap (retarded_t*, retarded_t*);

int main() {

     
    retarded_t *array = (retarded_t*) malloc(sizeof(retarded_t*) * 2);  

    /* array[0].wan = 3;
    array[1].wan = 5; */
    (array + 0)->wan = 3;
    (array + 1)->wan = 5;

    printf("ob1 %d\n", array[0].wan);
    printf("ob2 %d\n", array[1].wan);

    swap(array, array + 1);

    retarded_t* y;



    /* did not swap pointers */

    printf("\n");
    printf("ob1 %d\n", array[0].wan);
    printf("ob2 %d\n", array[1].wan);

    printf("thing \n");


    return 0;
}


void swap (retarded_t* a, retarded_t* b) {
    retarded_t temp;

    /* pointer swap */

    printf("\n");
    printf("%d %d\n", a->wan, b->wan);

    temp = *a;
    *a = *b;
    *b = temp;

    printf("\n");
    printf("%d %d\n", a->wan, b->wan);

    /* only value was swapped */
}