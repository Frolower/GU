#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList list;

    // Test push_front
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    std::cout << "After push_front: ";
    list.display();

    // Test push_back
    list.push_back(4);
    list.push_back(5);
    std::cout << "After push_back: ";
    list.display();

    // Test pop_front
    list.pop_front();
    std::cout << "After pop_front: ";
    list.display();

    // Test pop_back
    list.pop_back();
    std::cout << "After pop_back: ";
    list.display();

    // Test remove
    list.remove(3);
    std::cout << "After remove: ";
    list.display();

    // Test is_empty and size
    std::cout << "Is list empty? " << (list.is_empty() ? "Yes" : "No") << std::endl;
    std::cout << "List size: " << list.size() << std::endl;

    // Test clear
    list.clear();
    std::cout << "After clear: ";
    list.display();
    std::cout << "Is list empty? " << (list.is_empty() ? "Yes" : "No") << std::endl;

    return 0;
}
