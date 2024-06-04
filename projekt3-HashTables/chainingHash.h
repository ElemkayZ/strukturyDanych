#pragma once


class chainingHash
{
    struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};
protected:
    int size,capacity;
    Node**table;
    void reHash();
public:
    chainingHash(int size);
    ~chainingHash();
    int hashFunction(int key);
    void insert(int key, int value);
    void remove(int key);
    void display();


};