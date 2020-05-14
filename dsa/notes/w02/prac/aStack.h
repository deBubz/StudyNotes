#ifndef ASTACK_H_
#define ASTACK_H_

#include "baseStack.h"

// define data structure
class AStack : public BaseStack {
    private:
        class Node {
            public:
                int data;
                Node* next;

                Node(int data, Node* next);
                ~Node();
        };
        Node* head;
    public:
        AStack();
        ~AStack();

        bool empty();
        int top();
        void push(int data);
        void pop();
        void display();
};

#endif