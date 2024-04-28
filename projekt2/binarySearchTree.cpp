#include "binarySearchTree.h"
#include <iostream>

using namespace std;
    
    // Helper function to insert a key into the binary search tree
Node* binarySearchTree::insertNode(Node* _root, int key) {
        if (_root == nullptr) {
            return newNode(key);
        }
        if (key > _root->key) {
            _root->right = insertNode(_root->right, key);
        } else {
            _root->left = insertNode(_root->left, key);
        }
        return _root;
    }


// Helper function to delete a key from the binary search tree
    Node* binarySearchTree::deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMax(root->left);
            root->key = temp->key;
            root->left = deleteMax(root->left);
        }
        return root;
    }

     // Helper function to modify the key of a node in the binary search tree
    void binarySearchTree::modifyNode(Node* root, int oldKey, int newKey) {
        if (root == nullptr) {
            return;
        }
        if (root->key == oldKey) {
            root->key = newKey;
        } else if (oldKey > root->key) {
            modifyNode(root->right, oldKey, newKey);
        } else {
            modifyNode(root->left, oldKey, newKey);
        }
    }


    // Helper function for in-order traversal to display the binary search tree
    void binarySearchTree::inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }

    binarySearchTree::binarySearchTree(){
        root = nullptr;
    }


    // Function to create a new node
    Node* binarySearchTree::newNode(int key) {
        Node* node = new Node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    
    // Function to insert a key into the binary search tree
    void binarySearchTree::insert(int key) {
        this->root = insertNode(this->root, key);
    }

     // Function to find the maximum key in the binary search tree
    Node* binarySearchTree::findMax(Node* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

     // Function to delete the maximum key from the binary search tree
    Node* binarySearchTree::deleteMax(Node* root) {
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        root->right = deleteMax(root->right);
        return root;
    }
    
    // Function to delete a key from the binary search tree
    void binarySearchTree::deleteKey(int key) {
        root = deleteNode(root, key);
    }
    

    // Function to find the maximum key in the binary search tree (used for extracting the maximum)
    int binarySearchTree::findMaxValue(Node* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->key;
    }

    // Function to extract the maximum key from the binary search tree
    int binarySearchTree::extractMax() {
        int maxKey = findMaxValue(root);
        deleteKey(maxKey);
        return maxKey;
    }

    // Function to modify the key of a node in the binary search tree
    void binarySearchTree::modifyKey(int oldKey, int newKey) {
        modifyNode(root, oldKey, newKey);
    }
    
    // Function to display the binary search tree (in-order traversal)
    void binarySearchTree::display() {
        inorderTraversal(root);
        cout << endl;
    }
