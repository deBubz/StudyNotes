#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verif_len(char str[], int min, int max);
int verif_upper(char c);
int verif_number(char c);
int get_c_len(char str[]);

char* get_code();

/* verifying strin */
int main() {
    char str[1000];

    printf("hello: ");
    /* verification */
    strcpy(str, get_code());


    printf("VALID: %s\n", str);
}

/* =================================================================== */
/* =================================================================== */
/* =================================================================== */

char * get_code() {
    char * out;
    char in_str[100];
    scanf("%s", in_str);

    while(!check_code(in_str)) {
        printf("Invalid\n");

        printf("Flight Code>\n");
        scanf("%s", in_str);
    }

    out = &in_str[0];
    return out;
}

int check_code(char str[]) {
    int i;
    int len = strlen(str);

    /* check char length between 3 - 6 */
    if(!check_int_range(len, 3, 6)) {
        printf("LEN\n");
        return 0;
    };
    /* check if char 1 - 2 is upper case */
    for(i = 0; i < 2; i++) {
        if (!verif_upper(str[i])) {
            printf("UPPER\n");
            return 0;
        };
    }
    /* check if char 3 -> len is number */
    for(i = 2; i < len; i++) {
        if (!verif_number(str[i])) {
            printf("NUM %d\n", i);
            return 0;
        }
    }

    return 1;
}


/* 1 valid, 0 not valid */
int check_int_range(int i, int min, int max) {
    return (i >= min && i <= max ) ? 1 : 0;
}

/* 1 is upper, 0 is lower */
int verif_upper(char c) {
    return (c >= 'A' && c <= 'Z') ? 1:0;
}

/* 1 is number, 0 is not number */
int verif_number(char c) {
    return (c >= '0' && c <= '9' && c != '\0') ? 1:0;
}
