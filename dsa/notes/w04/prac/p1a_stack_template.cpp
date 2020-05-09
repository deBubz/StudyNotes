#include <iostream>

// -------------- stack.h -------
// #include "stack.h" ofcource import it
template <typename Type>
class stack {
    private:
        Type data[10];
        int size = 0;
    public:
        stack() {};
        ~stack() {};

        void push(Type t) {         // add into stack
            if(this->size != 10) {
                this->data[this->size] = t;
                this->size++;
            } else {
                std::cout << "Stack is full; Push failed!" << std::endl;
            }
        }
        
        void pop() {                // remove elem from top of stack
            if(!this->empty()) this->size--;
        }

        Type top() {                // get top(last in) elem of stack
            return this->data[this->size - 1];
        }

        bool empty() {              // check if stack is empty
            return this->size == 0;
        }
};

// -------------- main ----------
int main() {
    stack<int> s;

    for (int i = 0; i < 12; i++) {
        s.push(i);
    }

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    
    
}