#include <iostream>

// ========= stack.h    ==========

// declaring template
template <typename T>
class stack {
    private:
        T data[10];
        int size = 0;
    public:
        stack() { };
        ~stack() {};

        void push(T t) {    // first in
            this->data[this->size] = t;
            this->size++;
        };

        T pop() {           // last out
            T elem = this->data[this->size - 1];
            this->size--;
            return elem;
        };

        bool empty() {
            return size == 0;
        };
};

// ========= main class ==========

// #import <iostream>
// #include "stack.h"

int main () {
    stack<int> s;

    for (int i = 0; i < 10; i++) {
        if(i < 7)   s.push(i);  // add into stack
        else s.pop();    // remove from stack
    }

    std::cout << "Loop ended" << std::endl;

    // print stack
    while(!s.empty()) {
        std::cout << s.pop() << std::endl;
    }
}

//  try to compute the output on paper