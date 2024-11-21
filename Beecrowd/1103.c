/*
  * nome: 1103.c
  * descrição: Alarme Despertador
  * data: 21/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>

int main() {
    int H1, M1, H2, M2;

    while (1) {
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

        // Condição de parada: quatro zeros
        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) {
            break;
        }

        // Converte o inicio e fim para minutos totais
        int inicio = H1 * 60 + M1;
        int fim = H2 * 60 + M2;

        // Calculo da diferença de tempo
        int minutos_dormir;
        if (fim >= inicio) {
            // Caso o alarme seja para o mesmo dia
            minutos_dormir = fim - inicio;
        } else {
            // Caso o alarme aconteça em dias diferentes
            minutos_dormir = (24 * 60 - inicio) + fim;
        }

        // Mostra a diferença
        printf("%d\n", minutos_dormir);
    }

    return 0;
}
