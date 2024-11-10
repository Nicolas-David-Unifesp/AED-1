/*
  * nome: 1234.c
  * descrição: Sentença Dançante
  * data: 10/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <ctype.h>  // Para as funções toupper e tolower

void transformar_sentenca(char* sentenca) {
    int i = 0;
    int alternar = 1;  // Inicia com 1 para fazer a primeira letra ser maiúscula

    while (sentenca[i] != '\0') {
        if (sentenca[i] != ' ') {  
            if (alternar) {
                sentenca[i] = toupper(sentenca[i]);  // Torna maiúscula
            } else {
                sentenca[i] = tolower(sentenca[i]);  // Torna minúscula
            }
            alternar = !alternar;  // Vai alternando as letras
        }
        i++;
    }
}

int main() {
    char sentenca[51];  

    while (fgets(sentenca, sizeof(sentenca), stdin)) {
        size_t len = strlen(sentenca);
        if (len > 0 && sentenca[len - 1] == '\n') {
            sentenca[len - 1] = '\0';
        }

        // Função para transformar a sentença
        transformar_sentenca(sentenca);

        // Impressão
        printf("%s\n", sentenca);
    }

    return 0;
}
