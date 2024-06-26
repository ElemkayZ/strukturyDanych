#include <iostream>
#include "openHash.h"
//Open Addressing with quadratic Probing

//hashing function
    int openHash::hashFunction(int key) {
        return key % size;
    }

    int openHash::quadraticProbing(int key) {
        int index = hashFunction(key);
        int i = 0;
        int j = i;
        while (table[(index + j) % size].key != -1 && table[(index + j) % size].key != key) {
            j = i^2;
            i++;
            
        }
        return (index + i);
    }
//table size increase and rehashing
    void openHash::reSize() {
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
//constructor
    openHash::openHash(int size) : size(size), count(0) {
        table = new Pair[size];

    }
//deconstructor
    openHash::~openHash() {
        delete[] table;
    }
//adding element to table
    void openHash::insert(Pair _data) {
        if (count >= size * 0.7) { // Resize when load factor exceeds 0.7
            reSize();
        }
        int index = quadraticProbing(_data.key);
        if (table[index].key == -1) {
            table[index] = _data;
            count++;
        }
    }
//removing element from table
    void openHash::remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        int j = i;
        while (table[(index + i) % size].key != -1) {
            if (table[(index + i) % size].key == key) {
                table[(index + i) % size] = *new Pair;
                count--;
                return;
            }
            j = i^2;
            i++;


        }
    }
//display table
    void openHash::display() {
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
