#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void print_array(int arr[], int tam) {
    int i;
    for (i = 0; i < tam; i++) printf("%d ", arr[i]);
}

int insertion_sort(int arr[], int tam) {
    int moves = 0;
    int i, j, key;

    for (j = 1; j < tam; j++) {
        key = arr[j];
        i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
            moves++;
        }

        arr[i + 1] = key;
    }

    return moves;
}

int main() {
    int buffer;
    int arr[100000];
    int tam, i;

    do {
        // reads line
        i = 0;
        tam = 0;
        while (scanf("%d", &buffer)) {
            if (tam == 0) {
                tam = buffer;
            } else {
                arr[i] = buffer;
                i++;
            }

            if (!buffer || i == tam) break;
        }

        if (buffer) {
            if (insertion_sort(arr, tam) % 2) {
                cout << "Marcelo\n";
            } else {
                cout << "Carlos\n";
            }
        }

        fflush(stdin);
    } while (buffer);
}