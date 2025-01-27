/*
  * nome: 1308.c
  * descrição: Guerreiros Etruscos Nunca Jogam Xadrez
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

long long sum_of_first_k(long long k) {
    return k * (k + 1) / 2;
}

int main() {
    int t;
    scanf("%d", &t);  
    
    while (t--) {
        long long N;
        scanf("%lld", &N); 
        
        // Limitando a busca binária
        long long left = 0, right = 2e9;
        long long result = 0;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sum = sum_of_first_k(mid);
            
            if (sum <= N) {
                result = mid;  // k válido encontrado, mas pode existir um maior
                left = mid + 1; //Tentando encontrar o maior
            } else {
                right = mid - 1; // Aqui o k menor
            }
        }
        
        printf("%lld\n", result);
    }

    return 0;
}
