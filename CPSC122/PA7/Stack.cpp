/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#include "Stack.h"

void Stack::push(string newValue) {
    LinkedList::insertAtFront(newValue);
}

string Stack::pop() {
    string res = "";
    res = LinkedList::deleteAtFront();
	return res;
}

string Stack::peek() {
    if (head != NULL) {
        return head->value;
    }
    return "";
}

bool Stack::isEmpty() {
    if (head != NULL) {
        return false;
    }
    return true;
}
