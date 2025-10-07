#include "function.h"

int main()
{

    srand(time(NULL));

    int *vetor = NULL;
    int tamanho;

    vetor = criaVetor(&tamanho);
    if (vetor == NULL)
    {
        return 1;
    }

    // Salvando vetor em um arquivo .txt
    salvarVetor(vetor, tamanho, "Txt/vetor.txt");

    // Imprimindo vetor
    printf("\nVetor inicial: \n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\nVetor salvo em Txt/vetor.txt\n");

    divideVetor("Txt/vetor.txt", "Txt/bloco", 10);

    free(vetor);
    return 0;
}