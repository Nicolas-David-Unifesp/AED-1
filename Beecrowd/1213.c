/*
  * nome: 1213.c
  * descrição: The Ones
  * data: 27/01/2024
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int resto = 1 % n;
        int length = 1;
        
        while (resto != 0) {
            resto = (resto * 10 + 1) % n;
            length++;
        }
        
        printf("%d\n", length);
    }

    return 0;
}
