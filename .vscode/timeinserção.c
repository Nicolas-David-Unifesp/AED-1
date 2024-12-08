#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 100000; // constante para tamanho do vetor

void Inserção(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--) {
            v[i + 1] = v[i];
        }
        v[i + 1] = x; // Aqui a atribuição final é feita após o laço
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // semente de aleatoriedade
    srand((unsigned)time(NULL));

    // geração aleatória dos valores do vetor
    for (int a = 0; a < TAM; a++) {
        vetor[a] = rand() % TAM;
    }

    // Verificando tempo de execução do Inserção
    t = clock(); // armazena tempo inicial
    Inserção(TAM, vetor);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000)); // conversão para double

    return 0;
}