#include "Pair.h"
#pragma once


class openHash
{
protected:
    int size,count;
    Pair*table;
    void reSize();
public:
    openHash(int size);
    ~openHash();
    int hashFunction(int key);
    void insert(Pair data);
    int search(int key);
    void remove(int key);
    void display();

    int quadraticProbing(int key);
};