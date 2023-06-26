#include "Sieve.h"

//dvc
Sieve::Sieve() {
	n = 0;
	numsQ = new DoublyLinkedQueue();
	primesQ = new DoublyLinkedQueue();
}

//destructor
Sieve::~Sieve() {
	if (numsQ != NULL) {
		delete numsQ;
	}
	if (primesQ != NULL) {
		delete primesQ;
	}
}

//returns n
int Sieve::getN() const {
	return n;
}

//sets n
void Sieve::setN(int nParam) {
	n = nParam;
}

/*************************************************************
 * Function: computePrimes()
 * Date Created: 04/26/2023
 * Date Last Modified: 04/26/2023
 * Description: Combines all functions to complete the task
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: task completed
 **********************************************************/
void Sieve::computePrimes() {
    int p = 0;
    numsQ->clear();
    primesQ->clear();
    Sieve::fillWithNumbers(n);

    do {
    p = numsQ->dequeue();
    numsQ->removeDivisibleBy(p);
    primesQ->enqueue(p);
    } while (p < sqrt(n));
    Sieve::copyList();
}

//prints the report
int Sieve::reportResults(double& primePercent) {
	int numPrimes = 0;
	
	cout << "Primes up to " << n << " are as follows: " << endl;
	primesQ->displayQueue();
	
	numPrimes = primesQ->size();
	primePercent = static_cast<double>(numPrimes) / n * 100;
	
	return numPrimes;
}

//runs the programm
void Sieve::run() {
	int numPrimes = 0;
	double primePercent = 0.0;
	
	computePrimes();
	numPrimes = reportResults(primePercent);
	cout << numPrimes << " / " << n << " = " << primePercent << "% primes" << endl;
}

/*************************************************************
 * Function: fillWithNumbers()
 * Date Created: 04/26/2023
 * Date Last Modified: 04/26/2023
 * Description: fills numsQ with numbers from 2 to n
 * Input parameters: int n
 * Returns: -
 * Pre: n >= 2
 * Post: numsQ filled
 **********************************************************/
void Sieve::fillWithNumbers (int n) {
    for (int i = 2 ; i <= n ; i++) {
        numsQ->enqueue(i);
    }
}

/*************************************************************
 * Function: copyList()
 * Date Created: 04/26/2023
 * Date Last Modified: 04/26/2023
 * Description: copies remain content from numsQ to primesQ
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: content copied
 **********************************************************/
void Sieve::copyList () {
    Node * currNode = numsQ->getHead();

    while (currNode->next != NULL) {
        primesQ->enqueue(currNode->value);
        currNode = currNode->next;
    }
    primesQ->enqueue(currNode->value);
}