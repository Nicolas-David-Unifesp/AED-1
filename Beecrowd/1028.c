/*
  * nome: 1028.c
  * descrição: Figurinhas
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

// Cálculo MDC
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    scanf("%d", &N); 
    
    for (int i = 0; i < N; i++) {
        int F1, F2;
        scanf("%d %d", &F1, &F2); 
        
        // Calcula o MDC entre F1 e F2
        int resultado = mdc(F1, F2);
        printf("%d\n", resultado);
    }
    
    return 0;
}

