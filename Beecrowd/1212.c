/*
  * nome: 1212.c
  * descrição: Aritmética Primária
  * data: 27/01/2024
  *Resolvido por Nicolas David da Cruz Santos
  */
#include <stdio.h>

int main() {
    unsigned int a, b;
    
    while (scanf("%u %u", &a, &b) && (a != 0 || b != 0)) {
        int carry = 0, carry_count = 0;
        
        while (a > 0 || b > 0) {
            int sum = (a % 10) + (b % 10) + carry;
            if (sum >= 10) {
                carry = 1;
                carry_count++;
            } else {
                carry = 0;
            }
            
            a /= 10;
            b /= 10;
        }
        
        if (carry_count == 0) {
            printf("No carry operation.\n");
        } else if (carry_count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", carry_count);
        }
    }
    
    return 0;
}

