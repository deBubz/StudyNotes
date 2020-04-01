#include <iostream>

struct Node {
    char data;
    int heuristic;
    Node* left;
    Node* right;

    Node() {};
    Node(char, int, Node*, Node*);
};


Node :: Node(char d, int h, Node* l, Node* r) {
    data = d;
    heuristic = h;
    left = l;
    right = r;
}

struct Tree {
    Node* root;
    //Tree() { root = new Node; }

    Node* insert(char, int);
    // recursive function for insert
    void recInsert(Node*&, Node*);
    void display(Node*);
};

Node* Tree :: insert(char d, int v) {
    Node* in = new Node(d, v, nullptr, nullptr);

    if(root == nullptr)    root = in;
    else recInsert(root, in);
    return root;
}

void Tree :: recInsert(Node*& root, Node* in) {

    if(in->data < root->data) {
        if(root->left == nullptr)
            root->left = in;
        else recInsert(root->left, in);
    } else if(in->data > root->data) {
        if(root->right == nullptr)
            root->right = in;
        else recInsert(root->right, in);
    }
}

void Tree :: display(Node* root) {
    if(root == nullptr) return;
    display(root->left);
    std::cout << root->data << " : " << root->heuristic << "\n";
    display(root->right);
}

int main() {

    Tree* tree = new Tree;
    Node* root;

    root = tree->insert('B', 0);
    root = tree->insert('A', 1);
    root = tree->insert('C', 2);
    tree->display(root);

    std::cout << "\n";
    return 0;
}