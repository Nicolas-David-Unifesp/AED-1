/*
  * nome: 1129.c
  * descrição: Leitura Ótica
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
        for (int i = 0; i < N; i++) {
            int A, B, C, D, E;
            int count = 0;
            int answer = -1;

            // Lê os valores pras 5 alternativas
            scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

            // Verifica quais são "preto" (<= 127)
            int answers[5] = {A, B, C, D, E};

            // Conta as que estão marcadas (preto)
            for (int j = 0; j < 5; j++) {
                if (answers[j] <= 127) {
                    count++;
                    answer = j;  // Guarda a posição da alternativa
                }
            }

            // Se exatamente uma alternativa for marcada, é correto
            if (count == 1) {
                char result = 'A' + answer;  // 'A' + 0 -> 'A', 'A' + 1 -> 'B', etc.
                printf("%c\n", result);
            } else {
                // Senão, exibe *
                printf("*\n");
            }
        }
    }

    return 0;
}
