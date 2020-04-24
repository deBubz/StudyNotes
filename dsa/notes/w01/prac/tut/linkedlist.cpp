#include <iostream>
#include "linkedlist.h"

// implementation

LinkedList::Node::Node(int d, Node *next)
{
    this->data = d;
    this->next = next;
}

LinkedList::Node::~Node(){}

// ----------------------------

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
    //     while(this->head != nullptr){
    //     Node* temp = this->head;
    //     this->head = this->head->next;
    //     delete temp;
    // }
    
    // std::cout << "Linked list deteled!" << endl;
}

void LinkedList::append(int d)
{

}
void LinkedList::prepend(int d)
{

}
void LinkedList::prepend()
{

}
