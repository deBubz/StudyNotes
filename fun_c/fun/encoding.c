/*  
    req notes: encoding/decoding chars

    all lowercase
    map a->1 , b->2 ... z->26

    @INPUT 4 digit character
    @OUTPUT all possible string seperated by space

    valid:  1 possible string
            valid 4 char 0-9

    more note: 
        0000 invalid
        5 possibilities
            abcd - ab cd - a b cd - ab c d - a bc d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_OFFSET 96

/*----------------------------------------------------------------------------*/

int get_valid_input(char* input);
int format_validate(char* input);

void perm1(char* in);
void perm2(char* in);
void perm3(char* in);
void perm4(char* in);
void perm5(char* in);

int one_dig(char c);
int two_dig(char c1, char c2);

void print_decoded(char* input);

/*----------------------------------------------------------------------------*/
int main (void) {
    char input[20]; /* 20 char buffer */

    if(get_valid_input(input)) {
        print_decoded(input);
    } else {
        printf("\nterminating: invalid input\n");
    }
    
    return 0;
}

/*----------------------------------------------------------------------------*/

void print_decoded(char* input) {
    printf("input: %s\n", input);

    perm1(input);
    perm2(input);
    perm3(input);
    perm4(input);
    perm5(input);

    printf("\n");
}

/* a b c d */
void perm1(char* in) {
    int i, c, valid  = 1;
    char str[4];

    for (i = 0; i < 4; i++) {   /* check valid */
        c = one_dig(in[i]);
        if (c < 1) valid = 0;

        if (valid) str[i] = c+C_OFFSET;
    }
    
    if(valid) printf("%s ", str);
}

/* ab cd */
void perm2(char* in) {
    int c1 = two_dig(in[0], in[1]), 
        c2 = two_dig(in[2], in[3]), 
        valid = 1;

    if (c1 > 26 || c2 > 26) valid = 0;

    if (valid) printf("%c%c ", c1+C_OFFSET, c2+C_OFFSET);
}

/* a bc d */
void perm3(char* in) {
    int c1 = one_dig(in[0]),
        c2 = two_dig(in[1], in[2]), 
        c3 = one_dig(in[3]);
    int valid = 1;

    if (c1 < 1 || c3 < 1 || c2 > 26) valid = 0;

    if (valid) printf("%c%c%c ", c1+C_OFFSET, c2+C_OFFSET, c3+C_OFFSET);
}

/* ab c d */
void perm4(char* in) {
    int c1 = two_dig(in[0], in[1]),
        c2 = one_dig(in[2]), 
        c3 = one_dig(in[3]);
    int valid = 1;

    if (c1 > 26 || c2 < 1 || c3 <1) valid = 0;

    if (valid) printf("%c%c%c ", c1+C_OFFSET, c2+C_OFFSET, c3+C_OFFSET);
}

/* a b cd */
void perm5(char* in) {
    int c1 = one_dig(in[0]),
        c2 = one_dig(in[1]), 
        c3 = two_dig(in[2], in[3]);
    int valid = 1;

    if (c1 < 1 || c2 < 1 || c3 > 26) valid = 0;

    if (valid) printf("%c%c%c ", c1+C_OFFSET, c2+C_OFFSET, c3+C_OFFSET);
}

/* get 1 digit int*/
int one_dig(char c) {
    return c - '0';
}
/* get 2 digit int */
int two_dig(char c1, char c2) {
    return 10*(c1 - '0') + (c2 - '0');
}


/*----------------------------------------------------------------------------*/
/* 1 valid, 0 fail */
int get_valid_input(char *input) {
    printf("please enter a 4 digit number: ");
    scanf("%s", input);

    if (format_validate(input)) {
        if(!strcmp(input, "0000")) return 0;

        return 1;
    } else return 0;

}

/* 1 valid 0 fail */
int format_validate(char* input) {
    if (strlen(input) != 4) return 0;

    int i;
    for(i = 0; i < 4; i++) {
        if(input[i] < '0' || input[i] > '9') return 0;
    }
    
    return 1;
}