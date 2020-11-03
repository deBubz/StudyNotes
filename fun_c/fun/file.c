/*  
    req notes: text file

    main call a function do prior value in text file
    start with empty file
    each line has 1 balue

    > use dynamic memory

    self defined function
    ask to input each time
    - if value exist in anyline, prioritise it by swap value ahead of it
    - if value = first value keep the same
    - not exist add new line

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOFT_LIMIT 5
#define HARD_LIMIT 10

/*--------------------------------prototypes----------------------------------*/

void get_valid_input(int * in);
void set_priority(int** data, int* count);

int check_exist(int* data, int value, int count);
int add_new(int** data, int value, int* count);

void save(int* data, const int count);
void print_list(int* data, int count);


/*--------------------------------main----------------------------------------*/
int main (void) {
    int count = 0;
    int* data = (int*) malloc(sizeof(int) * SOFT_LIMIT);

    if (data == NULL) {
        printf("malloc error.\n");
        return 0;
    }

    set_priority(&data, &count);
    print_list(data, count);

    free(data);
    data = NULL;
    return 0;
}

/*--------------------------------function definitions------------------------*/
/* get new input and validate it */
void get_valid_input(int* in) {
    char* buffer = (char*) malloc(sizeof(char) * 20);
    int flag = 1;

    while(flag) {
        printf("next :");scanf("%s", buffer);
        /* check len */
        int len = strlen(buffer);
        if (len > 3 ) {
            printf("invalid input. try again.\n");
            continue;
        }
        /* check correct */
        int i, f = 0;
        for(i = 0; i < len; i++) {
            if(buffer[i] < '0' || buffer[i] > '9') {
                printf("invalid input. try again.\n");
                f = 1;
            }
        }
        if(f) continue;

        /* check range */
        int check = atoi(buffer);
        if(check < 0 || check > 100) {
            printf("invalid input. try again.\n");
            continue;
        }

        /* all test pass */
        *in = check;
        flag = 0;
    }

    free(buffer);
    buffer = NULL;
}

/* the self main defined function */
void set_priority(int** data, int* count) {
    /* get input */
    int in;

    get_valid_input(&in);
    while (in != 0) {
            /* check exist */
            int index = check_exist(*data, in, *count);
            if(index != -1){
            /* first do nothing */
            /* exist move up 1 space */
            if(index != 0) {
                int tmp = *(*data + index);
                *(*data + index)  = *(*data + index -1);
                *(*data + index - 1) = tmp;
            }

            } else {
                printf("pre add %p\n", *data);
                add_new(data, in, count);
                printf("post add %p\n", *data);
            }

            printf("presave OK\n");

            print_list(*data, *count);
            save(*data, *count);

            get_valid_input(&in);
    }
}

/* check new entered number exist exist */
int check_exist(int* data, int value, int count) {
    int i;
    for(i = 0; i < count; i++) {
        if(*(data+i) == value) return i;
    }

    return -1; /* not exist */
}

/* add new value into list */
/* 0 fail, 1 success */
int add_new(int** data, int value, int* count) {
    if(*count == 10) {
        printf("add failed, reach max memory limit");
    } else {

        if(*count == SOFT_LIMIT) {
            *data = (int*) realloc(*data, sizeof(int) * HARD_LIMIT);
            if(data == NULL) return 0;
        }
        
        *(*data + *count) = value;
        *count = *count + 1;
    }

    return 1;
}

/* save to file */
void save(int* data, const int count) {
    FILE *fp = NULL;
    fp = fopen("file", "w");

    if(fp == NULL) {
        printf("write error\n");
        return;
    }

    int i;
    for(i = 0; i < count; i++) {
        fprintf(fp, "%d\n", *(data + i));
    }

    fclose(fp);
}

/* print the list at the end when 0 is entered */
void print_list(int* data, int count) {
    int i = 0;
    for(i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}