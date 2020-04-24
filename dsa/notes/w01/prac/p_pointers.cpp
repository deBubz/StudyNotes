#include <iostream>

// Exercise understanding pointers

int main() {
    // array
    // int a[] = {1, 2};
    // this will compile and run
    // a[2] will just return the value of the mem next to a[1]
    // std::cout << a[1] << ", "<< a[2] << std::endl;

    // this will not work segmentation fault (core dumped)
    // memory is not allocated for b[1] b[2]
    std::cout << "POINTERS STUFF" << std::endl;
    int b = 3;
    int *b_ptr = &b;
    std::cout << "number: " << b << std::endl;
    std::cout << "pointer: " << b_ptr << std::endl;
    std::cout << "reference: " << *b_ptr << std::endl;
    std::cout << "reference: " << &b << std::endl;

    std::cout << "\nCHANGING" << std::endl;
    *b_ptr = 5;
    std::cout << b << std::endl;
    std::cout << "pointer: " << *b_ptr << std::endl;
    std::cout << "refernce: " << &b << std::endl;
}