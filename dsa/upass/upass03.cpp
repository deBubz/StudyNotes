#include <iostream>

using namespace std;

void ques06() {
    std::string test;
    std::cin >> test;
    std::cout << test;  
}

void ques07() {
    int a[] = {1};
    cout << a[0] << endl;
    cout << *a << endl;
    int *b = a; cout << *b << endl;
    cout << a << endl;
}

int main() {
    // ques06();
    ques07();
}