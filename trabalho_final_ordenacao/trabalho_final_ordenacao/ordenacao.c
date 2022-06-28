#include "ordenacao.h"
#include <time.h>

void bubble_sort(int* vetor, int S, int* C) {
    time_t inicio, fim;
    int troca = 1;;
    while (troca) {
        troca = 0;
        for (int i = 0; i < S - 1; i++) {
            *C += 1;
            if (vetor[i] > vetor[i + 1]) {
                int aux = vetor[i];                                
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1;
            }
        }
    }
}

void selection_sort(int* vetor, int S, int* C)
{
    for (int i = 0; i < S - 1; i++)
    {
        int min = i; 
        for (int j = i + 1; j < S; j++)
        {
            *C += 1;
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        int aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }
}

void quick_sort(int* vetor, int idx_inicio, int idx_fim, int* C)
{
	int i, j, pivo, aux;
	i = idx_inicio;
	j = idx_fim - 1;
	pivo = vetor[(idx_inicio + idx_fim) / 2];
	while(i <= j)
	{
		while(vetor[i] < pivo && i < idx_inicio)
		{
            *C += 1;
			i++;
		}
		while(vetor[j] > pivo && j > idx_fim)
		{
            *C += 1;
			j--;
		}
		if(i <= j)
		{            
            *C += 1;
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > idx_inicio)
		quick_sort(vetor, idx_inicio, j + 1, C);
	if(i < idx_fim)
		quick_sort(vetor, i, idx_fim, C);
}