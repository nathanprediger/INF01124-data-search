#include <stdio.h>
#include <stdlib.h>

// --------------------------------------------------------
// melhor caso (n): array já se encontra ordenado
// pior caso (n²): array na ordem reversa = n(n-1) / 2
// complexidade media: n² 
// --------------------------------------------------------
// Insertion Sorting é lento para um conjunto grande de valores
// desordenados porquê as trocas somente envolvem elementos
// adjacentes no vetor. Como resultado, elementos se movem pelo
// vetor somente uma posição por vez. 

void print_array(int C[], int tam) {
    if (tam > 10) printf("Printing only 10 initial elements\n");
    tam = tam > 10 ? 10 : tam;
    
    printf("[");
    for (int i = 0; i < tam - 1; i++) {
        printf("%d, ", C[i]);
    }
    printf("%d]", C[tam - 1]);
}

void insertion_sort(int C[], int tam, int print_ok) {
    int moves = 0;
    int i, j, key;

    if (print_ok) {
        printf ("\nArray before: ");
        print_array(C, tam);
    }

    for (j = 1; j < tam; j++) {
        key = C[j];
        i = j - 1;
    
        while ((i >= 0) && (C[i] > key)) {
            C[i + 1] = C[i];
            i--;
            moves++;
        }
    
        C[i + 1] = key;
    }

    if (print_ok) {
        printf ("\nArray after: ");
        print_array(C, 10);
    }

    printf("\nInsertion Sort used %d moves\n", moves);
}

int main() {
    int arr1[10] = {12,2,5,4,8,7,6,9,1,15};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
    int arr4[1000];
    int arr5[1000];

    insertion_sort(arr1, 10, 1);
    insertion_sort(arr2, 10, 1);
    insertion_sort(arr3, 10, 1);
    
    for (int i=0; i<1000; i++) arr4[i] = 1000-i;
    insertion_sort(arr4, 1000, 1);
    
    for (int i=0; i<1000; i++) arr5[i] = rand() % 1000+1;
    insertion_sort(arr5, 1000, 1);
    
    for (int i=0; i<1000; i++) arr5[i] = rand() % 1000+1;
    insertion_sort(arr5, 1000, 1);

    return 0;
}