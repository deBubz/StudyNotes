#include <iostream>

class Node {
    public:
        std::string data[2];
        Node *next;
};


// minimal things used to create a linked list
// difference between using object or 

int main() {
    Node *head = nullptr;

    // item 1 using object
    Node node;
    node.data[0] = "Cheese";
    node.data[1] = "Stick";
    node.next = nullptr;
    head = &node;

    // item 2 using pointer
    Node *node_ptr = new Node();
    node_ptr->data[0] = "sand";
    node_ptr->data[1] = "which?";
    node_ptr->next = nullptr;
    head->next = node_ptr;

    // traversing and printing linked lists
    Node *current = head;

    while(current != nullptr){
        std::cout << current->data[0] << " " << current->data[1] << std::endl;
        if (current->next == nullptr) std::cout << "\n";
        current = current->next;
    }
    
}