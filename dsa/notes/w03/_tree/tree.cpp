#include <iostream>

#include "tree.h"
using namespace std;

Tree::Node::Node() {  }

// Tree::Node::Node() {
//     data = ' ';
//     heuristic = -1;
//     left = nullptr;
//     right = nullptr;
// }

Tree::Node::Node(char d, int h, Node* l, Node* r) {
    this->data = d;
    this->heuristic = h;
    this->left = l;
    this->right = r;
}

Tree::Node::~Node() {} 

// ---------------------------------------------------
// tree definitions

Tree::Tree() {
    // this->root = new Node();
}
Tree::~Tree() {}

Tree::Node* Tree::insert(char d, int v) {
    Node* in = new Node(d, v, nullptr, nullptr);

    if(this->root == nullptr) {
        this->root = in; 
    }
    else recInsert(this->root, in);

    cout << "insert ok\n";
    return this->root;
}

void Tree::recInsert(Node*& root, Node* in) {
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

void Tree::display(Node* root) {
    if(root == nullptr) return;
    display(root->left);
    std::cout << root->data << " : " << root->heuristic << "\n";
    display(root->right);
}

int main() {
    Tree* tree = new Tree();

    tree->root = tree->insert('B', 0);
    tree->root = tree->insert('A', 1);
    tree->root = tree->insert('C', 2);
    tree->display(tree->root);

    std::cout << "wasd\n";
    return 0;
}