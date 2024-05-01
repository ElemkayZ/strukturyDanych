#pragma once
#include <stdio.h>

struct Pair
{
    int item;
    int priority;
    Pair() : item(0), priority(0) {};
    Pair(int _item, int _priority) : item(_item), priority(_priority) {}
};


class binaryHeap
{
private:
    Pair* heap;// pair: (item, priority)
    int* elementIndices;// array: item -> index in heap used in modifyPrio
    int size;
    int capacity;// Maximum capacity of the heap
    void upHeap(int idx);
    void downHeap(int idx);
    void resize();
public:
    binaryHeap();

    void insert(int item, int priority);
    int extract();
    int peek();
    void modifyPriority(int item, int new_priority);
    int getSize();
};
