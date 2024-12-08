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
        v[i + 1] = x;
    }
}

int main() {
    clock_t t;
    int vetor[TAM];

    // Coloca Valores Aleatorios
    srand((unsigned)time(NULL));

    // Geração Aletória
    for (int a = 0; a < TAM; a++) {
        vetor[a] = rand() % TAM;
    }

    t = clock(); // Tempo Incial
    Inserção(TAM, vetor);
    t = clock() - t; // Delta Tempo

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t) / (CLOCKS_PER_SEC));

    return 0;
}
