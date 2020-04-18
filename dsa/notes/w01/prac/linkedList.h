#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_



class linkedList
{
private:
    class Node          // node in linked list
    {
    private:
        int data;
        Node *next;
    public:
        Node(int d, Node *n);
        ~Node();
    };

    int length;
    Node *head;
public:
    linkedList();
    ~linkedList();

    // basic linked list methods
    void prepend(int d);
    void append(int d);
    // void removeByValue(int v);
    // void removeByPos(int pos);
    // void insertByPos(int d, int pos);
    // void ascendingSort();
    // void descendingSort();
    // void reverse();
    void display();
};

#endif