#include<stdio.h>

struct student{
    int score;
    char grade;
};
typedef struct student student_t;

int main(int argc, char const *argv[])
{
    student_t a, b;
    a.score = 10;
    a.grade = 'A';
    b.score = 10;
    b.grade = 'A';

    if(a.grade == b.grade) puts("lmao");



    return 0;
}
