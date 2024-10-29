
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sudokurand(int sudoku[9][9]){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            do {
                srand(time(0));
                sudoku[i][j] = rand() % 9 + 1;
            } while(sudoku_var(sudoku) != 1);
        }
    }
    
}

int sudoku_var(int sudoku[9][9]) {
    /* Verifica as linhas*/
    for (int i = 0; i < 9; i++) {
        int seen[10] = {0}; /*Inicializa todos os números como não visto*/
        for (int j = 0; j < 9; j++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9 || seen[num] == 1) {
                return 0;
            }
            seen[num] = 1; /*Marca algum número visto*/
        }
    }

     /* Verifica as colunas- Mesmo Processo que o Anterior*/
    for (int j = 0; j < 9; j++) {
        int seen[9 + 1] = {0};
        for (int i = 0; i < 9; i++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9 || seen[num] == 1) {
                return 0;
            }
            seen[num] = 1;
        }
    }

    /*Verifica as regiões 3x3, se há números diferentes em cada bloco*/
    for (int bloco_linha = 0; bloco_linha < 3; bloco_linha++) {
        for (int blocol = 0; blocol < 3; blocol++) {
            int seen[9 + 1] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = sudoku[bloco_linha * 3 + i][blocol * 3 + j];
                    if (num < 1 || num > 9 || seen[num] == 1) {
                        return 0;
                    }
                    seen[num] = 1;
                }
            }
        }
    }

    return 1; /*Retorna 1 se tudo estiver correto*/
}

int main() {
    int sudoku[9][9];
    sudokurand(sudoku);
    return 0;
}
