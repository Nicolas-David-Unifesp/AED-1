/*
  * nome: 2728.c
  * descrição: 
  * data: 21/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>

// Função que calcula duração de nota
double calcular_duracao(char nota) {
    switch (nota) {
        case 'W': return 1.0;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
        default: return 0.0; // Caso de nota inexistente
    }
}

int main() {
    char composicao[201];

    while (1) {
        // Lê uma composição
        scanf("%s", composicao);

        // Verifica se é o fim
        if (composicao[0] == '*') {
            break;
        }

        int compassos_corretos = 0;
        double duracao_atual = 0.0;

        // Percorre a composição
        for (int i = 0; i < strlen(composicao); i++) {
            if (composicao[i] == '/') {
                // Quando encontra uma barra, vê se o compasso está correto
                if (duracao_atual == 1.0) {
                    compassos_corretos++;
                }
                // Reinicia a duração do compasso, já que verifica na barra final do compasso
                duracao_atual = 0.0;
            } else {
                // Soma a duração da nota no meio do compasso atual
                duracao_atual += calcular_duracao(composicao[i]);
            }
        }

        // Impressão do número de compassos que estão corretos
        printf("%d\n", compassos_corretos);
    }

    return 0;
}
