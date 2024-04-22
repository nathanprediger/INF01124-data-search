#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include "constants.h"
#include "quicksort.h"

#define ARR_SIZE 1000001
#define MAX_STR 200

using namespace std;

void open_output_files(Test_info tests[], int n_tests) {
    int j;
    char path[MAX_STR];

    for (j = 0; j < n_tests; j++) {  
        sprintf(path, "data/outputs/%s", tests[j].output_file);
        tests[j].file_stream = fopen(path, "w");
    }
}

void close_output_files(Test_info tests[], int n_tests) {
    for (int j = 0; j < n_tests; j++) 
        fclose(tests[j].file_stream);
}

void write_output(Test_info test_data) {
    // TAMANHO ENTRADA 100
    fprintf(test_data.file_stream, "TAMANHO ENTRADA %d\n", test_data.size);
    // SWAPS #SWAPS
    fprintf(test_data.file_stream, "SWAPS %d\n", test_data.swaps);
    // RECURSOES #RECURSOES
    fprintf(test_data.file_stream, "RECURSOES %d\n", test_data.recursions);
    // TEMPO #TEMPO EM MILISEGUNDOS
    fprintf(test_data.file_stream, "TEMPO %dms\n", test_data.exe_time);
}

int process_file(char path[], Test_info *test_data) {
    // for execution time perf
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    FILE *file = fopen(path, "r");
    int arr[ARR_SIZE];
    int arr_size = 0, n, arr_pos;

    if (!file) { 
        std::cout << "Unable to open file";
        return 1; 
    }

    while (!feof(file)) {
        fscanf(file, "%d", &n);

        if (arr_size == 0) {
            arr_size = n;
            arr_pos = 0;
        } else {
            arr[arr_pos] = n;
            arr_pos++;
        }

        // if it has finished reading array
        if (arr_pos == arr_size) {
            arr[arr_pos] = '\0';
            test_data->size = arr_size;
            auto x = high_resolution_clock::now();
            quicksort(arr, 0, arr_size - 1, test_data);
            test_data->exe_time = duration_cast<milliseconds>(high_resolution_clock::now() - x).count();
            write_output(*test_data);
            // for (int j = 0; j < arr_size; j++) printf("%d ", arr[j]);
            arr_size = 0;
        }

        // reads /n
        fgetc(file);
	}

    fclose(file);

	return 0;
}

int main() {
    int i, n_tests = 4;
    char input_path[MAX_STR] = "data/inputs/entrada-quicksort.txt";

    Test_info tests[4] = {
        (Test_info) {RANDOM, LOMUTO, "aleatorio-lomuto.txt", NULL, 0,0,0,0},
        (Test_info) {RANDOM, HOARE, "aleatorio-hoare.txt", NULL, 0,0,0,0}, 
        (Test_info) {MEDIAN, LOMUTO, "mediana-lomuto.txt", NULL, 0,0,0,0}, 
        (Test_info) {MEDIAN, HOARE, "mediana-hoare.txt", NULL, 0,0,0,0}
    };

    open_output_files(tests, n_tests);
    for (i = 0; i < n_tests; i++) {
        process_file(input_path, &tests[i]);
    }
    close_output_files(tests, n_tests);
}
