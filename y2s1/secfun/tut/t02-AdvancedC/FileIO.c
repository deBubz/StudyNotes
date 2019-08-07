#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ifp, *ofp;
    char username[9];
    int score;

    ifp = fopen("in.list", "r");

    if (ifp==NULL)
    {
        printf("Cant open input file in in.list\n");
        exit(0);
    }

    ofp = fopen("../out.list", "w");
    if (ofp == NULL)
    {
        // theoreticly this will never be triggered because "w" will create the file if it doesnt exist
        printf("Cant open input file in in.list\n");
    }
    
    while (fscanf(ifp, "%s %d", username, &score) ==2)
    {
        fprintf(ofp, "%s %d\n", username, score+10);
    }

    printf("throw a ls to see what appreard");
    fclose(ifp);
    fclose(ofp);
    return 0;
    
}