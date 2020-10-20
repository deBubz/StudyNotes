#include "cipher.h"
#include "printing.h"

#include <string.h>

#define ROT_MIN '!'
#define ROT_MAX '~'

void xor_string(char* str, const int len) {
    char xor_key = '=';
    char *key = "aZbY";

    /* int len = strlen(str); */

    int i;
    for(i = 0; i < len; i++) {
        /* printf("%c + %c = %c\n", *(string + i), *(key + i%4), *(string + i) ^ *(key + (i % 4))); */
        *(str + i) = *(str + i) ^ *(key + (i % 4));
    }
}

void rot47(char* str) {
    const char rot_min = '!';
    const char rot_max = '~';

    const int rot_size = (rot_max - rot_min + 1);
    const int rot_half = (rot_size / 2);

    /* roltating */
    int i;
    for(i = 0; *(str+i) != '\0'; i++) {
        int ch;

        ch = *(str+i) + rot_half;
        *(str+i) = (ch > rot_max) ? ch - rot_size : ch;
    }
}

