/* 
factorial recursive
*/

int fac(const int);

int main(void) {
    int input;

    /* input */
    print("enter n: ");
    scanf("%d", &input);

    /* output */
    printf("%d! = %d\n", input, fac(input));

    return 0;
}

int fac(const int n) {
    if (n <= 1) return 1;
    else return n * fac(n - 1);
}