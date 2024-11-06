/*
  * nome: 1002.c
  * descrição: Área do Círculo
  * data: 12/10/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>

int main() {
    double raio, area;
    const double PI = 3.14159;

    // Valor do raio
    scanf("%lf", &raio);

    // Cálculo da área
    area = PI * raio * raio;

    // Imprime a Área
    printf("A=%.4lf\n", area);

    return 0;
}
