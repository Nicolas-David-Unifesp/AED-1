#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int const TAM = 100000; // Tamanho

// Função para particiona Vetores
int particiona(int v[], int baixo, int alto) {
    int pivo = v[alto];
    int i = baixo - 1; 

    for (int j = baixo; j < alto; j++) {
        if (v[j] <= pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = temp;

    return i + 1; 
}

void quicksort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(v, baixo, alto);
        quicksort(v, baixo, pi - 1);
        quicksort(v, pi + 1, alto);
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];

    // Aleatório
    srand((unsigned)time(NULL));

    // Gera Elementos Aleatórios
    for (int a = 0; a < TAM; a++) {
        vetor[a] = rand() % TAM;
    }

    t = clock();
    quicksort(vetor, 0, TAM - 1);
    t = clock() - t; //Delta Tempo

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t) / (CLOCKS_PER_SEC/1000)); // conversão para double

    return 0;
}
