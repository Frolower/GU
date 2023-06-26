#include "gtest/gtest.h"
#include "PA8.h"


// NOTE: the order is expected/solution, actual/received student value
TEST(Test1_DoublyLinkedList, addToEnd) {
	Node * h = NULL, * t = NULL;
	DoublyLinkedList dll;
	
	// add to end AKA insert at end AKA append node
	dll = DoublyLinkedList();
	dll.addToEnd(1);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_EQ(1, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_TRUE(NULL == h->next); 
	}
	
	dll.addToEnd(3);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(3, t->value); 
		EXPECT_EQ(1, h->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(t, h->next); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(h, t->prev); 
	}
	
	dll.addToEnd(5);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(5, t->value); 
		EXPECT_EQ(1, h->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(3, h->next->value); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(3, t->prev->value); 
	}
}

TEST(Test2_DoublyLinkedList, deleteAtFront) {
	Node * h = NULL, * t = NULL, * one = NULL, * two = NULL, * three = NULL;
	int val = -1;
	DoublyLinkedList dll;
	
	// delete at front
	one = new Node;
	one->value = 1;
	one->prev = NULL;
	two = new Node;
	two->value = 2;
	one->next = two;
	two->prev = one;
	three = new Node;
	three->value = 3;
	two->next = three;
	three->prev = two;
	three->next = NULL;
	dll.setHeadAndTail(one, three);
	
	val = dll.deleteAtFront();
	EXPECT_EQ(1, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, two); 
	EXPECT_EQ(t, three); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(2, h->value); 
		EXPECT_EQ(3, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(three, h->next); 
		EXPECT_EQ(two, t->prev); 
		EXPECT_TRUE(NULL == t->next); 
	}
	
	val = dll.deleteAtFront();
	EXPECT_EQ(2, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(3, h->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_TRUE(NULL == h->next); 
	}
	
	val = dll.deleteAtFront();
	EXPECT_EQ(3, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(NULL == h); 
}

TEST(Test3_DoublyLinkedList, deleteNode) {
	Node * h = NULL, * t = NULL, * one = NULL, * two = NULL, * three = NULL, * four = NULL;
	DoublyLinkedList dll;
	int val = -1;
	
	// delete node
	one = new Node;
	one->value = 1;
	one->prev = NULL;
	two = new Node;
	two->value = 2;
	one->next = two;
	two->prev = one;
	three = new Node;
	three->value = 3;
	two->next = three;
	three->prev = two;
	four = new Node;
	four->value = 4;
	four->prev = three;
	three->next = four;
	four->next = NULL;
	dll = DoublyLinkedList();
	dll.setHeadAndTail(one, four);

	// delete node that doesn't exist in the list
	// shouldn't modify list
	val = dll.deleteNode(5);
	EXPECT_EQ(-1, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(one, h); 
	EXPECT_EQ(four, t);
	EXPECT_TRUE(NULL == h->prev);
	EXPECT_EQ(two, h->next);
	EXPECT_EQ(three, h->next->next); 
	EXPECT_EQ(four, h->next->next->next);
	EXPECT_TRUE(NULL == t->next);
	EXPECT_EQ(three, t->prev);
	EXPECT_EQ(two, t->prev->prev);
	EXPECT_EQ(one, t->prev->prev->prev);
	
	// delete node somewhere in the middle of the list
	val = dll.deleteNode(2);
	EXPECT_EQ(2, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, one); 
	EXPECT_EQ(t, four); 
	EXPECT_EQ(1, h->value); 
	EXPECT_EQ(4, t->value); 
	EXPECT_TRUE(NULL == h->prev); 
	EXPECT_EQ(three, h->next); 
	EXPECT_EQ(three, t->prev); 
	EXPECT_TRUE(NULL == t->next); 
	EXPECT_EQ(three, one->next); // in this case, same as EXPECT_EQ(three, h->next); 
	EXPECT_EQ(one, three->prev);
	
	// delete node at the front of the list
	val = dll.deleteNode(1);
	EXPECT_EQ(1, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, three); 
	EXPECT_EQ(t, four); 
	EXPECT_EQ(3, h->value); 
	EXPECT_EQ(4, t->value); 
	EXPECT_TRUE(NULL == h->prev); 
	EXPECT_EQ(four, h->next); 
	EXPECT_EQ(three, t->prev); 
	EXPECT_TRUE(NULL == t->next); 
	
	// delete node at end of list
	val = dll.deleteNode(4);
	EXPECT_EQ(4, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, three); 
	EXPECT_EQ(h, t); 
	EXPECT_EQ(3, h->value); 
	EXPECT_TRUE(NULL == h->prev); 
	EXPECT_TRUE(NULL == h->next); 
	
	// delete only node in list
	val = dll.deleteNode(3);
	EXPECT_EQ(3, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(NULL == h); 
	
	// delete node that doesn't exist in empty list
	val = dll.deleteNode(5);
	EXPECT_EQ(-1, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(NULL == h); 
}

TEST(Test4_DoublyLinkedQueue, StandardQueueOps) {
	DoublyLinkedQueue q;
	int val = -1;
	
	// enqueue, size, isEmpty
	q.enqueue(1);
	EXPECT_EQ(1, q.size()); 
	EXPECT_TRUE(false == q.isEmpty()); 
	q.enqueue(2);
	EXPECT_EQ(2, q.size()); 
	EXPECT_TRUE(false == q.isEmpty()); 
	
	// dequeue
	val = q.dequeue();
	EXPECT_EQ(1, val); 
	EXPECT_EQ(1, q.size()); 
	EXPECT_TRUE(false == q.isEmpty()); 
	val = q.dequeue();
	EXPECT_EQ(2, val); 
	EXPECT_EQ(0, q.size()); 
	EXPECT_TRUE(true == q.isEmpty()); 
	
	// both
	for (int i = 1; i <= 5; i++) {
		q.enqueue(i);
		EXPECT_EQ(i, q.size()); 
	}
	for (int i = 5; i >= 1; i--) {
		val = q.dequeue();
		EXPECT_EQ(5 - i + 1, val); 
		EXPECT_EQ(i - 1, q.size()); 
	}
	
	// clear
	for (int i = 1; i <= 5; i++) {
		q.enqueue(i);
		EXPECT_EQ(i, q.size()); 
	}
	EXPECT_EQ(5, q.size()); 
	q.clear();
	EXPECT_EQ(0, q.size()); 
}

TEST(Test5_DoublyLinkedQueue, removeDivisibleBy) {
	Node * h = NULL, * t = NULL, * one = NULL, * two = NULL, * three = NULL, * four = NULL;
	DoublyLinkedQueue q;
	
	// build list
	one = new Node;
	one->value = 1;
	one->prev = NULL;
	two = new Node;
	two->value = 2;
	one->next = two;
	two->prev = one;
	three = new Node;
	three->value = 3;
	two->next = three;
	three->prev = two;
	four = new Node;
	four->value = 4;
	four->prev = three;
	three->next = four;
	four->next = NULL;
	q = DoublyLinkedQueue();
	q.setHeadAndTail(one, four);
	
	// removeDivisibleBy
	q.removeDivisibleBy(2);
	// check the linked list (so doesn't require other queue ops done)
	h = q.getHead();
	t = q.getTail();
	EXPECT_EQ(h, one); 
	EXPECT_EQ(t, three); 
	EXPECT_EQ(1, h->value); 
	EXPECT_EQ(3, t->value); 
	EXPECT_TRUE(NULL == h->prev); 
	EXPECT_EQ(three, h->next); 
	EXPECT_EQ(one, t->prev); 
	EXPECT_TRUE(NULL == t->next); 
	q.destroyList();
	
	// build list
	one = new Node;
	one->value = 1;
	one->prev = NULL;
	two = new Node;
	two->value = 2;
	one->next = two;
	two->prev = one;
	three = new Node;
	three->value = 3;
	two->next = three;
	three->prev = two;
	four = new Node;
	four->value = 4;
	four->prev = three;
	three->next = four;
	four->next = NULL;
	q = DoublyLinkedQueue();
	q.setHeadAndTail(one, four);
	
	// removeDivisibleBy
	q.removeDivisibleBy(3);
	// check the linked list (so doesn't require other queue ops done)
	h = q.getHead();
	t = q.getTail();
	EXPECT_EQ(h, one); 
	EXPECT_EQ(t, four); 
	EXPECT_EQ(1, h->value); 
	EXPECT_EQ(4, t->value); 
	EXPECT_TRUE(NULL == h->prev); 
	EXPECT_EQ(two, h->next); 
	EXPECT_EQ(two, t->prev); 
	EXPECT_TRUE(NULL == t->next); 
}

TEST(Test6_Sieve, computePrimes) {
	Sieve s;
	int numPrimes = 0;
	double primesPercent = 0.0;
	
	s.setN(20);
	s.computePrimes();
	numPrimes = s.reportResults(primesPercent);
	EXPECT_EQ(8, numPrimes); 
	EXPECT_DOUBLE_EQ(40, primesPercent);
	
	s.setN(100);
	s.computePrimes();
	numPrimes = s.reportResults(primesPercent);
	EXPECT_EQ(25, numPrimes); 
	EXPECT_DOUBLE_EQ(25, primesPercent);
	
	s.setN(1000);
	s.computePrimes();
	numPrimes = s.reportResults(primesPercent);
	EXPECT_EQ(168, numPrimes); 
	EXPECT_DOUBLE_EQ(16.8, primesPercent);
}

// BONUS: this last test is for the BONUS task
// which is implementing additional DoublyLinkedList member functions
TEST(BONUSTest7_DoublyLinkedList, BONUSAddToFront) {
	Node * h = NULL, * t = NULL;
	DoublyLinkedList dll;
	
	// insert into empty list
	dll.addToFront(1);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_TRUE(NULL == h->next); 
	}
	
	// insert into non empty list
	dll.addToFront(3);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(3, h->value); 
		EXPECT_EQ(1, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(t, h->next); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(h, t->prev); 
	}
	
	// insert into non empty list
	dll.addToFront(5);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(5, h->value); 
		EXPECT_EQ(1, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(3, h->next->value); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(3, t->prev->value); 
	}
}

// BONUS: this last test is for the BONUS task
// which is implementing additional DoublyLinkedList member functions
TEST(BONUSTest8_DoublyLinkedList, BONUSDeleteAtEnd) {
	Node * h = NULL, * t = NULL, * one = NULL, * two = NULL, * three = NULL;
	DoublyLinkedList dll;
	int val = -1;
	
	// delete at end
	one = new Node;
	one->value = 1;
	one->prev = NULL;
	two = new Node;
	two->value = 2;
	one->next = two;
	two->prev = one;
	three = new Node;
	three->value = 3;
	two->next = three;
	three->prev = two;
	three->next = NULL;
	dll = DoublyLinkedList();
	dll.setHeadAndTail(one, three);
	
	val = dll.deleteAtEnd();
	EXPECT_EQ(3, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, one); 
	EXPECT_EQ(t, two); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_EQ(2, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(two, h->next); 
		EXPECT_EQ(one, t->prev); 
		EXPECT_TRUE(NULL == t->next); 
	}
	
	val = dll.deleteAtEnd();
	EXPECT_EQ(2, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_TRUE(NULL == h->next); 
	}
	
	val = dll.deleteAtEnd();
	EXPECT_EQ(1, val); 
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(NULL == h); 
}

// BONUS: this last test is for the BONUS task
// which is implementing additional DoublyLinkedList member functions
TEST(BONUSTest9_DoublyLinkedList, BONUSInsertInOrder) {
	Node * h = NULL, * t = NULL;
	DoublyLinkedList dll;
	
	// insert in order
	dll = DoublyLinkedList();
	dll.insertInOrder(3);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_EQ(h, t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(3, h->value); 
		EXPECT_EQ(3, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_TRUE(NULL == h->next); 
	}
	
	dll.insertInOrder(1);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_EQ(3, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(t, h->next); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(h, t->prev); 
	}
	
	dll.insertInOrder(5);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_EQ(5, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(3, h->next->value); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(3, t->prev->value); 
	}
	
	dll.insertInOrder(4);
	h = dll.getHead();
	t = dll.getTail();
	EXPECT_TRUE(h != t); 
	EXPECT_TRUE(h != NULL);
	if (h != NULL) {
		EXPECT_EQ(1, h->value); 
		EXPECT_EQ(5, t->value); 
		EXPECT_TRUE(NULL == h->prev); 
		EXPECT_EQ(3, h->next->value); 
		EXPECT_TRUE(NULL == t->next); 
		EXPECT_EQ(4, t->prev->value); 
	}
}
