#ifndef P2_NODE_H
#define P2_NODE_H

#include <iostream>

class Node {
    private:
        std::string data[2];            // first, last
        Node * next;
    public:
        Node(std::string data[2]);
        ~Node();

        std::string * getData();             // return name?
        void setNext(Node * next);      // set next in linked list
        Node * getNext();               // get next in linked list
};

#endif