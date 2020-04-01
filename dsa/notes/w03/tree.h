#ifndef TREE_H_
#define TREE_H_

class Tree {
    private:
        class Node {
            public: 
                char data;
                int heuristic;
                Node* left;
                Node* right;

                Node();
                Node(char d, int h, Node* l, Node* r);
                ~Node();    // destructor
        };

    public:
        Node *root;   // private root
        Tree();
        ~Tree();

        Node* insert(char d, int v);
        // recursive function for insert
        void recInsert(Node*& root, Node* in);
        void display(Node* root);
};

#endif