#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
// TODO: add your additional function prototypes here
void displayStats (const Package arr[] , int * numPackages , int * heaviestId , double * heaviestWeight , double * avgWeight , string * driverName);

#endif
