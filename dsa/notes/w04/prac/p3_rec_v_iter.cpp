#include <iostream>


// comparing recurtion with iteration
// calculating factorial

// iterative
unsigned long long factorial (unsigned long long n){
    unsigned long long l = 1LL;       // litteral

    for (auto i = 2; i <= n; i++)
    {
        l = l * i;
    }
    return l;
}

// recursive
unsigned long long factorial_rec (unsigned long long n){
    if ( n == 1 ) return n;
    else return factorial_rec(n - 1) * n;
}

// main
int main() {
    unsigned long long n = 5;
    // std::cout << "Input Integer: " << std::endl;
    // std::cin >> n;

    std::cout << factorial(n) << std::endl;
    std::cout << factorial_rec(n) << std::endl;
}
