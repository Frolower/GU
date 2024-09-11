#include "binary_search_tree.hpp"


BinarySearchTree::BinarySearchTree()
{
    newTree(); //initialize a new tree
}
BinarySearchTree::~BinarySearchTree()
{
    deletionTree(head);
}

void BinarySearchTree::deletionTree(Node* node) {
    if (node != nullptr) {
        deletionTree(node->left);
        deletionTree(node->right);
        delete node;
    }
}

void BinarySearchTree::newTree()
{
    head = nullptr; //initialize the tree by making the head exist with NULL values, so it can be replaced later.
}

BinarySearchTree::Node* BinarySearchTree::getHead() {
    return head;
}

BinarySearchTree::Node* BinarySearchTree::newNode(int value)
{
    //init a new node with value and left/right nodes. lines are self-explanatory.
    Node* nNode = new Node(value);
    nNode->data = value; 
    nNode->left = nullptr;
    nNode->right = nullptr;
    return nNode;
}

void BinarySearchTree::iotTraversal(Node* start) {
    if(start == nullptr) //does this node actually exist?
    {
        return; //stop the recursion here.
    }

    iotTraversal(start->left); //traverse left

    std::cout << start->data << ", "; //print current node.

    iotTraversal(start->right); //traverse right after all nodes to its left have been traversed.

}

BinarySearchTree::Node* BinarySearchTree::search(Node* cur, int val)
{
    if(cur == nullptr) //is the node NULL (AKA the value doesn't actually exist, assuming that it's properly placed in-order?)
    {
        std::cout << "No node with such value" << std::endl;
        return nullptr; //ret NULL
    }
    if (cur->data == val) //is the current node EQUAL to the value requested?
    {
        return cur; //we found the node, return it!
    }
    if(cur->data < val) //is the current node value lesser than the key?
    {
        return search(cur->right, val); //search to its right.
    }

     return search(cur->left, val); //the only other option left to us, search the left of the node.
    

    
}

void BinarySearchTree::insert(Node* cur, Node* prevNode, int val) {

    if (head == nullptr) {//inserting to the head
        head = newNode(val);
        return;
    }

    if (cur == nullptr) { //correct place was found
        Node* toInsert = newNode(val);

        // Update the left or right pointer of the previous node
        if (prevNode->data > val) {
            prevNode->left = toInsert;
        } else {
            prevNode->right = toInsert;
        }
        return;
    } else if (val < cur->data) { //determining a way to go
        insert(cur->left, cur, val);
    } else {
        insert(cur->right, cur, val);
    }
}


int BinarySearchTree::deletion(int val) {

    if (head == nullptr) { // if head is empty
        std::cout << "Head is empty" << std::endl;
        return -1;
    }

    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr && currNode->data != val) { //looking for a correct node to delete
        prevNode = currNode;
        if (val < currNode->data) {
            currNode = currNode->left;
        } else {
            currNode = currNode->right;
        }
    }

    if (currNode == nullptr) { //if node doesn't exist
        std::cout << "No node with such value" << std::endl;
        return -1;
    }

    if (currNode->left == nullptr && currNode->right == nullptr) { //nodes with no children

        if (prevNode == nullptr) { //Deleting head node with no children
            delete head;
            head = nullptr;
        } else if (val < prevNode->data) {
            delete currNode;
            prevNode->left = nullptr;
        } else {
            delete currNode;
            prevNode->right = nullptr;
        }
    } else if (currNode->left == nullptr || currNode->right == nullptr) { //Node has only one child
        Node* child = (currNode->left != nullptr) ? currNode->left : currNode->right; //efficient way to find a child node
        if (prevNode == nullptr) { //head case
            delete head;
            head = child;
        } else if (val < prevNode->data) {
            delete currNode;
            prevNode->left = child;
        } else {
            delete currNode;
            prevNode->right = child;
        }
    } else { //Node has two children
        Node* successor = findMinNode(currNode->right); //Looking for the inorder successor
        int successorValue = successor->data;
        deletion(successorValue); //Recursively deleting the inorder successor
        currNode->data = successorValue; //Replacing the node's value with the successor's value
    }

    return 0;
}

BinarySearchTree::Node* BinarySearchTree::findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

