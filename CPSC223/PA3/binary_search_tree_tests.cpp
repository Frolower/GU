#include "binary_search_tree.hpp"

void insertionAndIOTtest();
void searchTest();
void deletionTest();

int main() {
    insertionAndIOTtest();
    searchTest();
    deletionTest();
    return 0;
}

void insertionAndIOTtest () {
    std::cout << "Insertion and IOT test" << std::endl;
    BinarySearchTree tree;
    tree.insert(tree.getHead() , nullptr , 6);
    tree.insert(tree.getHead() , nullptr , 3);
    tree.insert(tree.getHead() , nullptr , 1);
    tree.insert(tree.getHead() , nullptr , 5);
    tree.insert(tree.getHead() , nullptr , 2);
    tree.insert(tree.getHead() , nullptr , 4);
    tree.insert(tree.getHead() , nullptr , 8);
    tree.insert(tree.getHead() , nullptr , 7);
    tree.insert(tree.getHead() , nullptr , 10);
    tree.insert(tree.getHead() , nullptr , 9);
    tree.insert(tree.getHead() , nullptr , 11);
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    //1,2,3,4,5,6,7,8,9,10,11 expected
}

void searchTest() {
    BinarySearchTree tree;
    tree.insert(tree.getHead() , nullptr , 6);
    tree.insert(tree.getHead() , nullptr , 3);
    tree.insert(tree.getHead() , nullptr , 1);
    tree.insert(tree.getHead() , nullptr , 5);
    tree.insert(tree.getHead() , nullptr , 2);
    tree.insert(tree.getHead() , nullptr , 4);
    tree.insert(tree.getHead() , nullptr , 8);
    tree.insert(tree.getHead() , nullptr , 7);
    tree.insert(tree.getHead() , nullptr , 10);
    tree.insert(tree.getHead() , nullptr , 9);
    tree.insert(tree.getHead() , nullptr , 11);
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;

    std::cout << "Node with value " << tree.search(tree.getHead(), 6)->data << " found" << std::endl;
    std::cout << "Node with value " << tree.search(tree.getHead(), 1)->data << " found" << std::endl;
    std::cout << "Node with value " << tree.search(tree.getHead(), 8)->data << " found" << std::endl;
    std::cout << "Node with value " << tree.search(tree.getHead(), 11)->data << " found" << std::endl;
    tree.search(tree.getHead(), 436476)->data; //error expected
}

void deletionTest() {
    //setup
    BinarySearchTree tree;
    tree.insert(tree.getHead() , nullptr , 6);
    tree.insert(tree.getHead() , nullptr , 3);
    tree.insert(tree.getHead() , nullptr , 1);
    tree.insert(tree.getHead() , nullptr , 5);
    tree.insert(tree.getHead() , nullptr , 2);
    tree.insert(tree.getHead() , nullptr , 4);
    tree.insert(tree.getHead() , nullptr , 8);
    tree.insert(tree.getHead() , nullptr , 7);
    tree.insert(tree.getHead() , nullptr , 10);
    tree.insert(tree.getHead() , nullptr , 9);
    tree.insert(tree.getHead() , nullptr , 11);
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "1,2,3,4,5,6,7,8,9,10,11 expected" << std::endl;

    //deleting a node with left connection
    std::cout << "deleting " << tree.deletion(5) << std::endl;
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "1,2,3,4,6,7,8,9,10,11 expected" << std::endl;

    //deleting a node with right connection
    std::cout << "deleting " << tree.deletion(1) << std::endl;
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "2,3,4,6,7,8,9,10,11 expected" << std::endl;

    //deleting a node with two connections
    std::cout << "deleting " << tree.deletion(8) << std::endl;
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "2,3,4,6,7,9,10,11 expected" << std::endl;

    //deleting a node with no connections
    std::cout << "deleting " << tree.deletion(11) << std::endl;
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "2,3,4,6,7,9,10 expected" << std::endl;

    //deleting a head node with two connections
    std::cout << "deleting " << tree.deletion(6) << std::endl;
    tree.iotTraversal(tree.getHead());
    std::cout << std::endl;
    std::cout << "2,3,4,7,9,10 expected" << std::endl;

    //trying to delete a node that doesn't exist
    std::cout << "deleting 111. " << tree.deletion(111) << std::endl;
    std::cout << "error expected" << std::endl;
}