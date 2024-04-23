#define MAX_ARR 100000
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void swap(int arr[], int i, int f) {
    int aux;

    aux = arr[i];
    arr[i] = arr[f];
    arr[f] = aux; 
}

int lomuto(int arr[], int left, int right) {
    int chave = arr[left];
    int storeindex = left + 1; // Index of smaller element
    
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] < chave) {
            swap(arr, i, storeindex);
            storeindex++;
        }
    }
    swap(arr, left, storeindex - 1);

    return (storeindex - 1);
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void quicksort(int arr[], int i, int f) {
    int p, r;

    if (f > i) {
        p = get_random_number(i, f);
        swap(arr, i, p);
        r = lomuto(arr, i, f);
        quicksort(arr, i, r - 1);
        quicksort(arr, r + 1, f);
    }
}

int main() {
    int n, size = 0, even_c = 0, odd_c = 0;
    int arr_odd[MAX_ARR], arr_even[MAX_ARR];

    scanf("%d", &size);

    for (int j = 0; j < size; j++) {
        scanf("%d", &n);

        if (n % 2 == 0)
            arr_even[even_c++] = n;
        else
            arr_odd[odd_c++] = n;
    }

    quicksort(arr_even, 0, even_c - 1);
    quicksort(arr_odd, 0, odd_c - 1);

    for (int j = 0; j < even_c; j++)
        printf("%d\n", arr_even[j]);

    for (int j = 0; j < odd_c; j++) 
        printf("%d\n", arr_odd[odd_c - j - 1]);
}