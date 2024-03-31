#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQ 30
#define MAX_STRING 15

char SHELL[MAX_STRING] = "SHELL";
char KNUT[MAX_STRING] = "KNUT";
char CIURA[MAX_STRING] = "CIURA";
int shell_seq[MAX_SEQ] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int knuth_seq[MAX_SEQ] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484};
int ciura_seq[MAX_SEQ] = {1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711};

void print_array(int C[], int tam, char text[]) {
    for (int i = 0; i < tam; i++) printf("%d ", C[i]);
    printf("%s\n", text);
}

void shell_sort(int C[], int seq[], char name[], int tam) {
    int moves = 0;
    char msg[MAX_STRING];
    int i, j, key, seq_index = 0;

    sprintf(msg, "SEQ=%s", name);
    print_array(C, tam, msg);
    
    // find bigger value smaller than the vector size
    while (seq[seq_index] < tam) seq_index++;
    seq_index--;

    while (seq_index >= 0) {
        // execute insertion_sort
        for (j = 1; j * seq[seq_index] < tam; j++) {
            key = C[j * seq[seq_index]];
            i = (j - 1) * seq[seq_index];
        
            while ((i >= 0) && (C[i] > key)) {
                C[i + seq[seq_index]] = C[i];
                i -= seq[seq_index];
                moves++;
            }
        
            C[i + seq[seq_index]] = key;
        }

        sprintf(msg, "INC=%d", seq[seq_index]);
        print_array(C, tam, msg);
        seq_index--;
    }

    printf("Shell Sort used %d moves\n\n", moves);
}

int main() {
    int arr1[10] = {12,2,5,4,8,7,6,9,1,15};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr3[10] = {10,9,8,7,6,5,4,3,2,1};

    shell_sort(arr1, shell_seq, SHELL, 10);
    // shell_sort(arr1, knuth_seq, KNUT, 10);
    // shell_sort(arr1, ciura_seq, CIURA, 10);
    shell_sort(arr2, shell_seq, SHELL, 10);
    shell_sort(arr3, shell_seq, SHELL, 10);
}