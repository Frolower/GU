/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 26, 2023
 Programming Assignment: PA8
 Description: Prime Numbers
 Notes: -
*/

#include "DoublyLinkedQueue.h"

// displays queue
void DoublyLinkedQueue::displayQueue() {
	Node * currNode = head;
	
	while (currNode != NULL) {
		cout << currNode->value << " ";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << endl;
}

// adds element to the end of the list
void DoublyLinkedQueue::enqueue(int newValue) {
    DoublyLinkedList::addToEnd(newValue);
}

// removes element from the beginning of the list
int DoublyLinkedQueue::dequeue() {
	return DoublyLinkedList::deleteAtFront();
}

// clears list
void DoublyLinkedQueue::clear() {
    DoublyLinkedList::destroyList();
}

// checks if list is empty
bool DoublyLinkedQueue::isEmpty() {
	if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

// returns size of the list
int DoublyLinkedQueue::size() {
	int i = 0;
    Node * currNode = head;

    if (head == NULL) {
        return 0;
    }

    while (currNode->next != NULL) {
        i++;
        currNode = currNode->next;
    }
    i++;
    return i;
}

/*************************************************************
 * Function: removeDivisibleBy()
 * Date Created: 04/26/2023
 * Date Last Modified: 04/26/2023
 * Description: goes through the list and removes numbers that are divisible by p
 * Input parameters: int p
 * Returns: -
 * Pre: list must contain some numbers , p > 1
 * Post: list updated
 **********************************************************/
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	Node * currNode = head;
    Node * nextNode;

    while (currNode->next != NULL) {
        nextNode = currNode->next;
        if (currNode->value % p == 0) {
            DoublyLinkedList::deleteNode(currNode->value);
        }
        currNode = nextNode;
    }
    if (currNode->value % p == 0) {
        DoublyLinkedList::deleteNode(currNode->value);
    }
}

