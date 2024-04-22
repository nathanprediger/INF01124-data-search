#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utils.h"

using namespace std;

int lomuto(int arr[], int left, int right, Test_info *test_data) {
    int chave = arr[left];
    int storeindex = left + 1; // Index of smaller element
    
    for (int i = left + 1; i <= right; i++) {
        // If current element is smaller than or equal to pivot
        if (arr[i] < chave) {
            swap(arr, i, storeindex);
            test_data->swaps++;
            storeindex++; // increment index of smaller element
        }
    }
    swap(arr, left, storeindex - 1);
    test_data->swaps++;

    return (storeindex - 1);
}

int hoare(int arr[], int left, int right, Test_info *test_data) {
    int chave, i, j;
    chave = arr[left];
    i = left; 
    j = right;

    while (i < j) {
        while (arr[j] > chave && i < j) j--;
        arr[i] = arr[j];
        test_data->swaps++;
        while (arr[i] <= chave && i < j) i++;
        arr[j] = arr[i];
        test_data->swaps++;
    }
    arr[j] = chave;
    test_data->swaps++;

    return i;
}

int partition(int arr[], int i, int f, Test_info *test_data) {
    if (test_data->partitioning == HOARE)
        return hoare(arr, i, f, test_data);

    return lomuto(arr, i, f, test_data);
}

void quicksort(int arr[], int i, int f, Test_info *test_data) {
    int p, r;

    test_data->recursions++;
    if (f > i) {
        if (test_data->partitioner == MEDIAN)
            p = median3(arr, i, f);
        else
            p = get_random_number(i, f);
            
        swap(arr, i, p); // puts partitioner element at the first position of sub-array
        test_data->swaps++;

        r = partition(arr, i, f, test_data);
        quicksort(arr, i, r - 1, test_data);
        quicksort(arr, r + 1, f, test_data);
    }
}
