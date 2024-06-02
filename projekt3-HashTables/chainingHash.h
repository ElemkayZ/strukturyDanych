#include "Pair.h"
#pragma once


class chainingHash
{
    struct Node {
        Pair* data;
        Node* next;
        Node(Pair* _data) : data(_data), next(nullptr) {}
    };
protected:
    int size,count;
    Node**table;
    void reSize();
public:
    chainingHash(int size);
    ~chainingHash();
    int hashFunction(int key);
    void insert(Pair data);
    int search(int key);
    void remove(int key);
    void display();


};