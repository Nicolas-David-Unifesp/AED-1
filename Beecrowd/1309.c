/*
  * nome: 1309.c
  * descrição: Formatação Monetária
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>

void formatar_moeda(int dolares, int centavos) {
    // Armazenar a parte dos centavos com 2 dígitos
    char centavos_str[3];
    snprintf(centavos_str, sizeof(centavos_str), "%02d", centavos);

    // Formatando a parte dos dólares
    char dolares_str[50];
    int len = snprintf(dolares_str, sizeof(dolares_str), "%d", dolares);

    // Adicionando as vírgulas
    for (int i = len - 3; i > 0; i -= 3) {
        for (int j = len; j >= i; j--) {
            dolares_str[j + 1] = dolares_str[j];
        }
        dolares_str[i] = ',';
        len++;
    }

    
    printf("$%s.%s\n", dolares_str, centavos_str);
}

int main() {
    int dolares, centavos;

    while (scanf("%d %d", &dolares, &centavos) != EOF) {
        formatar_moeda(dolares, centavos);
    }

    return 0;
}
