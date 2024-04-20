#include <stdio.h>
#include "constants.h"
#include "quicksort.h"

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
    printf("\n");
}
