#include <iostream>

int main() {
    // array
    int a[] = {1, 2};
    // this will compile and run
    // a[2] will just return the value of the mem next to a[1]
    std::cout << a[1] << ', '<< a[2] << std::endl;

    // this will not work segmentation fault (core dumped)
    // memory is not allocated for b[1] b[2]
    int *b;
    std::cout << b[1] << ', '<< b[2] << std::endl;

}