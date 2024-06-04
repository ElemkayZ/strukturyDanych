#include <iostream>
#include <cstdlib>
#include "chainingHash.h"

//hashing function
int chainingHash::hashFunction(int key){
    return key % capacity;
}
//table size increase and rehashing
void chainingHash::reHash() {
    int oldcapacity = capacity;
    Node** oldTable = table;
    capacity *= 2;
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
// construktor
chainingHash::chainingHash(int _size) : capacity(_size), size(0) {
    table = new Node*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
}
// Deconstructor
chainingHash::~chainingHash() {
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
void chainingHash::insert(int key, int value) {
    if ((float)size / capacity > 0.7) {
        reHash();
    }
    int index = hashFunction(key);
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
}
//removing element from table
void chainingHash::remove(int key) {
    int index = hashFunction(key);
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
}
//display table
void chainingHash::display(){
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