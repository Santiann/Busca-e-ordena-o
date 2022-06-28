#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 100000 // variar 100, 1000, 10000, 100000
#define NUM_RODADAS 30

int main() {
    setbuf(stdout, NULL);
    int *vetor = malloc(SIZE * sizeof(int));
    int *vetor_teste = malloc(SIZE * sizeof(int));
    clock_t inicio, fim;
    double C1 = 0, C2 = 0, C3, T1 = 0, T2 = 0, T3 = 0;
    int C, T;
    for (int i = 0; i < NUM_RODADAS; i++) {
        printf("Rodada %d de %d (%.2f)...", i + 1, NUM_RODADAS, 100 * (double) (i + 1) / (double) NUM_RODADAS);
        for (int i = 0; i < SIZE; i++)
            vetor[i] = rand() % SIZE + 1;
        
        // bubble sort
        for (int i = 0; i < SIZE; i++)
            vetor_teste[i] = vetor[i];

        inicio = clock();
        C = 0;
        T = 0;
        bubble_sort(vetor, SIZE, &C);
        fim = clock();

        T = 1000 * (double) (fim - inicio) / CLOCKS_PER_SEC;
        T1 += T;
        C1 += (double) C / NUM_RODADAS;

        // selection sort
        for (int i = 0; i < SIZE; i++)
            vetor_teste[i] = vetor[i];

        inicio = clock();
        C = 0;
        T = 0;
        selection_sort(vetor, SIZE, &C);
        fim = clock();
        
        T = 1000 * (double) (fim - inicio) / CLOCKS_PER_SEC;
        T2 += T;
        C2 += (double) C / NUM_RODADAS;

        // quick sort
        for (int i = 0; i < SIZE; i++)
            vetor_teste[i] = vetor[i];

        inicio = clock();
        C = 0;
        T = 0;
        quick_sort(vetor, 0, SIZE - 1, &C);
        fim = clock();
        
        T = 1000 * (double) (fim - inicio) / CLOCKS_PER_SEC;
        T3 += T;
        C3 += (double) C / NUM_RODADAS;
        printf("OK\n"); 
    }
    T1 /= NUM_RODADAS;
    T2 /= NUM_RODADAS;
    T3 /= NUM_RODADAS;
    printf("\n========== Resultados ==========\n");
    printf("C1 = %.2f; C2 = %.2f; C3 = %.2f\n", C1, C2, C3);
    printf("T1 (ns) = %.2f; T2 (ns) = %.2f; T3 (ns) = %.2f", T1, T2, T3);
    free(vetor);
    free(vetor_teste);
}