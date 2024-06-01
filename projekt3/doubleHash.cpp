#include <iostream>
#include "doubleHash.h"

int doubleHash::hashFunction1(int key) {
    return key % size;
}
int doubleHash::hashFunction2(int key) {
    return (7 - (key % 7));
}
int doubleHash::doubleHashing(int key, int i) {
    return (hashFunction1(key) + i * hashFunction2(key))% size;
}
void doubleHash::reSize() {
    int oldSize = size;
        Pair* oldTable = table;

        size = size * 2; // Double the size of the table
        table = new Pair[size];

        count = 0;
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].key != -1) {
                insert(oldTable[i]);
            }
        }

        delete[] oldTable;
}
doubleHash::doubleHash(int size) : size(size), count(0){
    table = new Pair[size];

}
doubleHash::~doubleHash() {
    delete[] table;
}
void doubleHash::insert(Pair _data) {
    if (count >= size * 0.7) { // Resize when load factor exceeds 0.7
        reSize();
    }
    int i = 0;
    int index;
    do {
        index = doubleHashing(_data.key, i);
        i++;
    } while (table[index].key != -1 && table[index].key != _data.key);
    table[index] = _data;
    count++;
}
int doubleHash::search(int key) {
    int i = 0;
    int index;
    do {
        index = doubleHashing(key, i);
        if (table[index].key == key) {
            return true;
        }
        i++;
    } while (table[index].key != -1 && i < size);
    return false;
}
void doubleHash::remove(int key) {
    int i = 0;
    int index;
    do {
        index = doubleHashing(key, i);
        if (table[index].key == key) {
            table[index].key = -1;
            count--;
            return;
        }
        i++;
    } while (table[index].key != -1 && i < size);
}
void doubleHash::display() {
    for (int i = 0; i < size; i++) {
            std::cout << i << " --> ";
            if (table[i].key == -1)
            {
                std::cout << " --- ";
            }
            else{
                printf("%d - %d",table[i].key,table[i].value);
            }
            printf("\n");

        }
}


