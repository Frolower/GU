#include <iostream>
#include "sorting_arrays.hpp"

using namespace std;

void Sort::print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// setup function
void Sort::quick_sort(int arr[], int size) {
    quick_sort(arr, 0, size - 1);
}

void Sort::quick_sort(int arr[], int left, int right) {
    if (left < right) {
        //splitting the array
        int pivot = partition(arr, left, right);

        //sorting each sub array
        quick_sort(arr , left , pivot - 1);
        quick_sort(arr , pivot + 1 , right);
    }
}

int Sort::partition (int arr[] , int left , int right) {
    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

//helper swap function
void Sort::swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// setup function
void Sort::merge_sort(int arr[] , int size) {
    // call recusive merge_sort here
    merge_sort(arr, 0 , size - 1);
}

void Sort::merge_sort(int arr[] , int left , int right) {
    int mid;
    if (left < right){

        //deviding array to do a separate sort

        mid=(left + right) / 2;
        merge_sort(arr , left , mid);
        merge_sort(arr ,mid + 1 , right);
        //merge or conquer sorted arrays
        merge(arr,left,right,mid);
    }
}

void Sort::merge(int *arr , int left , int right , int mid)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int c[50];
    i = left;
    k = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)  {
        arr[i] = c[i];
    }
}

void Sort::insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
