#include <iostream>
#include "linkedList.h"

linkedList::Node::Node(int d, Node *n){
    this->data = d;
    this->next = n;
}

linkedList::Node::~Node(){}
linkedList::linkedList(){}
linkedList::~linkedList(){}