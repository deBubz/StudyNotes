/* program prints the first letter of a string to a text file */
#include<stdio.h>

/* prot */
int save_to_file(char s1[], char s2[], char filename[]);

int main(void) {
    char line1[] = "line1";
    char line2[] = "line2";
    char File[] = "sample";

    save_to_file(line1, line2, File);

    return 0;
}

int save_to_file(char s1[], char s2[], char filename[]) {

    FILE *fp = NULL;
    fp = fopen(filename, "w");

    /* check error */
    if(fp == NULL) {
        return 1;
    }

    fprintf(fp, "%s\n", s1);
    fprintf(fp, "%s", s2);
    fclose(fp);
    
    return 0;
}