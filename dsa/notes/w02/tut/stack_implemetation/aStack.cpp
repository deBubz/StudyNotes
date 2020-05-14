#include <iostream>
#include "aStack.h"

// AStack :: Node implementation
AStack::Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

AStack::Node::~Node() {}

// AStack implementation
AStack::AStack(){
    this->head = nullptr;
}

AStack::~AStack(){}

bool AStack::empty(){
    return (this->head ==  nullptr);
}

int AStack::top(){
    return this->head->data;
}

void AStack::push(int data){
    Node* n = new Node(data, this->head);
    this->head = n;
}
void AStack::pop(){
    if(!this->empty()){
        std::cout << "Remove " << this->top() << std::endl;
        this->head = this->head->next;
    }
}
void AStack::display(){
    if(this->empty()){
        std::cout << "empty stack\n";
    }
}