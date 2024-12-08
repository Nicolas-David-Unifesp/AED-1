#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 100000; // Tamanho

// Função Mescla Dois Arrajos
void Intercala (int v[], int p, int q, int r) {
  int i, j, k, *w;
  w = malloc ((r-p+1) * sizeof (int));
  i = p; j = q; k = 0;
  while (i < q && j < r) {
    if (v[i] <= v[j]) w[k++] = v[i++];
    else w[k++] = v[j++];
  }
  while (i < q) w[k++] = v[i++];
  while (j < r) w[k++] = v[j++];
  for (i = p; i < r; i++) v[i] = w[i-p];
  free (w);
}

// Função MergeSort
void mergesort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;
        mergesort(v, baixo, meio);               
        mergesort(v, meio + 1, alto);             
        Intercala(v, baixo, meio + 1, alto + 1);  
    }
}

int main() {
    clock_t t;
    int vetor[TAM];

    // Valores Aleatórios
    srand((unsigned)time(NULL));

    // Vai Atribuindo
    for (int a = 0; a < TAM; a++) {
        vetor[a] = rand() % TAM;
    }

    // Tempo
    t = clock(); 
    mergesort(vetor, 0, TAM - 1);
    t = clock() - t; // Delta Tempo

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000)); // conversão para double

    return 0;
}
