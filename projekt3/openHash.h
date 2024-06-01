
#pragma once
class openHash
{
protected:
    int size,count;
    int*table;
public:
    openHash(int size);
    ~openHash();
    int hashFunction(int key);
    void reHash();
    void insert(int key);
    int search(int key);
    void remove(int key);
    void display();

    int linearProbing(int key);
};