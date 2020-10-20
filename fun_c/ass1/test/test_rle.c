#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DB_name "Database"


/*void DB_write(int count2, char word[], int i);*/
char RLE(char word[]);



int main(){
    char word[] = "Yeeteetaaaf"; 
    char word_enc[50];
    int count2;
    RLE(word); 

    printf("%d\n", count2);
    return 0;
}

char RLE(char word[]){
    /* char wordenc[50]; */
    int length = strlen(word);
    int i, j, k;
    int count = 1,  count2;

    for(i = 0; i < length; i++){
        count2 = 1;
            if(word[i] == word[i+1] && word[i] != ' '){
                count2++;
                count++;
                word[i+1] = '0';

            }else if(word[i] != word[i+1]){
                count2 = 1;
            }
        if(word[i]!='0'){    
            printf("%d%c", count2, word[i]);
            /* wordenc[i] = word[i]; */
        }
    }

    return count2/* , wordenc[i] */;
}