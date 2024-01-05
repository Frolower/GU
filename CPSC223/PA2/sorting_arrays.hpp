#ifndef SORTING_ARRAYS_HPP
#define SORTING_ARRAYS_HPP


class Sort {
public:
    void quick_sort(int arr[], int size);
    void merge_sort(int arr[], int size);
    void print_array(int arr[], int size);
    void insertion_sort(int arr[], int size);
    
private: 
    void merge_sort(int arr[], int left, int right);
    void quick_sort(int arr[], int left, int right);
    int partition (int arr[], int low, int high);
    void swap(int* a, int* b);
    void merge(int *arr, int low, int high, int mid);
};
#endif