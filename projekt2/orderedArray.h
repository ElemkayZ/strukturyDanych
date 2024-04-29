#pragma once
#include "binaryHeap.h"
// struct Pair
// {
//     int item;
//     int priority;
//     Pair() : item(0), priority(0) {};
//     Pair(int _item, int _priority) : item(_item), priority(_priority) {}
// };
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
