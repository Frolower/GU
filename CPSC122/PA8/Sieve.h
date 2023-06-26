/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 26, 2023
 Programming Assignment: PA8
 Description: Prime Numbers
 Notes: -
*/

#ifndef SIEVE_H
#define SIEVE_H

#include <iostream>
#include <cmath>
#include "DoublyLinkedQueue.h"

using namespace std;

class Sieve {
	private:
		int n;
		DoublyLinkedQueue * numsQ; 
		DoublyLinkedQueue * primesQ;
	public:
		Sieve(); // DVC
		Sieve(string); // EVC
		~Sieve(); // destructor
		int getN() const;
		void setN(int);
		void computePrimes();
		int reportResults(double&);
		void run();
        void fillWithNumbers (int n);
        void copyList ();
};

#endif
