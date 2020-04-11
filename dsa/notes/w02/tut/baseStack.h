#ifndef BASESTACK_H_
#define BASESTACK_H_

// file 1
// interface
class BaseStack{
    public:
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual void push(int data) = 0;
    virtual void pop() = 0;
    virtual void display() = 0;
};

#endif