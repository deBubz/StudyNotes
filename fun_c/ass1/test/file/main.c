#include <stdio.h>
#include <stdlib.h>

#define FNAME "filename.bin"

int save();
int load();

typedef struct data {
    int d1;
    int d2;
} data_t;


int main() {

    if(save()) {
        printf("Save error\n");
        return 1;
    }

    if(load()) {
        printf("Read error\n");
        return 1;
    }

    return 0;
}

int save() {
    FILE* fp = NULL;
    fp = fopen(FNAME, "w");

    if (fp == NULL) {
        fclose(fp); return 1;
    }

    data_t lists[2];
    lists[0].d1 = 3;
    lists[0].d2 = 4;

    lists[1].d1 = 4;
    lists[1].d2 = 3;

    /* int list[] = { 1, 2, 3, 4, 5 }; */
    int list_size = sizeof(lists)/sizeof(lists[0]);
    printf("writing %ld/%ld = %d", sizeof(lists), sizeof(lists[0]), list_size);

    fwrite(&list_size, sizeof(list_size), 1, fp);
    fwrite(lists, sizeof(lists), 1, fp);
    /* fwrite(b, sizeof(b), 1, fp); */

    fclose(fp);
}

int load() {
    FILE* fp = NULL;
    fp = fopen(FNAME, "r");

    if (fp == NULL) {
        fclose(fp); return 1;
    }

    /* get size of array */
    int size;
    fread(&size, sizeof(size), 1, fp);
    printf("%d\n", size);
    /* get array using size? */
    data_t lists[size];
    printf("reading size: %ld\n", sizeof(int));
    fread(lists, sizeof(data_t), size, fp);
    /* fread(b, 20, 1, fp); */

    /* printf("read %d\n", list); */
    /* printf("b %s\n", b); */

    /* int arr_size = sizeof(list)/sizeof(list[0]); */
    int i;
    for(i = 0; i < size; i++) {
        printf("%d %d\n", lists[i].d1, lists[i].d2);
    }

    fclose(fp);
}