#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();
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
    void insertion_sort();

    void quick_sort();
    Node* getTail(Node* cur);
    Node* quickSortRecur(Node* head, Node* end);
    Node* partition( Node* head,  Node* end, Node** newHead, Node** newEnd);
    Node* merge(Node* left, Node* right);
    void split(Node* source, Node** front, Node** back);
    void merge_sort();
    void merge_sort_rec(Node*& head);
};

#endif
