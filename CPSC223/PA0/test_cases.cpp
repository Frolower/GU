#include <iostream>
#include "linked_list.h"

int main () {
    LinkedList test_ll;

    //push values 1-5 to the LL
    test_ll.push_back(3);
    test_ll.push_back(4);
    test_ll.push_back(5);
    test_ll.push_front(2);
    test_ll.push_front(1);

    std::cout << test_ll.size() << std::endl;

    test_ll.display();

    //removes values 1 , 3 , 5
    test_ll.pop_back();
    test_ll.pop_front();
    test_ll.remove(3);

    //tries to remove value that is not in the list
    test_ll.remove(6);

    std::cout << test_ll.size() << std::endl;

    //should return false or nothing
    std::cout << std::boolalpha << test_ll.is_empty() << std::endl;

    test_ll.display();

    test_ll.clear();

    //should return true
    std::cout << std::boolalpha << test_ll.is_empty() << std::endl;

    //tries to remove nodes from an empty list
    test_ll.pop_front();
    test_ll.pop_back();
}