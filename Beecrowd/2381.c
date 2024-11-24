/*
  * nome: 2381.c
  * descrição: Lista de Chamada- Utilizando Lista Encadeada e mergeSort
  * data: 24/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista Encadada
typedef struct Aluno {
    char nome[21];       
    struct Aluno* proximo;
} Aluno;

// Função para inserir um aluno na lista encadeada
void inserirAluno(Aluno** cabeca, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = *cabeca;    // Faz o novo aluno apontar para a cabeça
    *cabeca = novoAluno;  // Atualiza a cabeça da lista para o novo nó
}

// Função que divide a lista encadeada em duas
Aluno* dividirLista(Aluno* cabeca) {
    Aluno* lento = cabeca;
    Aluno* rapido = cabeca;
    Aluno* anterior = NULL;

    // Apontando lento para o meio e rápido para o final da lista
    while (rapido != NULL && rapido->proximo != NULL) {
        anterior = lento;
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
    }

    // Dividindo a lista
    if (anterior != NULL) {
        anterior->proximo = NULL;
    }

    return lento;
}

// Função para mesclar as duas listas ordenadas
Aluno* mesclarListas(Aluno* lista1, Aluno* lista2) {
    Aluno* resultado = NULL;

    // Se uma estiver vazia, tenta retornar a outra
    if (lista1 == NULL) return lista2;
    if (lista2 == NULL) return lista1;

    // As listas se mesclam conforme se comparam os nomes
    if (strcmp(lista1->nome, lista2->nome) < 0) {
        resultado = lista1;
        resultado->proximo = mesclarListas(lista1->proximo, lista2);
    } else {
        resultado = lista2;
        resultado->proximo = mesclarListas(lista1, lista2->proximo);
    }

    return resultado;
}

// Ordenando usando Merge Sort
Aluno* mergeSort(Aluno* cabeca) {
    if (cabeca == NULL || cabeca->proximo == NULL) {
        return cabeca; // Caso já esteja ordenada
    }
  
    // Divide a lista em duas partes
    Aluno* segundaMetade = dividirLista(cabeca);

    // Ordena as duas partes
    cabeca = mergeSort(cabeca);
    segundaMetade = mergeSort(segundaMetade);

    // Mescla as duas listas
    return mesclarListas(cabeca, segundaMetade);
}

// Função para encontrar o aluno sorteado
void encontrarKAluno(Aluno* cabeca, int k) {
    Aluno* atual = cabeca;
    int i;
    for (i = 1; i < k && atual != NULL; i++) {
        atual = atual->proximo;
    }
    if (atual) {
        printf("%s\n", atual->nome);  // Imprime o nome do aluno sorteado
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    Aluno* listaAlunos = NULL;  // Inicializa a lista vazia

    // Leitura dos nomes dos alunos e inserção na lista
    for (int i = 0; i < N; i++) {
        char nome[21];
        scanf("%s", nome);
        inserirAluno(&listaAlunos, nome);
    }
    
    // Ordena a lista usando Merge Sort
    listaAlunos = mergeSort(listaAlunos);

    // Encontra e imprime o aluno sorteado
    encontrarKAluno(listaAlunos, K);

    return 0;
}
