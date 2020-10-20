#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cipher.h"
/* #include "printing.h" */

int main () {
    char* msg = (char*)malloc(17);
    char* hex_str = (char*)malloc(17*2);
    strcpy(msg, "abaaaa");
    int msg_len = strlen(msg);
    printf("\n=============================================\n");
    printf("Start with XOR\n");

    printf("original string:\t%s\n", msg);
    printf("original int:\t\t");
    print_int(msg);
    printf("original hex string:\t");
    print_hex(msg);
    xor_string(msg, msg_len);

    printf("\nXORed int:\t\t");
    print_int(msg);
    printf("XORed hex string:\t");
    print_hex(msg);
    printf("XORed ascii:\t\t");
    print_ascii(msg);
    printf("aaaaaa:\t\t%s\n", msg);

    xor_string(msg, msg_len);
    printf("\nok\n");
    printf("\nrestore string:\t\t%s\n", msg);


    /* free(msg) */;

    printf("\nSimple xor ok\n");
    printf("\n=============================================\n");
    printf("ROT13 Try\n");

    printf("original string:\t%s\n", msg);
    printf("original int:\t\t");
    print_int(msg);
    printf("original hex string:\t");
    print_hex(msg);

    rot47(msg);
    printf("\nshuffled string:\t%s\n", msg);
    printf("original int:\t\t");
    print_int(msg);
    printf("original hex string:\t");
    print_hex(msg);

    rot47(msg);
    printf("\nunshuffled string:\t%s\n", msg);
    
    printf("\n=============================================\n");
    free(msg);

    printf("\nmin: %d", '!');
    printf("\nmax: %d", '~');
    printf("\nhalf: %d", ('~' + '!') /2);

    return 0;
}

