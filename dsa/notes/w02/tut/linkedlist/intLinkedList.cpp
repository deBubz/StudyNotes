#include "intLinkedList.h"

// inNode Definition
intLinkedList::intNode::intNode() {

}

intLinkedList::intNode::intNode(intNode *n, int data) {
    this->next = n;
    this->data = data;
}

intLinkedList::intNode::~intNode() {
    // destructor leave it
}

int intLinkedList::intNode::getData() {
    return this->data;
}

intLinkedList::intNode* intLinkedList::intNode::getNext() {
    return this->next;
}
void intLinkedList::intNode::setNext(intNode *next) {
    this->next = next;
}

// intLinkedList definition
intLinkedList::intLinkedList() {
    this->length = 0;
}
intLinkedList::~intLinkedList() {
    // destructor leave it
}

bool intLinkedList::isEmpty() {
    return (this->head == NULL);
}
void intLinkedList::prepend(int c) {
    intNode *node = new intNode(NULL, c);
    node->setNext = this->head;
    this->head = node;
}
// not working
void intLinkedList::append(int c) {

}
int intLinkedList::getHead() {

}
intLinkedList* intLinkedList::tail() {

}


int main() {

}