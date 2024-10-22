/*
  * nome: 1383.c
  * descrição: Criador de Sudoku-Exercício 1383 do Beecrowd
  * data: 22/10/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#define TAM 9

int sudoku_var(int sudoku[TAM][TAM]) {
    /* Verifica as linhas*/
    for (int i = 0; i < TAM; i++) {
        int seen[TAM + 1] = {0}; /*Inicializa todos os números como não visto*/
        for (int j = 0; j < TAM; j++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9 || seen[num] == 1) {
                return 0; 
            }
            seen[num] = 1; /*Marca algum número visto*/ 
        }
    }

     /* Verifica as colunas- Mesmo Processo que o Anterior*/
    for (int j = 0; j < TAM; j++) {
        int seen[TAM + 1] = {0}; 
        for (int i = 0; i < TAM; i++) {
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
            int seen[TAM + 1] = {0}; 
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
    int n;
    scanf("%d", &n); /*Número de Instâncias- Número de Sudokus para Verificação*/
    for (int instancia = 1; instancia <= n; instancia++) {
        int sudoku[TAM][TAM];

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);/*Para Cada Instância um Sudoku Diferente!*/
        if (sudoku_var(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
