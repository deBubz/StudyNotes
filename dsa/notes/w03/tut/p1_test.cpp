#include <iostream>
#include "node.h"

// minimal things used to create a linked list
// difference between using object or 

int main() {
    Node *head = nullptr;

    // item 1 object
    Node node;
    node.data[0] = "Cheese";
    node.data[1] = "Stick";
    node.next = nullptr;
    head = &node;

    // item 2 ptr
    Node *node_ptr
}