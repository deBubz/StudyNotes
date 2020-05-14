#ifndef INTLINKEDLIST_H_
#define INTLINKEDLIST_H_

#include <cstddef>
#include <string>

#include "intList.h"

using std::string;

class intLinkedList : public intList {
    private:
        class intNode {
            private:
                intNode* next;
                int data;
            public:
                intNode();
                intNode(intNode* next, int data);
                ~intNode();     // destructor
                int getData();
                intNode* getNext();
                void setNext(intNode *next);
            };
        intNode* head;
        std::size_t length;     // unsigned int used to indicate size
    public:
        intLinkedList();
        ~intLinkedList();
        bool isEmpty();
        void prepend(int c);
        void append(int c);
        int getHead();
        intLinkedList* tail();
};

#endif