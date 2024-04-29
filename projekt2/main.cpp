#include "binaryHeap.cpp"
#include "orderedArray.cpp"
#include <iostream>
#include <ctime>  
#include <random>

int main() {

    orderedArray pq;

    // Adding elements to the queue with specified priorities
    pq.insert(10, 20);
    pq.insert(15, 30);
    pq.insert(5, 10);
    pq.insert(3, 20);

    // Modifying the priority of an element
    pq.modifyPriority(15, 0); // Change priority of value 15 to 0

    // Removing and displaying elements with the highest priority
    while (!(pq.getSize() == 0)) {
        Pair element = pq.extract();
        std::cout << "Value: " << element.item << ", Priority: " << element.priority << std::endl;
    }




    // mt19937 rng(time(0));
    // std::uniform_int_distribution<unsigned long> dis;


    // binaryHeap pq;

    // for (int i = 0; i < 1000000; ++i) {
    //     pq.insert(i, dis(rng));
    //     std::cout << dis(rng)<<std::endl;

    // }
    // std::cout << "Dequeue: " << pq.extract() << std::endl; // Output: 6

    // pq.modifyPriority(1, 20);
    // std::cout << "Dequeue: " << pq.extract() << std::endl; // Output: 1

    return 0;

}