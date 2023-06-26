/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: February 10, 2023
 Programming Assignment: PA2
 Description: This program researches sorting algorithms
 Notes: -
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

// helper
void testSortingAlgorithms(ofstream& outfile);
void generateRandomVector (vector <int>& vec , int numElm);
void generateDescendingSortedVector (vector <int>& vec , int numElm);
void generateSortedVector (vector <int>& vec , int numElm);
void copyVector (vector <int>& vec, vector <int>& copy);
void generateStatsSelection(ofstream& outfile , vector <int>& vec , string type);
void generateStatsBubble(ofstream& outfile , vector <int>& vec , string type);
void generateStatsInsertion(ofstream& outfile , vector <int>& vec , string type);
void writeStats(ofstream& outfile , string type , vector <int>& vec , long dataComp , long loopComp , long dataAssign , long loopAssign , long other , long long durCount);
void swap(int * a, int * b);

// sorting
void selectionSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other);
void bubbleSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other);
void insertionSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other);