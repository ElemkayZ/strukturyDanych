#include "binarySearchTree.h"
#include <iostream>

using namespace std;

// Node structure for the binary search tree

Node::Node(int _key)
{
    Node* node = new Node;
    node->key = _key;
    node->left = nullptr;
    node->right = nullptr;
}

Node::~Node()
{
}
// binary search tree structure 
binarySearchTree::binarySearchTree(int _key)
{
    this->root = new Node(_key);
}

binarySearchTree::~binarySearchTree()
{
}

// Function to insert a key into the binary search tree
void binarySearchTree::insert(Node* root, int key) {
    if (root == nullptr) {
        this->root = new Node(key);
    }
    if (key > root->key) {
        root->left.insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    this->root = new Node(key);

}




///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

