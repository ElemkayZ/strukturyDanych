#include <iostream>
#include "openHash.h"


    int openHash::hashFunction(int key) {
        return key % size;
    }

    int openHash::linearProbing(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != -1 && table[(index + i) % size] != key) {
            i++;
        }
        return (index + i) % size;
    }

    void openHash::reHash() {
        int oldSize = size;
        int* oldTable = table;

        size = size * 2; // Double the size of the table
        table = new int[size];

        for (int i = 0; i < size; i++) {
            table[i] = -1;  // Initialize the new table with -1 representing empty slots
        }

        count = 0;
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1) {
                insert(oldTable[i]);
            }
        }

        delete[] oldTable;
    }

    openHash::openHash(int size) : size(size), count(0) {
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;  // Initialize the table with -1 representing empty slots
        }
    }

    openHash::~openHash() {
        delete[] table;
    }

    void openHash::insert(int key) {
        if (count >= size * 0.7) { // Resize when load factor exceeds 0.7
            reHash();
        }
        int index = linearProbing(key);
        if (table[index] == -1) {
            table[index] = key;
            count++;
        }
    }

    int openHash::search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != -1) {
            if (table[(index + i) % size] == key) {
                return table[(index + i) % size];
            }
            i++;
        }
        return -1;
    }

    void openHash::remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != -1) {
            if (table[(index + i) % size] == key) {
                table[(index + i) % size] = -1;
                count--;
                return;
            }
            i++;
        }
    }

    void openHash::display() {
        for (int i = 0; i < size; i++) {
            std::cout << i << " --> " << (table[i] == -1 ? "Empty" : std::to_string(table[i])) << std::endl;
        }
    }
