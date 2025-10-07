#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

// funcões para criar vetor com numeros aleatorios
int *criaVetor(int *tamSaida);

// função para armazenar o vetor criado em um arquivo .txt
void salvarVetor(const int *vetor, int tamanho, const char *nomeArquivo);

// função para dividir o vetor em porções menores
void divideVetor(const char *arquivoEntrada, const char *prefixoSaida, int tamanhoBloco);

// funcao usada no qsort
int compara(const void *a, const void *b);

// função para ordenar os blocos e juntar em um arquivo final
void ordenaVetor(int numBlocos, const char *prefixoEntrada, const char *arquivoSaida);
#endif