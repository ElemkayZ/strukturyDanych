#include "binarySearchTree.h"
#include <iostream>
#include <queue>

using namespace std;
    
    // Utility function to insert a node into the binary search tree
    Node* binarySearchTree::insertNode(Node* root, int data, int priority) {
        if (root == nullptr) {
            return new Node(data, priority);
        }

        if (priority > root->priority) {
            Node* newNode = new Node(data, priority);
            newNode->left = root;
            return newNode;
        }

        root->right = insertNode(root->right, data, priority);
        return root;
    }
     // Function to insert an element with a given priority
    void binarySearchTree::insert(int _data, int _priority) {
        root = insertNode(root, _data, _priority);
            this->size++;
    }
    
    // Utility function to find the maximum priority node
    Node* binarySearchTree::findMax(Node* _root) {
        if (_root == nullptr || _root->right == nullptr)
            return _root;
        return findMax(_root->right);
    }

    // Function to extract the element with maximum priority
    int binarySearchTree::extractMax() {
        if (this->root == nullptr) {
            std::cerr << "Queue is empty.\n";
            return -1; // Assuming -1 denotes an invalid value
        }

        Node* maxNode = findMax(this->root);
        int data = maxNode->data;

        // Deleting the maximum node
        Node* temp = root;
        if (temp == maxNode) {
            root = root->left;
        } else {
            while (temp->right != maxNode) {
                temp = temp->right;
            }
            temp->right = maxNode->left;
        }
        delete maxNode;
            this->size--;
        return data;
    }

    // Function to modify the priority of an element
    void binarySearchTree::modifyPrio(int _data, int _priority) {
        // First, extract the element from the queue
        int extractedData = -1;
        Node* temp = this->root;
        while (temp != nullptr) {
            if (temp->data == _data) {
                extractedData = temp->data;
                break;
            } else if (temp->priority < _priority) {
                break; // Element not found
            } else {
                temp = temp->right;
            }
        }
        if (extractedData == -1) {
            std::cerr << "Element not found.\n";
            return;
        }
        extractMax();

        // Re-insert the element with the new priority
        insert(extractedData, _priority);
    }

    // Utility function to display the queue
    void binarySearchTree::displayHandler(Node* root) {
        if (root == nullptr)
            return;
        displayHandler(root->right);
        std::cout << "Data: " << root->data << ", Priority: " << root->priority << std::endl;
        displayHandler(root->left);
    }

    // Function to display the binary search tree (in-order traversal)
    void binarySearchTree::display() {
        if (root == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }
        displayHandler(root);
    }


    int binarySearchTree::returnSize() {
        return this->size;
    }