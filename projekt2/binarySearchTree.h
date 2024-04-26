#pragma once;

class Node
{
protected:
public:
    int key;
    Node* left;
    Node* right;
    Node();
    Node(int _key);
    ~Node();
};

class binarySearchTree
{
private:
    Node* root;

public:
    binarySearchTree(int _key);
    ~binarySearchTree();
    void insert(Node* root, int key);
};

