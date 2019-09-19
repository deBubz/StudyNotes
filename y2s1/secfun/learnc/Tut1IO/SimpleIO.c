#include <stdio.h>
#include <stdlib.h>

char* enterText()
{
    char *s = (char*) malloc( 100 );
    scanf("%s",s);
    return s;
}

int main(){
    char *first = enterText();
    char *last = enterText();
    printf("Hey hey %s %s, Whats going on? ", first, last);
    exit(0);
}

