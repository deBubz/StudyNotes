#include "p2_node.h"
#include <iostream>

// Node declaration
Node::Node(std::string data[2]) {
    this->data[0] = data[0];
    this->data[1] = data[1];
}
Node::~Node(){};

std::string *Node::getData() {
    return this->data;
};

void Node::setNext(Node *next) {
    this->next = next;
}

Node *Node::getNext() {
    return this->next;
};


// main
int main() {
    // create empty name list
    Node *head = nullptr;

    // create node 1
    std::string d1[] = {"sand", "which?"};
    Node n1(d1);
    head = &n1;         // add

    // create node 2
    std::string d2[] = {"cheese", "stick"};
    Node * n2 = new Node(d2);
    head->setNext(n2);  // add

    // print
    Node *c = head;
    while(c != nullptr) {
        std::cout << c->getData()[0] << " " << c->getData()[1] << std::endl;
        c = c->getNext();
    }

    delete head->getNext();  // 2nd was created on heap
    head = nullptr;

}