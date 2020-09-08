/* simple program to read from file */
#include<stdio.h>

/* prot */
int read_from_file(char filename[]);

int main(void) {
    read_from_file("sample");

    return 0;
}

int read_from_file(char filename[]) {
    FILE *fp = NULL;
    char string1[50];
    char string2[50];
    char string3[50];
    fp = fopen(filename, "r");

    if(fp == NULL) {
        return 1;
    }

    /* fscanf(fp, "%s", string1);
    fscanf(fp, "%s", string2);
    fscanf(fp, "%s", string3); */
    char ch;
    for(ch = fgetc(fp); ch != EOF; ch=fgetc(fp)) {
        printf("%c", ch);
    }
    fclose(fp);

    /* printf("%s %s %s\n", string1, string2, string3); */
    
    return 0;
}