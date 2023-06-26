/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: February 10, 2023
 Programming Assignment: PA2
 Description: This program researches sorting algorithms
 Notes: -
*/

#include "SortingAnalysisHeader.h"

/*************************************************************
 * Function: generateSortedVector()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: generating vector from 0 to N
 * Input parameters: vector to fill, number of elements
 * Returns: Nothing
 * Pre: vector must exist
 * Post: vector is filled
 *************************************************************/
void generateSortedVector (vector <int>& vec , int numElm) {
    for (int i = 0; i < numElm; i++) {
        vec.push_back(i);
    }
}

/*************************************************************
 * Function: generateDescendingSortedVector()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: generating vector from N to 0
 * Input parameters: vector to fill, number of elements
 * Returns: Nothing
 * Pre: vector must exist
 * Post: vector is filled
 *************************************************************/
void generateDescendingSortedVector (vector <int>& vec , int numElm) {
    for (int i = numElm; i > 0; i--) {
        vec.push_back(i);
    }
}

/*************************************************************
 * Function: generateRandomVector()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: generating vector with random values from 1 to 10000
 * Input parameters: vector to fill, number of elements
 * Returns: Nothing
 * Pre: vector must exist
 * Post: vector is filled
 *************************************************************/
void generateRandomVector (vector <int>& vec , int numElm) {
    srand (time(NULL));
    for (int i = 0; i < numElm; i++) {
        vec.push_back(rand() % 10000 + 1);
    }
}

/*************************************************************
 * Function: copyVector()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: copied values from one vector to another
 * Input parameters: vector to copy , vector to copy in
 * Returns: Nothing
 * Pre: vectors must exist
 * Post: vector is copied
 *************************************************************/
void copyVector (vector <int>& vec, vector <int>& copy) {
    for (int i = 0; i < vec.size(); i++) {
        copy.at(i) = vec.at(i);
    }
}

/*************************************************************
 * Function: testSortingAlgorithms()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: holds all vectors and functions that needed to generate final stats
 * Input parameters: ofstream&
 * Returns: Nothing
 * Pre: -
 * Post: output in output.csv
 *************************************************************/
void testSortingAlgorithms(ofstream& outfile) {

    vector <int> unsorted500;
    vector <int> unsorted1000;
    vector <int> unsorted5000;
    vector <int> unsorted10000;
    vector <int> unsorted500copy;
    vector <int> unsorted1000copy;
    vector <int> unsorted5000copy;
    vector <int> unsorted10000copy;

    vector <int> sorted500;
    vector <int> sorted1000;
    vector <int> sorted5000;
    vector <int> sorted10000;

    vector <int> descendingSorted500;
    vector <int> descendingSorted1000;
    vector <int> descendingSorted5000;
    vector <int> descendingSorted10000;
    vector <int> descendingSorted500copy;
    vector <int> descendingSorted1000copy;
    vector <int> descendingSorted5000copy;
    vector <int> descendingSorted10000copy;

    generateSortedVector(sorted500 , 500);
    generateSortedVector(sorted1000 , 1000);
    generateSortedVector(sorted5000 , 5000);
    generateSortedVector(sorted10000 , 10000);

    generateDescendingSortedVector(descendingSorted500 , 500);
    generateDescendingSortedVector(descendingSorted1000 , 1000);
    generateDescendingSortedVector(descendingSorted5000 , 5000);
    generateDescendingSortedVector(descendingSorted10000 , 10000);

    generateDescendingSortedVector(descendingSorted500copy , 500);
    generateDescendingSortedVector(descendingSorted1000copy , 1000);
    generateDescendingSortedVector(descendingSorted5000copy , 5000);
    generateDescendingSortedVector(descendingSorted10000copy , 10000);

    generateRandomVector(unsorted500 , 500);
    generateRandomVector(unsorted1000 , 1000);
    generateRandomVector(unsorted5000 , 5000);
    generateRandomVector(unsorted10000 , 10000);

    generateRandomVector(unsorted500copy , 500);
    generateRandomVector(unsorted1000copy , 1000);
    generateRandomVector(unsorted5000copy , 5000);
    generateRandomVector(unsorted10000copy , 10000);

    outfile << "Selection sort" << endl;
    outfile << "Vector configuration, Microseconds, #Data Comparisons, #Loop Comparisons, #Data Comparisons, #Loop Assignments, #Other, #Total" << endl;

    generateStatsSelection(outfile , sorted500 , "Sorted");
    generateStatsSelection(outfile , sorted1000 , "Sorted");
    generateStatsSelection(outfile , sorted5000 , "Sorted");
    generateStatsSelection(outfile , sorted10000 , "Sorted");

    copyVector(descendingSorted500 , descendingSorted500copy);
    generateStatsSelection(outfile , descendingSorted500copy , "Descending Sorted");
    copyVector(descendingSorted1000 , descendingSorted1000copy);
    generateStatsSelection(outfile , descendingSorted1000copy , "Descending Sorted");
    copyVector(descendingSorted5000 , descendingSorted5000copy);
    generateStatsSelection(outfile , descendingSorted5000copy , "Descending Sorted");
    copyVector(descendingSorted10000 , descendingSorted10000copy);
    generateStatsSelection(outfile , descendingSorted10000copy , "Descending Sorted");

    copyVector(unsorted500 , unsorted500copy);
    generateStatsSelection(outfile , unsorted500copy , "Unsorted");
    copyVector(unsorted1000 , unsorted1000copy);
    generateStatsSelection(outfile , unsorted1000copy , "Unsorted");
    copyVector(unsorted5000 , unsorted5000copy);
    generateStatsSelection(outfile , unsorted5000copy , "Unsorted");
    copyVector(unsorted10000 , unsorted10000copy);
    generateStatsSelection(outfile , unsorted10000copy , "Unsorted");

    outfile << endl << "Bubble sort" << endl;
    outfile << "Vector configuration, Microseconds, #Data Comparisons, #Loop Comparisons, #Data Comparisons, #Loop Assignments, #Other, #Total" << endl;

    generateStatsBubble(outfile , sorted500 , "Sorted");
    generateStatsBubble(outfile , sorted1000 , "Sorted");
    generateStatsBubble(outfile , sorted5000 , "Sorted");
    generateStatsBubble(outfile , sorted10000 , "Sorted");

    copyVector(descendingSorted500 , descendingSorted500copy);
    generateStatsBubble(outfile , descendingSorted500copy , "Descending Sorted");
    copyVector(descendingSorted1000 , descendingSorted1000copy);
    generateStatsBubble(outfile , descendingSorted1000copy , "Descending Sorted");
    copyVector(descendingSorted5000 , descendingSorted5000copy);
    generateStatsBubble(outfile , descendingSorted5000copy , "Descending Sorted");
    copyVector(descendingSorted10000 , descendingSorted10000copy);
    generateStatsBubble(outfile , descendingSorted10000copy , "Descending Sorted");

    copyVector(unsorted500 , unsorted500copy);
    generateStatsBubble(outfile , unsorted500copy , "Unsorted");
    copyVector(unsorted1000 , unsorted1000copy);
    generateStatsBubble(outfile , unsorted1000copy , "Unsorted");
    copyVector(unsorted5000 , unsorted5000copy);
    generateStatsBubble(outfile , unsorted5000copy , "Unsorted");
    copyVector(unsorted10000 , unsorted10000copy);
    generateStatsBubble(outfile , unsorted10000copy , "Unsorted");

    outfile << endl << "Insertion sort" << endl;
    outfile << "Vector configuration, Microseconds, #Data Comparisons, #Loop Comparisons, #Data Comparisons, #Loop Assignments, #Other, #Total" << endl;

    generateStatsInsertion(outfile , sorted500 , "Sorted");
    generateStatsInsertion(outfile , sorted1000 , "Sorted");
    generateStatsInsertion(outfile , sorted5000 , "Sorted");
    generateStatsInsertion(outfile , sorted10000 , "Sorted");

    copyVector(descendingSorted500 , descendingSorted500copy);
    generateStatsInsertion(outfile , descendingSorted500copy , "Descending Sorted");
    copyVector(descendingSorted1000 , descendingSorted1000copy);
    generateStatsInsertion(outfile , descendingSorted1000copy , "Descending Sorted");
    copyVector(descendingSorted5000 , descendingSorted5000copy);
    generateStatsInsertion(outfile , descendingSorted5000copy , "Descending Sorted");
    copyVector(descendingSorted10000 , descendingSorted10000copy);
    generateStatsInsertion(outfile , descendingSorted10000copy , "Descending Sorted");

    copyVector(unsorted500 , unsorted500copy);
    generateStatsInsertion(outfile , unsorted500copy , "Unsorted");
    copyVector(unsorted1000 , unsorted1000copy);
    generateStatsInsertion(outfile , unsorted1000copy , "Unsorted");
    copyVector(unsorted5000 , unsorted5000copy);
    generateStatsInsertion(outfile , unsorted5000copy , "Unsorted");
    copyVector(unsorted10000 , unsorted10000copy);
    generateStatsInsertion(outfile , unsorted10000copy , "Unsorted");

}

/*************************************************************
 * Function: generateStatsSelection()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: measuring time to complete selection sort
 * Input parameters: ofstream& outfile , vector <int>& vec , string type
 * Returns: Nothing
 * Pre: output file must be opened
 * Post: stats generated and written to the file
 *************************************************************/
void generateStatsSelection(ofstream& outfile , vector <int>& vec , string type) {

    long dataComp = 0;
    long loopComp = 0;
    long dataAssign = 0;
    long loopAssign = 0;
    long other = 0;

    auto start = high_resolution_clock::now();
    selectionSortVector(vec , dataComp , loopComp , dataAssign , loopAssign , other);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long durCount = duration.count();
    writeStats(outfile , type , vec , dataComp , loopComp , dataAssign , loopAssign , other , durCount);
}

/*************************************************************
 * Function: generateStatsBubble()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: measuring time to complete bubble sort
 * Input parameters: ofstream& outfile , vector <int>& vec , string type
 * Returns: Nothing
 * Pre: output file must be opened
 * Post: stats generated and written to the file
 *************************************************************/
void generateStatsBubble(ofstream& outfile , vector <int>& vec , string type) {

    long dataComp = 0;
    long loopComp = 0;
    long dataAssign = 0;
    long loopAssign = 0;
    long other = 0;

    auto start = high_resolution_clock::now();
    bubbleSortVector(vec , dataComp , loopComp , dataAssign , loopAssign , other);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long durCount = duration.count();
    writeStats(outfile , type , vec , dataComp , loopComp , dataAssign , loopAssign , other , durCount);
}

/*************************************************************
 * Function: writeStats()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: writing the output
 * Input parameters: ofstream& outfile , string type , vector <int>& vec , long dataComp , long loopComp , long dataAssign , long loopAssign , long other , long long durCount
 * Returns: Nothing
 * Pre: output file must be opened, only after sorting function
 * Post: stats written to the file
 *************************************************************/
void writeStats(ofstream& outfile , string type , vector <int>& vec , long dataComp , long loopComp , long dataAssign , long loopAssign , long other , long long durCount) {
    outfile << type << " N = " << vec.size() << ", " << durCount << ", " << dataComp << ", " << loopComp << ", " << dataAssign << ", " << loopAssign << ", " << other << ", " << dataComp + loopComp + dataAssign + loopAssign + other << endl;
}

/*************************************************************
 * Function: generateStatsInsertion()
 * Date Created: 06/02/2023
 * Date Last Modified: 10/02/2023
 * Description: measuring time to complete insertion sort
 * Input parameters: ofstream& outfile , vector <int>& vec , string type
 * Returns: Nothing
 * Pre: output file must be opened
 * Post: stats generated and written to the file
 *************************************************************/
void generateStatsInsertion(ofstream& outfile , vector <int>& vec , string type) {

    long dataComp = 0;
    long loopComp = 0;
    long dataAssign = 0;
    long loopAssign = 0;
    long other = 0;

    auto start = high_resolution_clock::now();
    insertionSortVector(vec , dataComp , loopComp , dataAssign , loopAssign , other);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long durCount = duration.count();
    writeStats(outfile , type , vec , dataComp , loopComp , dataAssign , loopAssign , other , durCount);
}


// adapted from Gaddis
//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(int * a, int * b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

// adapted from Gaddis
//********************************************************************
// The selectionSort function sorts an int array in ascending order. *
//********************************************************************
void selectionSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other) {
    dataComp = 0;
    loopComp = 0;
    dataAssign = 0;
    loopAssign = 0;
    other = 0;
    int minIndex, minValue;
    other += 2; // for declaring minIndex and minValue

    loopAssign++; // for int start = 0
    for (int start = 0; start < (vec.size() - 1); start++) {
        loopComp++; // for boolean condition evaluating to true
        loopAssign++; // for start++

        minIndex = start;
        other++; // for minIndex assignment
        minValue = vec.at(start);
        dataAssign++; // for minValue assignment

        loopAssign++; // for int index = start + 1
        for (int index = start + 1; index < vec.size() - 1; index++) {
            loopComp++; // for inner loop boolean condition evaluating to true
            loopAssign++; // for index++

            dataComp++; // for if statement boolean condition
            if (vec.at(index) < minValue) {
                minValue = vec.at(index);
                dataAssign++; // for minValue assignment
                minIndex = index;
                other++; // for minIndex assignment
            }
        }
        loopComp++; // for inner loop boolean condition evaluating to false
        swap(vec.at(minIndex), vec.at(start));
        dataAssign += 3; // for 3 data assignments in swap
    }
    loopComp++; // for boolean condition evaluating to false
}

//// adapted from Gaddis
////*****************************************************************
//// The bubbleSort function sorts an int array in ascending order. *
////*****************************************************************
//
void bubbleSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other) {
    dataComp = 0;
    loopComp = 0;
    dataAssign = 0;
    loopAssign = 0;
    other = 0;
    int maxElement;
    int index;
    other += 2; //initializing variables

    loopAssign++; // initializing loop control variable
    for (maxElement = vec.size() - 1; maxElement > 0; maxElement--) {
        loopComp++; // for boolean condition evaluating to true
        loopAssign++; // maxElement--
        loopAssign++; //index = 0
        for (index = 0; index < maxElement; index++) {
            dataComp++; // for boolean condition evaluating to true
            loopAssign++; //index++
            if (vec.at(index) > vec.at(index+1)) {
                dataComp ++;
                swap(vec.at(index) , vec.at(index+1));
                dataAssign += 3;//inside swap
            }
        }
    }
    loopComp++; // for boolean condition evaluating to false;
}

/*************************************************************
 * Function: insertionSortVector()
 * Date Created: ???
 * Date Last Modified: 10/02/2023
 * Description: insertion sort vector
 * Input parameters: vector to sort & variables that counting actions inside
 * Returns: Nothing
 * Pre: -
 * Post: vector is sorted
 *************************************************************/
void insertionSortVector(vector <int>& vec , long& dataComp , long& loopComp , long& dataAssign , long& loopAssign , long& other) {
    dataComp = 0;
    loopComp = 0;
    dataAssign = 0;
    loopAssign = 0;
    other = 0;
    int j, currValue;
    loopAssign ++; // initializing loop control variable
    other ++; //initializing variable

    loopAssign ++; // initializing the loop control variable
    for (int i = 1; i < vec.size(); i++) {
        loopComp ++; // for boolean condition evaluating to true
        loopAssign ++; // for i++
        currValue = vec.at(i);
        dataAssign ++; //changing data
        j = i - 1;
        loopAssign ++; //giving the value to the loop control variable
        loopAssign ++; //initializing the loop
        while (j >= 0 && currValue < vec.at(j)) {
            loopComp ++; // for boolean condition evaluating to true
            vec.at(j + 1) = vec.at(j);
            dataComp ++; // comparing data
            j--;
            loopAssign ++; //decreasing loop control variable
        }
        loopComp ++; // for boolean condition evaluating to false

        vec.at(j + 1) = currValue;
        dataAssign ++; // changing the value in vector

    }
    loopComp ++; // for boolean condition evaluating to false
}