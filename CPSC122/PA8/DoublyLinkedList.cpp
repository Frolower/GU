/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 26, 2023
 Programming Assignment: PA8
 Description: Prime Numbers
 Notes: -
*/

#include "DoublyLinkedList.h"

// dvc
DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

// destructor
DoublyLinkedList::~DoublyLinkedList() {
	// free each Node's memory in the list
	destroyList();
}

// returns head
Node * DoublyLinkedList::getHead() const {
	return head;
}

// returns tail
Node * DoublyLinkedList::getTail() const {
	return tail;
}

// sets head and tail
void DoublyLinkedList::setHeadAndTail(Node * newHead, Node * newTail) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
	tail = newTail;
}

// clears the list
void DoublyLinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

// displays content of the list
void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
	if (tail != NULL) {
		cout << "tail->" << tail->value << endl;
	}
	else {
		cout << "tail->NULL" << endl;
	}
}

// adds node to the end
void DoublyLinkedList::addToEnd(int newValue) {
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
}

// deletes node from front
int DoublyLinkedList::deleteAtFront() {
    Node * nodeToDel;
    int val = 0;

	if (head != NULL) {
        if (head->next == NULL) {
            nodeToDel = head;
            head = head->next;
            val = nodeToDel->value;
            tail = NULL;
            return val;
        } else {
            nodeToDel = head;
            head = head->next;
            head->prev = NULL;
            val = nodeToDel->value;
            return val;
        }
    } else {
        return -1;
    }
}

/*************************************************************
 * Function: deleteNode()
 * Date Created: 04/26/2023
 * Date Last Modified: 04/26/2023
 * Description: delete node based on its value
 * Input parameters: int targetValue
 * Returns: -
 * Pre: -
 * Post: node deleted
 **********************************************************/
int DoublyLinkedList::deleteNode(int targetValue) {
    Node * currNode = head;
    int val = 0;

    if (head != NULL) {
        while (currNode->value != targetValue) {
            if (currNode->next == NULL) {
                return -1;
            }
            currNode = currNode->next;
        }
        if (currNode->value == targetValue) {
            if (currNode == head && currNode == tail) {
                val = currNode->value;
                head = NULL;
                tail = NULL;
                delete currNode;
                return val;
            } else if (currNode == head) {
                val = currNode->value;
                head = currNode->next;
                head->prev = NULL;
                return val;
            } else if (currNode == tail) {
                val = currNode->value;
                tail = currNode->prev;
                currNode->prev->next = NULL;
                delete currNode;
                return val;
            } else {
                val = currNode->value;
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                delete currNode;
                return val;
            }

        } else {

        }
        return -1;
    } else {
        return -1;
    }
}

// adds element to the front of the list
void DoublyLinkedList::addToFront(int newValue) {
	Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
}

// deletes element at the end of the list
int DoublyLinkedList::deleteAtEnd() {
	Node * nodeToDel;
    int val = 0;

    if (tail == head) {
        nodeToDel = head;
        val = nodeToDel->value;
        delete nodeToDel;
        tail = NULL;
        head = NULL;
        return val;
    } else {
        nodeToDel = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        val = nodeToDel->value;
        delete nodeToDel;
        return val;
    }
}

// TODO: BONUS ONLY finish this function
void DoublyLinkedList::insertInOrder(int newValue) {

}
