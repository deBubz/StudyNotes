/* testing grabbing 3 chars */

#include <stdio.h>
#include <string.h>

const char * string_thing() {
    char * thingy;
    scanf("%s", thingy);
    return thingy;
}
int main() {
    char thing[3];

    strncpy(thing, string_thing(), 3);
    thing[3] = '\0';

    printf("string: %s\n", thing);
    


    return 0;
}