// simple program to test the scanf function

#include <stdio.h>

int main(void) {
    int i;
    int a, b;

    // alright this doesnt work, it'll assign gibberish to i
    // scanf("enter a number: %d", &i);

    // ----------------------------------------------

    // stick to this solution
    // printf("Enter a number: ");
    // scanf("%d", &i);
    // printf("the number is: %d\n", i);

    // ----------------------------------------------

    // multiple inputs
    // alright so the text stream thing
    // either have 2 inputs seperated by a space or a carriage_return
    printf("\nEnter 2 numbers: ");
    scanf("%d%d", &a, &b);
    printf("First:\t%d\nSecond:\t%d\n", a, b);
    // because of the place holder %d
    // the program will ignore any char that doesnot fit the data type/ and use that as a seperator for the next variable

    return 0;
}

