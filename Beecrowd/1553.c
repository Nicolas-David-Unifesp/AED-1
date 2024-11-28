/*
  * nome: 1553.c
  * descrição: Perguntas mais Frequentes
  * data: 12/10/2024
  *Resolvido por Nicolas David da Cruz Santos
  */


#include <stdio.h>

void BubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;  // Se não houve troca, já está ordenado
        }
    }
}

int main() {
    int N, K;
    while (scanf("%d %d", &N, &K) && (N != 0 || K != 0)) {
        int perguntas[N];
        int total = 0, count = 1;
        
        // Leitura dos valores
        for (int i = 0; i < N; i++) {
            scanf("%d", &perguntas[i]);
        }

        // Ordenação
        BubbleSort(perguntas, N);

        // Contagem das perguntas
        for (int i = 1; i < N; i++) {
            if (perguntas[i] == perguntas[i - 1]) {
                count++;  // Continuamos a sequência
            } else {
                if (count >= K) {
                    total++;  // Incrementa total de sequências
                }
                count = 1;  // Reinicia a contagem para abrir espaço para uma nova sequência
            }
        }

        // Verifica a última sequência
        if (count >= K) {
            total++;
        }

        printf("%d\n", total);
    }
    return 0;
}
