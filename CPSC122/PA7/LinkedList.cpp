/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#include "LinkedList.h"

/*************************************************************
 * Function: LinkedList class dvc
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: creating LinkedList class object with default values
 * Input parameters: -
 * Returns: LinkedList class object
 * Pre:
 * Post: LinkedList class object created
 **********************************************************/
LinkedList::LinkedList() {
	head = NULL;
}

/*************************************************************
 * Function: LinkedList class destroyer
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: destroys LinkedList object
 * Input parameters: -
 * Returns: -
 * Pre:
 * Post: LinkedList class object destroyed
 **********************************************************/
LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

/*************************************************************
 * Function: destroyList()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: destroys objects in LinkedList
 * Input parameters: -
 * Returns: -
 * Pre: LinkedList object must exist
 * Post: LinkedList class object is clear
 **********************************************************/
void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

/*************************************************************
 * Function: displayList()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: displays content of LinkedList
 * Input parameters: -
 * Returns: -
 * Pre: LinkedList object must exist
 * Post: LinkedList content displayed
 **********************************************************/
void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

/*************************************************************
 * Function: insertAtFront()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: inserts new object at front of the list
 * Input parameters: string newValue
 * Returns: -
 * Pre: LinkedList object must exist
 * Post: new node inserted
 **********************************************************/
void LinkedList::insertAtFront(string newValue) {
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

/*************************************************************
 * Function: deleteAtFront()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: destroys first node in LinkedList
 * Input parameters: -
 * Returns: string val
 * Pre: LinkedList object must exist
 * Post: First node deleted
 **********************************************************/
string LinkedList::deleteAtFront() {
    string val = "";
    if (head != NULL) {
        Node * nodeToDelete = head;
        head = head->next;
        val = nodeToDelete->value;
        delete nodeToDelete;
        return val;
    } else {
        return val;
    }
}


