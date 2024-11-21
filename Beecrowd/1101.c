/*
  * nome: 1101.c
  * descrição: Sequência de Números
  * data: 21/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */


#include <stdio.h>

int main() {
    int M, N;

    while (1) { // Loop infinito, será encerrado quando M E N menor/igual a zero
        scanf("%d %d", &M, &N);

        // Condição de parada
        if (M <= 0 || N <= 0) {
            break;
        }

        // Vendo quem é o menor e o maior
        int menor = (M < N) ? M : N;
        int maior = (M > N) ? M : N;

        // Cálculo e impressão da sequência de números e a soma entre eles
        int soma = 0;
        for (int i = menor; i <= maior; i++) {
            printf("%d ", i);
            soma += i;
        }
        printf("Sum=%d\n", soma);
    }

    return 0;
}
