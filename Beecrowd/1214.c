/*
  * nome: 1214.c 
  * descrição: Acima da Média
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);   
    while (C--) {
        int N;  
        scanf("%d", &N);
        int notas[N];  
        int soma = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &notas[i]);
            soma += notas[i]; 
        }
        // Calculo media turma
        double media = soma / (double)N;
        // Conta Acima da Média
        int acima_media = 0;
        for (int i = 0; i < N; i++) {
            if (notas[i] > media) {
                acima_media++;
            }
        }
        // Calculando o percentual de estudantes acima da média
        double percentual = (acima_media * 100.0) / N;
        printf("%.3lf%\n", percentual);
    }
    
    return 0;
}
