/*****************************************************************************
 * YOU SHALL NOT PASS?word
 *
 * Members:
 *  - Bao Hoang
 *  - Zachary Butler
 *  - Drumil Sevak
 *  - Jonno XD
 *
 * Project Description:
 * Bank Administration password management system
 *
 * Last updated: 21 Sept 2020
 *****************************************************************************/

/*******************************************************************************
 * HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*******************************************************************************
 * STRUCTS
 ******************************************************************************/
struct account {
    char* user_id;
    char* password;
    char* email;
    char* pin;
    char account_type;  /* admin, user */
};
typedef struct account account_t;

/*******************************************************************************
 * PREPROCESSING DIRECTIVES
 ******************************************************************************/
#define DB_NAME "database"
#define BIG_ERROR "A major error just occured, please try again or contact the dev team at help@help.help"

/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/
/* HIGH LEVEL PROTOTYPES (to be broken down in later stages)
menu prompt
login/logout prompt (program only accesible by admin)

add/remove account (encrypt new password)
list all passwords (decrypt)
list password by an ID (decrypt)

save to file (compression)
load to file (decompression)
*/
int admin_login(void);
void print_menu(void);

int add_account(void);
int remove_account(void);
int show_password_by_id(void);   // used 
int show_all_passwords(void);

void encode(char* password, int freq);
void decode(char* password, int freq);

/* save load to file (huffman)*/
/* huffman encoding has linkded list, trees, and other nonsense */
int save(void);
int load(void);

/* NOTE: return type/params are currently temporary */

/*******************************************************************************
 * MAIN FUNCTION
 ******************************************************************************/
int main(void) {
    /*int choice;*/
    printf("Hello World\n");

    print_menu();

    return 0;
}


/**
    Fizz buzz, this is for fun
    @param n the number
*/
void fb(const int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(i % 15 == 0) printf("fizzbuzz");
            else if (i % 5 == 0) printf("buzz");
            else if (i % 3 == 0) printf("fizz");
            else printf("%d", i);
    }
    printf("\n");
}

/*******************************************************************************
 * FUNCTION DEFINITION
 ******************************************************************************/


/******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
******************************************************************************/
void print_menu (void){
    printf("Add Account\n");
    printf("Login to Account");
    printf("Remove Password\n");
    printf("List Passwords\n");
}

