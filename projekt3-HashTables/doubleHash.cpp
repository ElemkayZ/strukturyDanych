#include <iostream>
#include "doubleHash.h"
#include <cmath>
//hashing functions
int doubleHash::hashFunction1(int key) {
    return key % capacity;
}
int doubleHash::hashFunction2(int key) {
    const double fib = 0.6180339887 ;
    float x = fmod(key * fib, 1.0);
    int index = int(x*capacity);
    return index;
}
int doubleHash::doubleHashing(int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    if(tableLen[index1] < tableLen[index2])
    return index1;
    return index2;

}
//table size increase and rehashing
void doubleHash::reHash() {
    int oldcapacity = capacity;
        Node** oldTable = table;

        capacity *= 2;
        tableLen = new int[capacity];
        table = new Node*[capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }

        for (int i = 0; i < oldcapacity; ++i) {
            Node* entry = oldTable[i];
            while (entry != nullptr) {
                insert(entry->key, entry->value);
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }

        delete[] oldTable;
}
//constructor
doubleHash::doubleHash(int capacity) : capacity(capacity), size(0){
    tableLen = new int[capacity];
    table = new Node*[capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }

}
//deconstructor
doubleHash::~doubleHash() {
    for (int i = 0; i < capacity; ++i) {
        Node* entry = table[i];
        while (entry != nullptr) {
            Node* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}
//adding element to table
void doubleHash::insert(int key, int value) {
    if ((float)size / capacity > 0.7) {
        reHash();
        }
        int index = doubleHashing(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* entry = table[index];
            Node* prev = nullptr;
            while (entry != nullptr) {
                if (entry->key == key) {
                    entry->value = value;
                    delete newNode;
                    return;
                }
                prev = entry;
                entry = entry->next;
            }
            prev->next = newNode;
        }
        ++size;
        ++tableLen[index];
}
//removing element from table
void doubleHash::remove(int key) {
    int index = hashFunction1(key);
    Node* entry = table[index];
    Node* prev = nullptr;

    while (entry != nullptr) {
        if (entry->key == key) {
            if (prev == nullptr) {
                table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            --size;
            return;
        }
        prev = entry;
        entry = entry->next;
    }
    
    index = hashFunction2(key);
    entry = table[index];
    prev = nullptr;
    while (entry != nullptr) {
        if (entry->key == key) {
            if (prev == nullptr) {
                table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            --size;
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}
//display table
void doubleHash::display() {
    for (int i = 0; i < capacity; ++i) {
        Node* entry = table[i];
        std::cout << "Index " << i << ": ";
        while (entry != nullptr) {
            std::cout << "[" << entry->key << ": " << entry->value << "] ";
            entry = entry->next;
        }
        std::cout << std::endl;
    }
}


