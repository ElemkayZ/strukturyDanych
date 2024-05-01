#pragma once
#include "binaryHeap.h"
// struct Pair implemented in binaryHeap.h
class orderedArray
{
private:
    Pair* array;
    int capacity;
    int size;

    void resize();
    void insert(Pair _element);
public:
    orderedArray();
    ~orderedArray();
    void insert(int _data, int _priority);
    Pair extract();
    Pair peek();
    void modifyPriority(int value, int newPriority);
    int getSize();
};
