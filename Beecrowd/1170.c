#include <stdio.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        double C; // Quantidade inicial de comida
        scanf("%lf", &C);

        int dias = 0;
        while (C > 1.0) {
            C /= 2.0; // Blobs come metade do suprimento
            dias++;
        }

        printf("%d dias\n", dias);
    }

    return 0;
}
