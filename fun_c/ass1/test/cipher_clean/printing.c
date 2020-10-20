#include "printing.h"
#include <stdio.h>

void print_hex(char* str) {
    int i = 0;
    for(i = 0; *(str + i) != '\0'; i++) {
        printf("%d ", *(str+i));
    }
    printf("\n");
}

void print_int(char* str) {
    int i = 0;
    for(i = 0; *(str + i) != '\0'; i++) {
        printf("%02X ", *(str+i));
    }
    printf("\n");
}

void print_ascii(char* str) {
    int i = 0;
    for(i = 0; *(str + i) != '\0'; i++) {
        if(*(str+i) <= 32) {
            printf("%d ", *(str+i));
        } else printf("%c ", *(str+i));
    }
    printf("\n");
}



