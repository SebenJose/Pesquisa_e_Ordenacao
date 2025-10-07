#include "function.h"

int main()
{
    srand(time(NULL));

    int *vetor = NULL;
    int tamanhoVetor;
    int tamanhoBloco = 10;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    vetor = criaVetor(tamanhoVetor, NULL);
    if (vetor == NULL)
    {
        return 1;
    }

    salvarVetor(vetor, tamanhoVetor, "Txt/vetor.txt");

    printf("\nVetor inicial: \n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\nVetor salvo em Txt/vetor.txt\n\n");

    divideVetor("Txt/vetor.txt", "Txt/bloco", tamanhoBloco);

    int numBlocos = (tamanhoVetor + tamanhoBloco - 1) / tamanhoBloco;

    ordenaVetor(numBlocos, "Txt/bloco", "Txt/vetorOrdenado.txt");

    printf("\nVetor ordenado salvo em Txt/vetorOrdenado.txt\n");

    printf("\nVetor ordenado: \n");
    FILE *arquivoOrdenado = fopen("Txt/vetorOrdenado.txt", "r");
    if (arquivoOrdenado == NULL)
        return 1;

    int valor;
    while (fscanf(arquivoOrdenado, "%d", &valor) == 1)
    {
        printf("%d ", valor);
    }
    printf("\n");

    fclose(arquivoOrdenado);
    free(vetor);
    return 0;
}