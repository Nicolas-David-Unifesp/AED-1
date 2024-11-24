


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];

    while (1) {
        // Lê uma linha de entrada
        fgets(input, sizeof(input), stdin);
        
        // Remove o caractere de nova linha, se presente
        input[strcspn(input, "\n")] = '\0';

        // Se a entrada for um número negativo, encerra o programa
        if (atoi(input) < 0) {
            break;
        }

        // Verifica se o número é hexadecimal
        if (input[0] == '0' && input[1] == 'x') {
            // Converte de hexadecimal para decimal
            int decimal = (int)strtol(input, NULL, 16);
            printf("%d\n", decimal);
        } else {
            // Converte de decimal para hexadecimal
            int decimal = atoi(input);
            printf("0x%X\n", decimal);
        }
    }

    return 0;
}
