/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
	protected:
		struct Node {
			string value; 
			struct Node * next; 
		}; 

	   	Node * head; // list head pointer

	public:
	   	LinkedList(); // DVC
	   	~LinkedList(); // destructor
		  
	   	// common linked list operations
	   	void destroyList();
	   	void displayList();
	   	void insertAtFront(string);
	   	string deleteAtFront();
};

#endif
