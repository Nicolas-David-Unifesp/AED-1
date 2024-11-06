



#include <stdio.h>

int main() {
    double raio, area;
    const double PI = 3.14159;

    // Entrada do valor do raio
    scanf("%lf", &raio);

    // Cálculo da área
    area = PI * raio * raio;

    // Saída formatada com 4 casas decimais e nova linha no final
    printf("A=%.4lf\n", area);

    return 0;
}