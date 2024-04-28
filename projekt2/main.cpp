#include "binaryHeap.h"
#include "binarySearchTree.cpp"
#include <iostream>


int main() {
    binarySearchTree bst;

    // Insertion
    bst.insert(5);
    bst.insert(10);
    bst.insert(3);
    bst.insert(7);

    // Display
    std::cout << "Binary Search Tree: ";
    bst.display();

    // Extraction of maximum
    int maxKey = bst.extractMax();
    std::cout << "Maximum key extracted: " << maxKey << std::endl;

    // Display after extraction
    std::cout << "Binary Search Tree after extraction: ";
    bst.display();

    // Modify key
    bst.modifyKey(3, 9);
    std::cout << "Key 3 modified to 9" << std::endl;
    std::cout << "Binary Search Tree after modification: ";
    bst.display();

    return 0;
}