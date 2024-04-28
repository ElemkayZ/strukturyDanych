#pragma once

struct Node
{
protected:
public:
    int key;
    Node* left;
    Node* right;

};

class binarySearchTree
{
private:
    Node* root;
    Node* insertNode(Node* root, int key);
    Node* deleteNode(Node* root, int key);
    void modifyNode(Node* root, int oldKey, int newKey);
    void inorderTraversal(Node* root);
    
public:
    binarySearchTree();
    Node* newNode(int key);
    void insert(int key);
    Node* findMax(Node* root);
    Node* deleteMax(Node* root);
    void deleteKey(int key);
    int findMaxValue(Node* root);
    int extractMax();
    void modifyKey(int oldKey, int newKey);
    void display();

   
};

