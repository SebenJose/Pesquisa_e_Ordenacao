#include "function.h"

// funcões para criar vetor com numeros aleatorios
#define TAM 50

int *criaVetor(int *tamSaida)
{
    int *vetor = (int *)malloc(TAM * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = 0; i < TAM; i++)
    {
        vetor[i] = rand() % 100; // Números aleatórios entre 0 e 99
    }

    *tamSaida = TAM;
    return vetor;
}

// função para armazenar o vetor criado em um arquivo .txt
void salvarVetor(const int *vetor, int tamanho, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL)
        return;

    for (int i = 0; i < tamanho; i++)
    {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

// função para dividir o vetor em porções menores
void divideVetor(const char *arquivoEntrada, const char *prefixoSaida, int tamanhoBloco)
{

    FILE *entrada = fopen(arquivoEntrada, "r");
    if (entrada == NULL)
        return;

    int contadorArquivos = 1;
    int numero, numerosLidos;

    while (!feof(entrada))
    {
        int bloco[tamanhoBloco];
        numerosLidos = 0;

        for (int i = 0; i < tamanhoBloco; i++)
        {
            if (fscanf(entrada, "%d", &numero) == 1)
            {
                bloco[i] = numero;
                numerosLidos++;
            }
            else
            {
                break;
            }
        }

        if (numerosLidos > 0)
        {
            qsort(bloco, numerosLidos, sizeof(int), compara);

            char nomeArquivoSaida[100];
            sprintf(nomeArquivoSaida, "%s%d.txt", prefixoSaida, contadorArquivos);

            FILE *saida = fopen(nomeArquivoSaida, "w");
            if (saida == NULL)
            {
                printf("Erro ao criar o arquivo de saida: %s\n", nomeArquivoSaida);
                fclose(entrada);
                return;
            }

            for (int i = 0; i < numerosLidos; i++)
            {
                fprintf(saida, "%d\n", bloco[i]);
            }

            fclose(saida);
            printf("Bloco '%s' criado com %d numeros ordenados.\n", nomeArquivoSaida, numerosLidos);
            contadorArquivos++;
        }
    }

    fclose(entrada);
}

// funcao usada no qsort
int compara(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// função para ordenar os blocos e juntar em um arquivo final
void ordenaVetor(int numBlocos, const char* prefixoEntrada, const char* arquivoSaida) {

    FILE* arquivosEntrada[numBlocos];
    char nomeArquivoEntrada[100];

    for (int i = 0; i < numBlocos; i++) {
        sprintf(nomeArquivoEntrada, "%s%d.txt", prefixoEntrada, i + 1);
        arquivosEntrada[i] = fopen(nomeArquivoEntrada, "r");
        
        if (arquivosEntrada[i] == NULL) return;
    }

    FILE* saida = fopen(arquivoSaida, "w");
    if (saida == NULL) return;

    int buffer[numBlocos];
    bool finalizados[numBlocos];
    for (int i = 0; i < numBlocos; i++) {
        finalizados[i] = false;
    }

    for (int i = 0; i < numBlocos; i++) {
        if (fscanf(arquivosEntrada[i], "%d", &buffer[i]) != 1) {
            finalizados[i] = true;
            buffer[i] = INT_MAX;
        }
    }

    while (true) {
        int menorValor = INT_MAX;
        int indiceMenor = -1;

        for (int i = 0; i < numBlocos; i++) {
            if (!finalizados[i] && buffer[i] < menorValor) {
                menorValor = buffer[i];
                indiceMenor = i;
            }
        }

        if (indiceMenor == -1) {
            break;
        }

        fprintf(saida, "%d\n", menorValor);

        if (fscanf(arquivosEntrada[indiceMenor], "%d", &buffer[indiceMenor]) != 1) {
            finalizados[indiceMenor] = true;
            buffer[indiceMenor] = INT_MAX;
        }
    }

    for (int i = 0; i < numBlocos; i++) {
        fclose(arquivosEntrada[i]);
    }
    fclose(saida);

    printf("Arquivo '%s' criado com todos os valores ordenados!\n", arquivoSaida);
}