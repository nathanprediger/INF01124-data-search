#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// partitioning algorithms
#define LOMUTO 'L'
#define HOARE 'H'
// partiotioner choices
#define RANDOM 'R'
#define MEDIAN 'M'

using namespace std;

// return position of last smaller element of partition
int lomuto(int arr[], int left, int right) {
    int chave = arr[left];
    int storeindex = left + 1; // Index of smaller element
    
    for (int i = left + 1; i <= right; i++) {
        // If current element is smaller than or equal to pivot
        if (arr[i] < chave) {
            swap(arr, i, storeindex);
            storeindex++; // increment index of smaller element
        }
    }
    swap(arr, left, storeindex - 1);

    return (storeindex - 1);
}

// return position of last smaller element of partition
int hoare(int arr[], int left, int right) {
    int chave, i, j;
    chave = arr[left]; 
    i = left; 
    j = right;

    while (i < j) {
        while (arr[j] > chave && i < j) j--;
        arr[i] = arr[j];
        while (arr[i] <= chave && i < j) i++;
        arr[j] = arr[i];
    }
    arr[j] = chave;

    return i;
}

int partition(int arr[], int i, int f, int partitioning) {
    if (partitioning == HOARE)
        return hoare(arr, i, f);

    return lomuto(arr, i, f);
}

/*!*****************************************************************************
 * @brief quicksort with different partiotioning and partioner algorithms
 * @param arr: array to be sorted
 * @param i: index of array first element
 * @param f: index of array last element
 * @param partitioner: RANDOM/MEDIAN
 * @param partitioning: LOMUTO/HOARE
 *******************************************************************************/
void quicksort(int arr[], int i, int f, char partitioner, char partiotining) {
    char p, r;

    if (f > i) {
        p = (partitioner == MEDIAN) ? median3(arr, i, f) : random_number(i, f);
        swap(arr, i, p); // puts partitioner element at the first position of sub-array

        r = partition(arr, i, f, partiotining);
        quicksort(arr, i, r - 1, partitioner, partiotining);
        quicksort(arr, r + 1, f, partitioner, partiotining);
    }
}

int main() {
    int arr[] = {4, 3, 2, 1, 3, 5, 2, 4, 1, 7, 2, 3, 9, 6, 8, 7, 5, 4, 6, 7, 8, 5, 56, 73, 2, 12, 122, 67, 98, 45, 432, 66, 89, 0, 32};
    int arr_size = sizeof(arr) / sizeof(int);
    int last_smaller = 0;


    for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);

    // quicksort(arr, 0, arr_size - 1, RANDOM, HOARE);
    // quicksort(arr, 0, arr_size - 1, RANDOM, LOMUTO);
    // quicksort(arr, 0, arr_size - 1, MEDIAN, HOARE);
    quicksort(arr, 0, arr_size - 1, MEDIAN, LOMUTO);

    printf("\n");
    for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);
}