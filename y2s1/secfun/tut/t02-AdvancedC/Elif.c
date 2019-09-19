#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;

    printf("please enter your age: ");
    scanf("%d", &age);

    if (age < 60)
    {
        printf("what a baby"); 
    }
    else if (age == 60)
    {
        printf("big boy over here"); 
    }
    else
    {
        printf("Why arent you dead yet");
    }
    
    return 0;
}
