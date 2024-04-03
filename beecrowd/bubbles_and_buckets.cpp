#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int moves = 0;
int ciura_seq[17] = {1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711};
int seq_i = 0;

void insertion_sort(int arr[], int tam, int h) {
    int i, j, key;

    for (j = 1; j < tam; j++) {
        key = arr[j];
        i = j - h;

        while (i >= 0 && arr[i] > key) {
            arr[i + h] = arr[i];
            i -= h;
            moves++;
        }

        arr[i + h] = key;
    }
}

void shell_sort(int arr[], int tam) {
    int h, j;

    while (ciura_seq[seq_i + 1] < tam) seq_i++;
    while (seq_i >= 0) {
        h = ciura_seq[seq_i];
        insertion_sort(arr, tam, h);            
        seq_i--;
    }
}

int main() {
    int buffer;
    int arr[100000];
    int tam, i;

    do {
        i = 0;
        tam = 0;
        moves = 0;

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
            shell_sort(arr, tam);
            cout << (moves % 2 ? "Marcelo\n" : "Carlos\n");
        }

        fflush(stdin);
    } while (buffer);
}