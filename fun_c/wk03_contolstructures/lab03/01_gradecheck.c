/* 
program displays message grade
depends on the entered chat

bunch of else ifs
*/

#include <stdio.h> /* printf, scanf */

/* prototypes */
void print_mark(const int);

/* main */
int main(void) {
    int mark;

    /* input */
    printf("what is your mark: ");
    scanf("%d", &mark);

    /* output */
    print_mark(mark);
    return 0;
}

/**
 * returns a grade msg depending on the entered grade
 * @param int grade
 * @return corresponding msg based on the grade
 */
void print_mark(const int mark) {
    if(mark < 0)
        printf("%d\t: Impossible, check the input again.\n", mark);
    else if (mark < 50)
        printf("%d\t: Z - Pity you failed, try harder next time.\n", mark);
    else if (mark < 101)
        printf("%d\t: P - Congratulations, way to go.\n", mark);
    else
        printf("%d\t: Too awesome for the class, check the input again.\n", mark);
}