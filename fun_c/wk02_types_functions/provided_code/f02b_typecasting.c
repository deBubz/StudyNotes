/*******************************************************************************
Introduce integer division and casting. Program to calcualte the average mark
in the class.
*******************************************************************************/

#include <stdio.h>

int main(void)
{
    int    total_score, num_students;
    double average;

    /* input */
    printf("Enter sum of students' scores> ");
    scanf("%d", &total_score);

    printf("Enter number of students> ");
    scanf("%d", &num_students);

    /* output */
    average = (double) total_score / num_students; /* type cast using the (double) keyword in the equasion */
    printf("Average score is %.2f\n", average);
    return (0);
}