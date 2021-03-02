#include <iostream>

int fac(int);

int main() {
    int a = 5;

    std::cout<< fac(a) << std::endl;
}

int fac(int a) {
    if(a == 1) return 1;
    else return a * fac(a-1);
}