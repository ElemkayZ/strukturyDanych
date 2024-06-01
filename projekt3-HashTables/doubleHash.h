#include "Pair.h"
#pragma once


class doubleHash
{
protected:
    int size,count;
    Pair*table;
    void reSize();
public:
    doubleHash(int size);
    ~doubleHash();
    int hashFunction1(int key);
    int hashFunction2(int key);
    int doubleHashing(int key, int i);
    void insert(Pair data);
    int search(int key);
    void remove(int key);
    void display();

    int quadraticProbing(int key);
};