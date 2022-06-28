#include "busca.h"
#include <time.h>

int busca_sequencial(int* vetor, int S, double* T, int* C, int N) {
    clock_t inicio, fim;
    int idx = -1;
    inicio = clock();
    for (int i = 0; i < S; i++) {
        *C += 1;
        if (N == vetor[i]) {
            idx = i;
            break;
        }
    }
    fim = clock();
    *T = 1000 * (double) (fim - inicio) / CLOCKS_PER_SEC;
    return idx;
}

int busca_binaria(int* vetor, int S, double* T, int* C, int N) {
    time_t inicio, fim;
    int idx = -1, idx_ini = 0, idx_fim = S - 1, meio;
    inicio = clock();
    while (idx_ini <= idx_fim) {
        meio = (idx_ini + idx_fim) / 2;
        *C += 1;
        if (N < vetor[meio])
            idx_fim = meio - 1;
        else if (N > vetor[meio])
            idx_ini = meio + 1;
        else {
            idx = meio;
            break;
        }
    }
    fim = clock();
    *T = 1000 * (double) (fim - inicio) / CLOCKS_PER_SEC;
    return idx;
}
