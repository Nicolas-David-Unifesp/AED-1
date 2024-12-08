#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 100000; // Tamanho

// Função Mescla Dois Arrajos
void mescla(int v[], int baixo, int meio, int alto) {
    int n1 = meio - baixo + 1;
    int n2 = alto - meio;

    // Vetores temporários
    int v1[n1], v2[n2];

    // Copia os dados para os vetores temporários
    for (int i = 0; i < n1; i++) {
        v1[i] = v[baixo + i];
    }
    for (int j = 0; j < n2; j++) {
        v2[j] = v[meio + 1 + j];
    }

    // Mescla os dois sub-arranjos
    int i = 0, j = 0, k = baixo;
    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            v[k] = v1[i];
            i++;
        } else {
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver
    while (i < n1) {
        v[k] = v1[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = v2[j];
        j++;
        k++;
    }
}

// Função MergeSort
void mergesort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;

        // Ordena a primeira e a segunda metade
        mergesort(v, baixo, meio);
        mergesort(v, meio + 1, alto);

        // Mescla as duas metades
        mescla(v, baixo, meio, alto);
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

    // Verificando tempo de execução do MergeSort
    t = clock(); // armazena tempo inicial
    mergesort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000)); // conversão para double

    return 0;
}
