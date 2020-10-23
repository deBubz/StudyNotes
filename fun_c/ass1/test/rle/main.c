/* put your stuff here Drumil */
/*Still Work in progress
Todo: 
-integrate with rest of code.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct Accs{
code
    char word[50];
    char wordenc[100];
    char worddec[50];
};
typedef struct Accs accounts_t;*/

void RLE_Encode(char* word, char* encoded);
void RLE_Decode(char* enc, char* dec);

int main(void){
    char* word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaarff";
    char* encword = (char*) malloc(sizeof(char) * (strlen(word) *2 + 1));
    char* decword = (char*) malloc(sizeof(char) * (strlen(word) *2 + 1));

    printf("%s\n", word);
    RLE_Encode(word, encword);
    printf("%s\n", encword);

    RLE_Decode(encword, decword);
    printf("\n%s\n", decword);

    printf("comparing %d\n", strcmp(word, decword));

    free(encword);
    free(decword);
    return 0;
}

void RLE_Encode(char* word, char* wordenc){
    int length = strlen(word);
    int i, count = 1, j = 0;
    for(i = 0; i < length; i++){
        count = 1;

        /* assign new word */
        while(word[i] == word[i+1] && word[i] != '\0') {
            count++; i++;
        }

        if(word[i]!='\0'){    
            wordenc[j] = count+48;
            wordenc[j+1] = word[i];
            j+=2;
        }

        /* reset word count */
        if(word[i] != word[i+1]) count = 1;
    }
}

void RLE_Decode(char* enc, char* dec){
    int length = strlen(enc);

    int i;
    int n = 0;  /* number pos 0, 2, 4, 6.. */
    int c = 1;  /* char pos 1, 3, 5, 7*/
    int dec_i = 0;
    for (i = 0; i < length/2; i++) {
        int c_num = enc[n] - '0';
        while(c_num != 0) {
            dec[dec_i++] = enc[c];
            c_num--;
        }

        n += 2;
        c += 2;
    }

    dec[dec_i] = '\0';
}