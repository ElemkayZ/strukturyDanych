#pragma once



class doubleHash
{
    struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};
protected:
    int size,capacity;
    int* tableLen;
    Node**table;
    void reHash();
    int hashFunction1(int key);
    int hashFunction2(int key);
public:
    doubleHash(int size);
    ~doubleHash();
    int doubleHashing(int key);
    void insert(int key, int value);
    void remove(int key);//
    void display();


};