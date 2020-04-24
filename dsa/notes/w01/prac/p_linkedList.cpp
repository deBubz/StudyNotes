#include <iostream>
#include "p_linkedList.h"

// exercises on header files
// implementing a linked list

// ================= NODE ===================
linkedList::Node::Node(){}
linkedList::Node::~Node(){}

// ============== LinkedList ================

linkedList::linkedList()
{
    this->length = 0;
    this->head = nullptr;
}
linkedList::~linkedList()
{
    std::cout << "List Deleted" << std::endl;
}

void linkedList::prepend(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = this->head;
    
    this->head = newNode;
    this->length++;
}

void linkedList::append(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = nullptr;

    Node *node = this->head;
    while(node->next != nullptr)
    {
        node = node->next;
    }
    node->next = newNode;
    this->length++;
}

int linkedList::size()
{
    return this->length;
}

void linkedList::display(){
    Node *node = this->head;
    for (int i = 0; i < this->size(); i++)
    {
        std::cout << node->data << std::endl;
        if(i < this->size()) node = node->next;
    }
    
}

// ============= MAIN ================

int main()
{
    linkedList *list = new linkedList();

    for (int i = 0; i < 6; i++)
    {
        if(i < 3) list->prepend(i);
        else list->append(i);
    }

    list->display();
    std::cout << "List Length: " << list->size() << std::endl;

    delete list;
    return 0; 
}






