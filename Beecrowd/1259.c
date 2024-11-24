/*
  * nome: 1259.c
  * descrição: Pares e Impares
  * data: 24/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>

int comparacaoCrescente(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // Ordena em Ordem Crescente
}

int comparacaoDecrescente(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Ordena em Ordem Decrecente
}

int main() {
    int N; // Número de Elementos
    scanf("%d", &N);

    int pares[N], impares[N];
    int contPares = 0, contImpares = 0;

    // Classifica os números em pares e ímpares
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            pares[contPares++] = num;  // Conta os pares
        } else {
            impares[contImpares++] = num;  // Conta os ímpares
        }
    }

    // Ordena os pares crescentemente
    qsort(pares, contPares, sizeof(int), comparacaoCrescente);

    // E os ímpares em ordem decrescente
    qsort(impares, contImpares, sizeof(int), comparacaoDecrescente);

    // Imprime os pares
    for (int i = 0; i < contPares; i++) {
        printf("%d\n", pares[i]);
    }

    // Imprime os ímpares
    for (int i = 0; i < contImpares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
