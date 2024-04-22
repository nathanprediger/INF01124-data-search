#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "constants.h"
#include "quicksort.h"

#define ARR_SIZE 1000000
#define MAX_STR 100

using namespace std;

int swaps, recursions;
float exe_time;

int process_file(char path[], Test_info test_data) {
    FILE *file = fopen(path, "r");
    int arr[ARR_SIZE], arr_size = 0, n, arr_pos;
    int count = 0;

    if (!file) { 
        cout << "Unable to open file";
        return 1; 
    }

    while (fscanf(file, "%d", &n) != EOF) {
        if (arr_size == 0) {
            arr_size = n;
            arr_pos = 0;
        } else {
            arr[arr_pos] = n;
            arr_pos++;
        }

        if (arr_pos == arr_size) {
            count++;
            arr[arr_pos] = '\0';

            quicksort(arr, 0, arr_size - 1, test_data.partitioner, test_data.partitioning);

            for (int p = 0; p < arr_size; p++) printf("%d ", arr[p]);
            printf("\n");
            arr_size = 0;
            if (count == 2) break;
        }

	}

    cout << endl; 
  
    // Close the file 
    fclose(file);

	return 0;
}

// numero de trocas (swaps) entre elementos do vetor, o numero de chamadas recursivas e o tempo de execucao 
// do algoritmo em milisegundos. Estes resultados devem ser impressos no exato formato listado abaixo: ˜
// TAMANHO ENTRADA 100
// SWAPS #SWAPS
// RECURSOES #RECURSOES
// TEMPO #TEMPO EM MILISEGUNDOS

int main() {
    int i;
    char input_path[MAX_STR] = "data/inputs/entrada-quicksort.txt";

    Test_info tests[4] = {
        (Test_info) {RANDOM, LOMUTO, "aleatorio-lomuto.txt"},
        // (Test_info) {RANDOM, HOARE, "aleatorio-hoare.txt"}, 
        // (Test_info) {MEDIAN, LOMUTO, "mediana-lomuto.txt"}, 
        // (Test_info) {MEDIAN, HOARE, "mediana-hoare.txt"}
    };

    process_file(input_path, tests[0]);
    // for (i = 0; i < 4; i++) {
        // process_file(input_path, tests[i]);
    // }
    // int arr[] = {4, 3, 2, 1, 3, 5, 2, 4, 1, 7, 2, 3, 9, 6, 8, 7, 5, 4, 6, 7, 8, 5, 56, 73, 2, 12, 122, 67, 98, 45, 432, 66, 89, 0, 32};

    // int arr_size = sizeof(arr) / sizeof(int);
    // int last_smaller = 0;

    // for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);

    // // quicksort(arr, 0, arr_size - 1, RANDOM, HOARE);
    // // quicksort(arr, 0, arr_size - 1, RANDOM, LOMUTO);
    // // quicksort(arr, 0, arr_size - 1, MEDIAN, HOARE);
    // quicksort(arr, 0, arr_size - 1, MEDIAN, LOMUTO);

    // printf("\n");
    // for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);
    // printf("\n");
}
