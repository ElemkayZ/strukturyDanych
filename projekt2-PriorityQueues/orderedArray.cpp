#include "orderedArray.h"
#include <iostream>

    //function to increase array size
    void orderedArray::resize() {
        int newCapacity = capacity * 2;
        Pair* newArray = new Pair[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    //helping function to add element to array 
    void orderedArray::insert(Pair _element) {
        int i;
        for (i = size - 1; i >= 0 && array[i].priority < _element.priority; --i) {
            array[i + 1] = array[i];
        }
        array[i + 1] = _element;

    }
    //constructor
    orderedArray::orderedArray(){
        capacity = 10;
        array = new Pair[capacity];
        size = 0;

    }
    //destructor
    orderedArray::~orderedArray(){
        delete[] array;
        
    }
    //function to add element to array
    void orderedArray::insert(int _data, int _priority){
        if (size == capacity) {
            resize();
        }
        insert(*new Pair(_data, _priority));
        size++;
    }
    //function to return and remove max prio element from array
    Pair orderedArray::extract(){
        if (size == 0) {
            // std::cerr << "Queue is empty!" << std::endl;
            return *new Pair(-1,-1);
        }
        Pair maxValue = this->array[0]; 

        for (int i = 1; i < size; ++i) {
            array[i - 1] = array[i];
        }
        size--;
        return maxValue;
    }
    //function returning max prio element from array
    Pair orderedArray::peek(){
        return this->array[0];
    }
    //function to retun array size
    int orderedArray::getSize(){
        return this->size;
    }
    //function modifying prio of first encoutered element with given val
    void orderedArray::modifyPriority(int value, int newPriority) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (array[i].item == value) {
                index = i;
            }
        }
        if (index != -1) {
            array[index].priority = newPriority;
            Pair modifiedElement = array[index];
            for (int i = index - 1; i >= 0 && array[i].priority < modifiedElement.priority; --i) {
                array[i + 1] = array[i];
                array[i] = modifiedElement;
            }
            for (int i = index + 1; i < size && array[i].priority > modifiedElement.priority; ++i) {
                array[i - 1] = array[i];
                array[i] = modifiedElement;
            }
        } else {
            // std::cerr << "Element not found!" << std::endl;
        }
    }