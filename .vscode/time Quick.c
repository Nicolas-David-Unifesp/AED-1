#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 100000; // constante para tamanho do vetor

// Função para particionar o vetor
int particiona(int v[], int baixo, int alto) {
    int pivo = v[alto];
    int i = baixo - 1; // índice do menor elemento

    for (int j = baixo; j < alto; j++) {
        if (v[j] <= pivo) {
            i++;
            // Troca os elementos v[i] e v[j]
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    // Troca o pivô para a posição correta
    int temp = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = temp;

    return i + 1; // Retorna o índice do pivô
}

// Função QuickSort
void quicksort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        // Particiona o vetor e obtém o índice do pivô
        int pi = particiona(v, baixo, alto);

        // Ordena os sub-arranjos de forma recursiva
        quicksort(v, baixo, pi - 1);
        quicksort(v, pi + 1, alto);
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

    // Verificando tempo de execução do QuickSort
    t = clock(); // armazena tempo inicial
    quicksort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000)); // conversão para double

    return 0;
}