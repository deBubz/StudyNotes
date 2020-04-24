#ifndef BASELIST_H_
#define BASELIST_H_

// interface file
// typically a bunch of virtual functions

class BaseList
{
    public:
        virtual void prepend(int d) = 0;
        virtual void append(int d) = 0;
        virtual void display(int d) = 0;
};

#endif