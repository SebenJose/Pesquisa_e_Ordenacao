# 🔍 Pesquisa e Ordenação

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![UTFPR](https://img.shields.io/badge/Universidade-UTFPR-orange?style=flat-square)

Repositório dedicado aos **trabalhos da disciplina de Pesquisa e Ordenação**, com implementações práticas de algoritmos de busca e ordenação.

Cada trabalho está organizado em uma pasta própria dentro do repositório.

---

## 📘 Trabalho 01 — Ordenação Externa (K-Way Merge Sort)

### 🧾 Descrição

Este projeto implementa o **Merge Sort Externo**, técnica usada para ordenar grandes volumes de dados que **não cabem inteiramente na memória**.

O algoritmo é dividido em duas fases principais:

#### 🩵 Fase 1 — Criação dos blocos
1.  Geração de um vetor aleatório (tamanho definido pelo usuário).  
2.  Gravação do vetor em arquivo (`vetor.txt`).  
3.  Divisão do arquivo em blocos menores de tamanho fixo (ex: 10 números).  
4.  Ordenação de cada bloco na memória com `qsort()`.  
5.  Salvamento de cada bloco **já ordenado** em arquivos (`bloco1.txt`, `bloco2.txt`, ...).

#### ❤️ Fase 2 — Intercalação (Merge)
1.  Leitura simultânea dos blocos ordenados.  
2.  Seleção do menor elemento entre os blocos ativos.  
3.  Escrita sequencial dos valores no arquivo final `vetorOrdenado.txt`.  
4.  Resultado: todos os dados ordenados em um único arquivo final.

---

### 🧾 Exemplo de execução

Digite o tamanho do vetor: 50

Vetor inicial:
82 3 55 14 97 ...

Bloco 'Txt/bloco1.txt' criado com 10 números ordenados.
Bloco 'Txt/bloco2.txt' criado com 10 números ordenados.
...

Vetor ordenado salvo em Txt/vetorOrdenado.txt

Vetor ordenado:
0 2 3 5 7 8 9 11 14 ...

---

### 🧠 Funções principais

| Função | Descrição |
|:--------|:-----------|
| `criaVetor()` | Gera um vetor de inteiros aleatórios. |
| `salvarVetor()` | Salva o vetor em um arquivo `.txt`. |
| `divideVetor()` | Lê o vetor do arquivo, separa em blocos menores e ordena cada bloco. |
| `ordenaVetor()` | Realiza a intercalação (merge) dos blocos ordenados. |
| `compara()` | Função auxiliar usada pelo `qsort()`. |

---

## 🚀 Trabalhos

| Nº | Nome do Projeto | Status | Descrição |
|:---|:----------------|:--------|:-----------|
| 01 | Ordenação Externa (K-Way Merge Sort) | ✅ Concluído | Implementação completa do algoritmo de Merge Sort Externo. |

---

## 👨‍💻 Autores

**Seben José**

**Caio Macedo**

🎓 *Estudantes de Ciência da Computação - UTFPR (Câmpus Santa Helena)* 📅 *Ano: 2025*

---
