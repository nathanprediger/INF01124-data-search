#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utils.h"

using namespace std;

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

void quicksort(int arr[], int i, int f, char partitioner, char partiotining) {
    int p, r;

    if (f > i) {
        if (partitioner == MEDIAN)
            p = median3(arr, i, f);
        else
            p = get_random_number(i, f);
            
        swap(arr, i, p); // puts partitioner element at the first position of sub-array

        r = partition(arr, i, f, partiotining);
        quicksort(arr, i, r - 1, partitioner, partiotining);
        quicksort(arr, r + 1, f, partitioner, partiotining);
    }
}
