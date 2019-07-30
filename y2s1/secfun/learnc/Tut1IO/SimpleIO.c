#include <stdio.h>
#include <stdlib.h>

char* enterText(char *s)
{
    // *s = (char*)malloc(20);
    scanf("%99s", &s);
    return s;
}

int main(void){
    char first[100];
    char last[100];

    printf("Whats your firstname? \n");
    enterText(first);
    printf("Whats your Lastname \n");
    enterText(last);
    printf("Hello %s %s, How are you doing? ", first, last);
    exit(0);
}

