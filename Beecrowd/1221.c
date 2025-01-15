#include <stdio.h>
#include <math.h>

//Estou considerando 1 para primo e 0 para não primo!
int is_prime(int x) {
    if (x <= 1) return 0;  // 1 não é primo!
    if (x == 2) return 1;  // 2 é primo!
    if (x % 2 == 0) return 0;  // Maiores e Divisiveis por 2 não são primos!!!

    // Checar divisores até raiz de X, pois facilita o processo de verificação de primos
    int limit = (int)sqrt(x);
    for (int i = 3; i <= limit; i += 2) {  //Teste dos Impares
        if (x % i == 0) return 0;  // Se divisivel por algum número, não é primo!
    }
    return 1;  // Senão, é primo!
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int X;
        scanf("%d", &X);
        
        if (is_prime(X)) {
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
    }

    return 0;
}
