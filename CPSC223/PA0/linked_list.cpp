#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

//creates new node and pushes it to the front
void LinkedList::push_front(int value) {

    Node* insert = new Node(value);

    if (head == nullptr) {
        head = insert;
    } else {
        insert->next = head;
        head = insert;
    }
}

//creates new node and pushes it to the back
void LinkedList::push_back(int value) {

    // check if LL is empty
    if (head == nullptr) {
        Node* insert = new Node (value);
        insert->data = value;
        insert->next = nullptr;
        head = insert;
        return;
    }

    Node* curr_node = head;

    while (curr_node->next != nullptr) {
        curr_node = curr_node->next;
    }

    Node* insert = new Node (value);
    insert->data = value;
    insert->next = nullptr;
    curr_node->next = insert;
}

//delete the node at front
void LinkedList::pop_front() {

    //check if LL is empty
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* del = head;

    head = head->next;
    delete del;

    del = nullptr;
}

//delete node at back
void LinkedList::pop_back() {

    //check if LL is empty
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* curr = head;

    //check if it's the only node in LL
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }


    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

//returns the size of a LL
int LinkedList::size() const {

    int size = 0;
    Node* curr_node = head;

    if (head == nullptr) {
        return 0;
    }

    while (curr_node != nullptr) {
        size++;
        curr_node = curr_node->next;
    }

    return size;
}

//removes node with exact value
void LinkedList::remove(int value) {

    //check if LL is empty
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* curr_node = head;
    Node* prev_node = nullptr;

    while (curr_node != nullptr && curr_node->data != value) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node != nullptr) {
        if (prev_node == nullptr) {
            head = curr_node->next;
        } else {
            prev_node->next = curr_node->next;
        }
        delete curr_node;
        curr_node = nullptr;
        return;

    } else {
        std::cout << "No node with this value" << std::endl;
    }
}

void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

LinkedList::Node* LinkedList::get_head() const {
    return head;
}