#ifndef INTLINKED_H_
#define INTLINKED_H_

#include <cstddef>
#include <string>

#include "./intlist.h"

using std::size_t;
using std::string;

class intLinked : public intList {
    private:
        class intNode {
            private:
                intNode * next;
                int data;
            
            public:
                // const
                intNode();
                intNode(intNode * next, int data);
                // destructor
                ~intNode();

                // functions
                int getData();
                intNode * getNext();
                void setNext(intNode * data);
        };

        intNode* head;
        size_t length;

    public:
        // const
        intLinked();
        // destructor
        ~intLinked();
        
        bool isEmpty();
        void prepend(int c);
        void append( int c);
        int getHead( int c);
        intLinked* tail();
};

#endif