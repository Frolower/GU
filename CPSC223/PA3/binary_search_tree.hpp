#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

class BinarySearchTree{

    private:
        struct Node {
           int data;
          Node* left;
          Node* right;
          Node(int value) : data(value), left(nullptr), right(nullptr) {};
        };

         Node* head;

    public:
    BinarySearchTree();
    ~BinarySearchTree();

    void deletionTree(Node* node);

    void newTree();
    Node* newNode(int value);

    Node* getHead();

    void iotTraversal(Node* start);
    Node* search(Node* cur, int val);

    void insert(Node* cur, Node* prevNode, int val);

    int deletion(int val);
    Node* findMinNode(Node* node);

};

#endif