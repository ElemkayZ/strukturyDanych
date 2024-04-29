#include "binaryHeap.h"

#include <iostream>

using namespace std;


    void binaryHeap::upHeap(int index) {
        while (index > 0) {
            int parent_index = (index - 1) / 2;
            if (heap[index].priority <= heap[parent_index].priority) {
                break;
            }
            swap(heap[index], heap[parent_index]);
            elementIndices[heap[index].item] = index;
            elementIndices[heap[parent_index].item] = parent_index;
            index = parent_index;
        }
    }

    void binaryHeap::downHeap(int index) {
        while (index < size) {
            int left_child_index = 2 * index + 1;
            int right_child_index = 2 * index + 2;
            int largest = index;
            if (left_child_index < size && heap[left_child_index].priority > heap[largest].priority) {
                largest = left_child_index;
            }
            if (right_child_index < size && heap[right_child_index].priority > heap[largest].priority) {
                largest = right_child_index;
            }
            if (largest == index) {
                break;
            }
            swap(heap[index], heap[largest]);
            elementIndices[heap[index].item] = index;
            elementIndices[heap[largest].item] = largest;
            index = largest;
        }
    }

    void binaryHeap::resize() {
        int new_capacity = capacity * 2;
        Pair *new_heap = new Pair[new_capacity];
        int *new_element_indices = new int[new_capacity];
        for (int i = 0; i < capacity; ++i) {
            new_heap[i] = heap[i];
            new_element_indices[i] = elementIndices[i];
        }
        delete[] heap;
        delete[] elementIndices;
        heap = new_heap;
        elementIndices = new_element_indices;
        capacity = new_capacity;
    }

    binaryHeap::binaryHeap() {
        size = 0;
        capacity = 10;
        heap = new Pair[capacity];
        elementIndices = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            elementIndices[i] = -1; // Initialize all indices to -1
        }
    }

    void binaryHeap::insert(int item, int priority) {
        if (size == capacity) {
            resize();
        }
        heap[size] = Pair(item, priority);
        elementIndices[item] = size;
        upHeap(size);
        ++size;
    }

    int binaryHeap::extract() {
        if (size == 0) {
            return -1; // or any suitable indicator for empty queue
        }
        int item = heap[0].item;
        if (size == 1) {
            elementIndices[item] = -1;
            size = 0;
            return item;
        }
        heap[0] = heap[size - 1];
        elementIndices[heap[0].item] = 0;
        --size;
        downHeap(0);
        return item;
    }
    int binaryHeap::peek(){
        return heap[0].item;
    }

    void binaryHeap::modifyPriority(int item, int new_priority) {
        if (elementIndices[item] == -1) {
            cout << "Item not found in priority queue" << endl;
            return;
        }
        int index = elementIndices[item];
        int old_priority = heap[index].priority;
        heap[index].priority = new_priority;
        if (new_priority < old_priority) {
            downHeap(index);
        } else {
            upHeap(index);
        }
    }

    int binaryHeap::getSize(){
        return this->size;
    }
