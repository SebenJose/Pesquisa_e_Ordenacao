#include "function.h"

int main(){
    
    int* vetor = NULL;
    int tamanho;

    vetor = criaVetor(&tamanho);
    if (vetor == NULL) {
        return 1;
    }

    // Imprimindo vetor
    printf("\nVetor inicial: \n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}