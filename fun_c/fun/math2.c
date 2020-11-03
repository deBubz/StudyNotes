/*  
    req notes:
    @return: for all ints >= 2 &&  <= 100

    N = 2^a * 3^b * 5^c * M
    - a,b,c ints, BUT 1 is != 0
    - M positive int
    - 2 <= N <= 100

    for each N



    more notes: 

*/

#include <stdio.h>
#include <math.h>

/* easy way */
/* const int prime_list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; */

void print_matching(const int N, int* P);
void set_values(const int N, int* a, int* b, int* c, int *M);
int check_req(const int N);

void set_new_largest_prime (const int i, int* prev_p);
int check_prime(const int i);

int main (void) {
    int largest_p = 2;

    int i; 
    for (i = 2; i <= 100; i++){ /* each N */
        print_matching(i, &largest_p);
    }

    printf("\nOnly P is working\n");
    
    return 0;
}

void print_matching(const int N, int* P) {  /* each N */
    int a = 0, 
        b = 0, 
        c = 0;
    int M = 0;

    set_new_largest_prime(N, P);

    if (check_req(N)) {
        /* printf("==%d======\n", N); */
            /* set_values(N, &a, &b, &c, &M); */

        /* int x = N;
        printf("%d\n",x); */

/*         while(x != 1) {
            if (x%5 == 0) {
                x /= 5;
                c++;
            }

            if (x%3 == 0) {
                x/= 3;
                b++;
            }

            if (x%2 == 0) {
                printf("mod2\n");
                x /= 2;
                a++;
            }

            printf("- %d\n", x);
        } */

        /* printing result */
        printf("%d = 2^%d x 3^%d x 5*%d * %d, P = %d\n", N , a, b, c , M, *P);
    }

    
}



/*
    supposedly this is to get each permutation of a, b, c, M
*/
void set_values(const int N, int* a, int* b, int* c, int *M) {
    if (N % *M == 0) {
        int without_m = N /(*M);
        printf("%d / %d = %d\n", N, *M, without_m);
    }
}

/* at least one in a,b,c != 0 */
int check_req(const int N) {
    if (N % 2 == 0 || N % 3 == 0 || N % 5 == 0)
        return 1;
    
    return 0;
}

/* set new largest prime */
void set_new_largest_prime(const int N, int* prev_p) {
    int p;
    for (p = (*prev_p) + 1; p <= N; p++) {
        if(check_prime(p)) {
            if(p > *prev_p) *prev_p = p;
        }
    }
}

/* check if int is prime or not 0 fail, 1 false */
int check_prime(const int i) {
    int j;
    for (j = 2; j <= i - 1; j++) {
        /* not prime */
        if (i % j == 0) return 0;
    }

    /* prime */
    if (i == j) return 1;

    return 0;

}
