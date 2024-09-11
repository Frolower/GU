#include "linked_list.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (is_empty()) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::pop_front() {
    if (!is_empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::pop_back() {
    if (!is_empty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

int LinkedList::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::clear() {
    while (!is_empty()) {
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

void LinkedList::remove(int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

LinkedList::Node* LinkedList::get_head() const {
    return head;
}

void LinkedList::insertion_sort() {
    Node *head = get_head();

    if(head == NULL || head->next == NULL) {
        return;
    }
    Node* temp1 = head->next;
    while(temp1 != NULL) {
        int sec_data = temp1->data;
        int found = 0;
        Node* temp2 = head;
        while(temp2 != temp1) {
            if(temp2->data > temp1->data && found == 0) {
                sec_data = temp2->data;
                temp2->data = temp1->data;
                found = 1;
                temp2 = temp2->next;
            } else {
                if(found == 1) {
                    int temp = sec_data;
                    sec_data = temp2->data;
                    temp2->data = temp;
                }
                temp2 = temp2->next;
            }
        }
        temp2->data = sec_data;
        temp1 = temp1->next;
    }
}

LinkedList::Node* LinkedList::partition( Node* head,  Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL) {
                (*newHead) = cur;
            }

            prev = cur;
            cur = cur->next;
        }
        else {
            // If cur node is greater than pivot => move cur node to next of tail, and change tail
            if (prev) {
                prev->next = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL) {
        (*newHead) = pivot;
    }

    // Update newEnd to the current last node
    (*newEnd) = tail;

    return pivot;
}


LinkedList::Node* LinkedList::quickSortRecur(Node* head, Node* end) {

    if (!head || head == end) {
        return head;
    }

    Node *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated by the partition function
    Node* pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void LinkedList::quick_sort() {
    Node* headRef = get_head();
    headRef = quickSortRecur(headRef, getTail(headRef));
    LinkedList::head = headRef;
    return;
}

LinkedList::Node* LinkedList::getTail(Node* cur) {
    while (cur != NULL && cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}

LinkedList::Node* LinkedList::merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void LinkedList::split(Node* source, Node** front, Node** back) {
    Node* slow;
    Node* fast;

    if (source == nullptr || source->next == nullptr) {
        *front = source;
        *back = nullptr;
    } else {
        slow = source;
        fast = source->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
    }
}

void LinkedList::merge_sort_rec(Node*& head) {
    Node* a;
    Node* b;

    if (head == nullptr || head->next == nullptr) {
        return; // Base case check
    }

    // Split the list into two halves
    split(head, &a, &b);

    // Recursively sort both halves
    merge_sort_rec(a);
    merge_sort_rec(b);

    // Merge the sorted halves and update the head pointer
    head = merge(a, b);
}

void LinkedList::merge_sort() {
    Node* head = get_head();
    merge_sort_rec(head);
    LinkedList::head = head;
}