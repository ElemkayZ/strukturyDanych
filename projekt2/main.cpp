#include "binaryHeap.cpp"
#include "binarySearchTree.cpp"
#include <iostream>


int main() {
    // binarySearchTree pq;

    // // Insertion
    // pq.insert(40,7);
    // pq.insert(20,10);
    // pq.insert(30,3);
    // pq.insert(10,5);

    // std::cout << "Queue contents after insertion:" << std::endl;
    // pq.display();

    // std::cout << "Extracted max element: " << pq.extractMax() << std::endl;

    // std::cout << "Queue contents after extraction:" << std::endl;
    // pq.display();

    // pq.modifyPrio(20, 15);

    // std::cout << "Queue contents after priority modification:" << std::endl;
    // pq.display();


    binaryHeap pq;
    pq.insert(1, 10);
    pq.insert(2, 20);
    pq.insert(3, 15);
    pq.insert(4, 5);
    pq.insert(5, 34);
    pq.insert(6, 35);

    std::cout << "Dequeue: " << pq.extract() << std::endl; // Output: 6

    pq.modifyPriority(1, 20);
    std::cout << "Dequeue: " << pq.extract() << std::endl; // Output: 1

    return 0;

}