#include <stdio.h>

int main() {
    int x, y, x1 = 0, y1 = 0, count = 0;
    char commands[1000]; 

    // Leitura do tamanho da matriz
    scanf("%d %d", &x, &y);

    if (x < 100 && y < 100) {
        int mat[x][y];

        // Inicializa a matriz com zeros
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                mat[i][j] = 0;
            }
        }

        mat[0][0] = 1;

        // Limpa o buffer 
        getchar(); // Consome o '\n' 
        fgets(commands, 1000, stdin); // Lê todos os comandos

        // Processa os comandos
        for (int i = 0; commands[i] != '\0'; i++) {
            char c = commands[i];

            if (c == '\n') break; 
            if (c == '>') {
                if (x1 + 1 < x) {
                    x1++;
                    mat[x1][y1] = 1;
                }
            } else if (c == '<') {
                if (x1 - 1 >= 0) {
                    x1--;
                    mat[x1][y1] = 2;
                }
            } else if (c == '^') {
                if (y1 - 1 >= 0) {
                    y1--;
                    mat[x1][y1] = 3;
                }
            } else if (c == 'v') {
                if (y1 + 1 < y) {
                    y1++;
                    mat[x1][y1] = 4;
                }
            } else if (c == '.') {
                if (mat[x1][y1] == 1 && x1 + 1 < x) {
                    x1++;
                    mat[x1][y1] = 1;
                } else if (mat[x1][y1] == 2 && x1 - 1 >= 0) {
                    x1--;
                    mat[x1][y1] = 2;
                }
            } else if (c == '*') {
                count++;
            }
        }

        // Exibe o resultado
        if (x1 < 0 || x1 >= x || y1 < 0 || y1 >= y) {
            printf("!\n");
        } else if (count > 0) {
            printf("*\n");
        } else {
            printf("!\n");
        }
    } else {
        printf("!\n");
    }

    return 0;
}
