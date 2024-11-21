#include <stdio.h>

int main() {
    int N;  // Número de casos de teste
    scanf("%d", &N);

    getchar();

    for (int i = 0; i < N; i++) {
        char texto[51]; 
        int deslocamento;  // Quantos passos para o deslocamento

        fgets(texto, sizeof(texto), stdin);  // Lê o texto codificado
        texto[strcspn(texto, "\n")] = 0;

        scanf("%d", &deslocamento);  // Lê o valor deslocado
        getchar();

        // Processo de descodificar o código
        for (int j = 0; texto[j] != '\0'; j++) {
            if (texto[j] >= 'A' && texto[j] <= 'Z') {
                // Desloca a letra para a esquerda
                char letra_original = texto[j] - deslocamento;
                
                // Verifica se ultrapassou a letra 'A'
                if (letra_original < 'A') {
                    letra_original += 26;  // Volta para o final do alfabeto
                }
                
                printf("%c", letra_original);
            }
        }

        printf("\n");
    }

    return 0;
}
