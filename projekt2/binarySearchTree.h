#pragma once

struct Node
{
protected:
public:
    int data;
    int priority;
    Node* left;
    Node* right;

    Node(int _data, int _prio) : data(_data), priority(_prio), left(nullptr) ,right(nullptr){}
};

class binarySearchTree
{
private:
    Node* root;
    int size = 0;
    Node* insertNode(Node* _root, int _data, int _priority);
    void displayHandler(Node* root);

public:
    binarySearchTree() : root(nullptr){}
    void insert(int _data, int _priority);//
    Node* findMax(Node* _root);//
    int extractMax();//
    void modifyPrio(int _data, int _priority);//
    int returnSize();

    void display();

   
};

