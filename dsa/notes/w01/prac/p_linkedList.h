#ifndef P_LINKEDLIST_H_
#define P_LINKEDLIST_H_



class linkedList
{
private:
    class Node          // node in linked list
    {
    public:
        int data;
        Node *next;
        Node();
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
    int size();
    // void removeByValue(int v);
    // void removeByPos(int pos);
    // void insertByPos(int d, int pos);
    // void ascendingSort();
    // void descendingSort();
    // void reverse();
    void display();
};

#endif