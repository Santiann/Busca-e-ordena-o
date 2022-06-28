#include "busca.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10000000 // variar 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
#define NUM_RODADAS 30

int main() {
    int *vetor = malloc(SIZE * sizeof(int));
    double C1 = 0, C2 = 0, T1 = 0, T2 = 0;
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = i + 1;
    }
    for (int i = 0; i < NUM_RODADAS; i++) {
        printf("Rodada %d de %d (%.2f)...", i + 1, NUM_RODADAS, 100 * (double) (i + 1) / (double) NUM_RODADAS); 
        int N = rand() % SIZE + 1;
        int C;
        double T;
        
        C = 0; // numero de comparacoes
        T = 0; // tempo decorrido (ns)
        busca_sequencial(vetor, SIZE, &T, &C, N);
        T1 += T;
        C1 += (double) C / NUM_RODADAS;

        C = 0; // numero de comparacoes
        T = 0; // tempo decorrido
        busca_binaria(vetor, SIZE, &T, &C, N);
        T2 += T;
        C2 += (double) C / NUM_RODADAS;       

        printf("OK\n"); 
    }
    T1 /= NUM_RODADAS;
    T2 /= NUM_RODADAS;
    printf("\n========== Resultados ==========\n");
    printf("C1 = %.2f; C2 = %.2f\n", C1, C2);
    printf("T1 (ns) = %.2f; T2 (ns) = %.2f", T1, T2);
    free(vetor);
}