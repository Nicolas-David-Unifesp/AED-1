/*
  * nome: 1323.c
  * descrição: Feynman
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        int total = 0;
        // Somar quadrados
        for (int k = 1; k <= N; k++) {
            total += (N - k + 1) * (N - k + 1);
        }
        printf("%d\n", total);
    }
    return 0;
}
