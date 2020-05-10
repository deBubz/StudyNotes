#include <iostream>

int fib(long n) {
    long out = 1;
    long prev = 0;
    
    for (int i = 0; i <= n; i++)
    {
        long tmp = out;
        out = out + prev;
        prev = tmp;
    }

    return out;
}

int fib_rec(long n) {
    if (n == 0) return 0;
    if(n == 1) return 1;
    else return fib_rec(n - 1) + fib_rec(n - 2);
}

// main
int main() {
	long n;
	std::cout << "Enter a number:" << std::endl;
	std::cin >> n;

	std::cout << fib_rec(n) << std::endl;
    std::cout << fib(n) << std::endl;
}