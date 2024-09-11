#include <iostream>
#include "linked_list.hpp"
#include "sorting_arrays.hpp"

int main() {
    LinkedList list;
    Sort array_sorter;
    int array[12] = {55,24,89,65,117,25,-42,10,16,0,79,-3};
    int size = 12;

    list.push_back(55);
    list.push_back(24);
    list.push_back(89);
    list.push_back(50);
    list.push_back(93);
    list.push_back(13);
    list.push_back(43);
    list.push_back(58);
    list.push_back(65);
    list.push_back(117);
    list.push_back(25);
    list.push_back(-42);

    // Testing Merge Sorts
    list.merge_sort();
    list.display();
    /*
    array_sorter.merge_sort(array, size);
    array_sorter.print_array(array, size);

    // Reset Lists
    int array2[12] = {-42,10,16,0,79,-3,55,24,89,65,117,25};
    size = 12;

    list.clear();
    list.push_back(43);
    list.push_back(58);
    list.push_back(65);
    list.push_back(117);
    list.push_back(25);
    list.push_back(-42);
    list.push_back(55);
    list.push_back(24);
    list.push_back(89);
    list.push_back(50);
    list.push_back(93);
    list.push_back(13);


    // Testing Quick Sorts
    list.quick_sort();
    list.display();
    array_sorter.quick_sort(array2, size);
    array_sorter.print_array(array2, size);

    // Reset Lists
    int array3[12] = {55,24,89,10,16,65,117,25,-42,0,79,-3};
     size = 12;

    list.clear();
    list.push_back(55);
    list.push_back(24);
    list.push_back(89);
    list.push_back(65);
    list.push_back(50);
    list.push_back(93);
    list.push_back(13);
    list.push_back(43);
    list.push_back(58);
    list.push_back(117);
    list.push_back(25);
    list.push_back(-42);

    // Testing insertion sorts
    list.insertion_sort();
    list.display();
    array_sorter.insertion_sort(array3, size);
    array_sorter.print_array(array3, size);
*/
    return 0;
}
