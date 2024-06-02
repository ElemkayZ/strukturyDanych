#include <iostream>
#include "chainingHash.h"
//linked list Separate Chaining
int chainingHash::hashFunction(int key) {
    return key % size;
}
void chainingHash::reSize() {
    int oldSize = size;
    size *= 2;
    Node** newTable = new Node*[size];
    for (int i = 0; i < size; ++i) {
        newTable[i] = nullptr;
    }
    for (int i = 0; i < oldSize; ++i) {
        Node* entry = table[i];
        while (entry != nullptr) {
            Node* next = entry->next;
            int index = hashFunction(entry->data->key);
            entry->next = newTable[index];
            newTable[index] = entry;
            entry = next;
        }
    }
    delete[] table;
    table = newTable;
}
chainingHash::chainingHash(int initialSize) : size(initialSize), count(0) {
    table = new Node*[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
}
chainingHash::~chainingHash() {
    for (int i = 0; i < size; ++i) {
        Node* entry = table[i];
        while (entry != nullptr) {
            Node* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}
void chainingHash::insert(Pair _data) {
    if ((float)count / size > 0.7) {
        reSize();
    }
    int index = hashFunction(_data.key);
    Node* newNode = new Node(&_data);
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* entry = table[index];
        while (entry->next != nullptr) {
            entry = entry->next;
        }
        entry->next = newNode;
    }
    count++;
}
int chainingHash::search(int key) {
    int index = hashFunction(key);
    Node* entry = table[index];
    while (entry != nullptr) {
        if (entry->data->key == key) {
            return entry->data->value;
        }
        entry = entry->next;
    }
    return -1;
}
void chainingHash::remove(int key) {
    int index = hashFunction(key);
    Node* entry = table[index];
    Node* prev = nullptr;
    while (entry != nullptr && entry->data->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == nullptr) {
        return;
    }
    if (prev == nullptr) {
        table[index] = entry->next;
    } else {
        prev->next = entry->next;
    }
    delete entry;
    count--;
}
void chainingHash::display() {
    for (int i = 0; i < size; i++) {
        std::cout << i;
        Node* entry = table[i];
        while (entry != nullptr) {
            std::cout << " --> " << entry->data->key;
            entry = entry->next;
        }
        std::cout << std::endl;
    }
}
