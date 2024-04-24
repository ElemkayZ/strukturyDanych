#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList(int initialCapacity) : capacity(initialCapacity), size(0) {
    array = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] array;
}

void ArrayList::add(int element) {
    if (size >= capacity) {
        resize();
    }
    array[size++] = element;
}
void ArrayList::insert(int index, int element) {
    if (index > size) {
        printf("Index out of range");
    }

    if (size >= capacity) {
        resize();
    }

    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = element;
    ++size;
}
int ArrayList::get(int index) const {
    if (index >= size) {
        printf("Index out of range");
        return -1;
    }
    return array[index];
}

int ArrayList::getSize() const {
    return size;
}

void ArrayList::resize() {
    int newCapacity = capacity * 2;
    int *tempArray = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        tempArray[i] = array[i];
    }
    delete[] array;
    array = tempArray;
    capacity = newCapacity;
}
int ArrayList::search(int element) const {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void ArrayList::print() const {
    if (size == 0) {
        std::cout << "ArrayList is empty." << std::endl;
    } else {
        std::cout << "ArrayList elements:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}

void ArrayList::remove(int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    --size;
}