/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:

to show how to use command line arguments. write a program that has two modes of
operation. two modes are defined by a command line flags:
    -a : mode a
    -b : mode b
If a mode has not been specified by the user or an invalid mode has been
specified, print an error message.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    /* argc - count of seperate string typed on the CLI including the program name */
    /* argv[] - char pointer array, hold all the string including the program name */

    int i;
    


    if(argc == 1) {
        /* normal start not cli mode */
        printf("not cli mode\n");

    } else {
        printf("cli mode\n");
        /* cli modes */ 

        /* 3 modes */
        if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
            /* help -h or --help */
            printf("help flag\n");
        } else if (!strcmp(argv[1], "-c") || !strcmp(argv[1], "--count")) {
            /* view numer of saved accounts in database -c or --count */
            printf("view number of accounts\n");
        } else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--view")) {
            if(argc != 4) {     /* else invalid command, please run with flag -h or --help for instructions */
                printf("invalid use of flag -v/--view.\nPlease use -h/--help for instructions\n");
            } else {            /* quick view password -v --view */
                printf("correct use of view flag\n");
                printf("uname: %s\n", argv[2]);
                printf("pin: %s\n", argv[3]);
            }
        }
        else {
            printf("wrong flags\n");
        }

    }

/* ok this looks good */
/* launch mode */


    return 0;
}