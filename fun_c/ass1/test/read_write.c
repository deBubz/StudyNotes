/* simple program to read from file */
#include<stdio.h>

/* prot */
int save_to_file(char[], char[]);
int read_from_file(char filename[]);

int main(void) {
    char line1[] = "line1";
    char file[] = "sample_binary";
    
    printf("savign\n");
    save_to_file(line1, file);
    printf("reading\n");
    read_from_file(file);

    return 0;
}

int save_to_file(char line[], char file[]) {
    FILE *fp = NULL;
    fp = fopen(file, "wb");

    /* check errors */
    if(fp == NULL) {
        return 1;
    }

    fwrite(line, 1, 5, fp);
    fclose(fp);

    return 0;
}


int read_from_file(char filename[]) {
    FILE *fp = NULL;
    char string1[50];
    fp = fopen(filename, "rb");

    if(fp == NULL) {
        return 1;
    }

    /* can use both
    fscanf(fp, "%s", string1);
    fread(string1, 1, 5, fp);
    */

    char ch;
    for(ch = fgetc(fp); ch != EOF; ch=fgetc(fp)) {
        printf("%c", ch);
    } 

    printf("%s\n", string1);
    fclose(fp);

    return 0;
}