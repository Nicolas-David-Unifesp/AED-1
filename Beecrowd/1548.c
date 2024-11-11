/*
  * nome: 1548.c
  * descrição: Fila do Recreio
  * data: 12/10/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Função para ordenar de forma decrescente as notas
}

int main() {
    int N;  // Qauntos vão ser os testes
    scanf("%d", &N);

    while (N--) {
        int M;  // Número de alunos
        scanf("%d", &M);

        int notas[M], notasOrdenadas[M];
        
        // Vamos copiar as notas para o outro vetor
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notasOrdenadas[i] = notas[i];
        }

        // Usamos aqui um qsort que ordena o vetor segundo a função compara
        qsort(notasOrdenadas, M, sizeof(int), compara);

        // Aqui conta-se quantos alunos não precisaram trocar de lugar
        int semTroca = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notasOrdenadas[i]) {
                semTroca++;
            }
        }

        // Imprime quantos alunos não trocaram de lugar
        printf("%d\n", semTroca);
    }

    return 0;
}
