#include <stdlib.h>;

char* receiveInput( char *s ){
    scanf("%99s",s);
    return s;
}
int main()
{
    char str[100];
    receiveInput( str );
    int length = strlen(str);

    printf("Your string is %s, length is %d\n", str, length);

    return 0;
}