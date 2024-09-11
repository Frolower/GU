// Author        : Luke Johnson
// Date Created  : 2023-09-11
// Modifier      : Nikita Dubinin
// Date Modified : 2023-09-22

#include<iostream>
#include<cstring>
#include<vector>
#include<cassert>
#include<ctime>
#include <chrono>

void sandbox(); // remember to change this if you want to add parameters

void test1();
void test2();
void test3();
void measureShrinkToFitTime();
void measureMemoryDifference();
void printMaxSizes();

int main(int argc, char* argv[]) { 
    if(argc == 1) { 
        sandbox();
        return 0;
    }
    else if (argc == 2) {
        if (strcmp(argv[1], "test1") == 0) {
            test1();
            return 0;
        }
        else if (strcmp(argv[1], "test2") == 0) {
            test2();
            return 0;
        }
        else if (strcmp(argv[1], "test3") == 0) {
            test3();
            return 0;
        }
        else { 
            return -1;
        }
    }
    else {
        return -1;
    }
}

void sandbox() {
    measureShrinkToFitTime();
    measureMemoryDifference();
    printMaxSizes();
}

void test1() { 
    std::vector<int> five_numbers = {12345, 23456, 34567, 1887, 0};
    std::vector<bool> four_truths = {0,0,1,0};
    std::vector<char> place_holder = {'a','b','c'};
    assert(five_numbers.capacity() < four_truths.capacity() ); // modify placeholder to make the assert true (not using placeholder)
}

void test2() { 
    std::vector<int> six_numbers = {1,2,3,4,5,6};
    six_numbers.pop_back();
    six_numbers.pop_back();
    six_numbers.resize(10,0);
    assert(six_numbers.capacity() == 10); // change the integer value here so the assert is true.
}

void test3() { 
    std::vector<int> numbers = {0};
    std::vector<int> numbers_too = {0};
    // Using a for loop that only uses the built-in function resize, make numbers equal to numbers_too
    for (int index = 1; index <= 100000; index++) {
        numbers.resize(index+1 , index);
    }

    for (int index_too = 1; index_too <= 100000; index_too++) {
        numbers_too.push_back(index_too);
    }

    assert(numbers==numbers_too);
}

//this function measures time for both unshrinked array and for shrinked array
void measureShrinkToFitTime() {

    std::vector<int> vec = {};

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 50000; ++i) {
        vec.push_back(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken without shrink_to_fit(): " << duration.count() << " milliseconds" << std::endl;

    vec.clear();

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 50000; ++i) {
        vec.push_back(i);
        vec.shrink_to_fit();
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken with shrink_to_fit(): " << duration.count() << " milliseconds" << std::endl;
}

//getting the memory allocated for each vector and print it
void measureMemoryDifference() {

    std::vector<bool> boolVector(10000);
    std::vector<char> charVector(10000);

    std::cout << "Memory used by bool vector: " << boolVector.capacity() << " bytes" << std::endl;
    std::cout << "Memory used by char vector: " << charVector.capacity() << " bytes" << std::endl;
    std::cout << "Memory difference: " << boolVector.capacity() - charVector.capacity() << " bytes" << std::endl;
}

//this function shows a maximum size of the vector with built in c++ function
void printMaxSizes() {

    std::cout << "Max size of int vector: " << std::vector<int>().max_size() << std::endl;
    std::cout << "Max size of char vector: " << std::vector<char>().max_size() << std::endl;
    std::cout << "Max size of long vector: " << std::vector<long>().max_size() << std::endl;
    std::cout << "Max size of double vector: " << std::vector<double>().max_size() << std::endl;
    std::cout << "Max size of int* vector: " << std::vector<int*>().max_size() << std::endl;
}