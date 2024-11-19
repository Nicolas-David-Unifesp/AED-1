#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 100000; //constante para tamanho do vetor

void bubbleSort (int v[TAM]) {
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

int BuscaSeqüencial (int x, int n, int v[]) {
    int j = 0;
    while (j < n && v[j] < x) ++j;
    return j;
}

int BuscaBinária (int x, int n, int v[]) {
    int e, m, d;
    e = -1; d = n;
    while (/*X*/ e < d - 1) {
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
}
    return d;
}

int main(){
    clock_t t, t1; //variável para armazenar tempo
    int vetor[TAM], a, j, k;
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));
    

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++){
        vetor[a] = rand() % TAM;
    }
    scanf("%d", &a);
        

    bubbleSort(vetor);
    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    k = BuscaSeqüencial(a, TAM, vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    t1 = clock();
    j = BuscaBinária(a,TAM,vetor);
    t1= clock()-t1;

    printf("Tempo de execucao: %lf ms\n", ((double)t1)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
