/*
  * nome: 1371.c
  * descrição: Fechem as Portas!
  * data: 24/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <math.h>

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        int limite = (int)sqrt(N); // Maior número que, quando elevado a 2, não ultrapassa N
        
        // Impressão dos quadrados perfeitos
        for (int i = 1; i <= limite; i++) {
            printf("%d", i * i);
            if (i < limite) {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
