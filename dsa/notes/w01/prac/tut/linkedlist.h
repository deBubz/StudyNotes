#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "baselist.h"

class LinkedList : public BaseList
{
    private:
        class Node
        {
            public:
                int data;
                Node *next;

                Node(int d, Node *next);
                ~Node();
        };

        Node *head;

    public:
        LinkedList();
        ~LinkedList();

        void prepent(int d);
        void append(int d);
        void display();
};

#endif