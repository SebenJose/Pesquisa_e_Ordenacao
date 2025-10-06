#include "function.h"

//funcões para criar vetor com numeros aleatorios
#define TAM 50

int* criaVetor(int *tamSaida) {
    int *vetor = (int *)malloc(TAM * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100; // Números aleatórios entre 0 e 99
    }

    *tamSaida = TAM;
    return vetor;
}