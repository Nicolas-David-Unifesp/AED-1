#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t


void Intercala (int p, int q, int r, int v[]) {
  int i, j, k, *w;
  w = malloc ((r-p) * sizeof (int));
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

void Mergesort (int p, int r, int v[]) {
  if (p < r - 1) {
    int q = (p + r)/2;
    Mergesort (p, q, v);
    Mergesort (q, r, v);
    Intercala (p, q, r, v);
  }
}



int const TAM = 100000; //constante para tamanho do vetor



int main(){
    clock_t t, t1; //variável para armazenar tempo
    int vetor[TAM], a, j;
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));
    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++){
        vetor[a] = rand() % TAM;
    }
    //Verificando tempo de execução do mergesort
    t = clock(); //armazena tempo
    Mergesort( 0, TAM, vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}

