#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Dictionary;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

    friend class Dictionary;
public:
    // Constructor and Destructor
    LinkedList();
    ~LinkedList();

    // Functions to be completed by students
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    bool is_empty() const;
    int size() const;
    void clear();
    void display() const;
    Node* get_head() const;
    void remove(int value);
};

#endif
