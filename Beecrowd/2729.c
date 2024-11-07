/*
  * nome: 2729.c
  * descrição: Lista de Compras
  * data: 07/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel {
    char conteudo[21]; 
    struct cel *seg;
};

typedef struct cel celula;


void insere_sem_duplicata(celula *lista, const char *item) {
    celula *temp = lista;
    while (temp->seg != NULL) {
        if (strcmp(temp->seg->conteudo, item) == 0) {
            return;  // Item duplicado encontrado, não insere
        }
        temp = temp->seg;
    }

    // Se não for duplicado, insere no final da lista
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->conteudo, item);
    nova->seg = NULL;
    temp->seg = nova;
}

// Função para ordenar a lista em ordem alfabética
void ordena_lista(celula *lista) {
    if (lista->seg == NULL || lista->seg->seg == NULL) {
        return; // Já está ordenado ou lista com apenas 1 item
    }

    celula *temp, *i, *j;
    char aux[21];

    
    for (i = lista->seg; i != NULL; i = i->seg) {
        for (j = i->seg; j != NULL; j = j->seg) {
            if (strcmp(i->conteudo, j->conteudo) > 0) {
                // Troca os conteúdos dos nós
                strcpy(aux, i->conteudo);
                strcpy(i->conteudo, j->conteudo);
                strcpy(j->conteudo, aux);
            }
        }
    }
}

// Imprime
void imprime_lista(celula *lista) {
    celula *temp = lista->seg; 
    while (temp != NULL) {
        printf("%s", temp->conteudo);
        if (temp->seg != NULL) {
            printf(" "); 
        }
        temp = temp->seg;
    }
    printf("\n");
}

int main() {
    int N;  
    scanf("%d", &N);
    getchar();  

    for (int i = 0; i < N; i++) {
        char linha[1001]; 
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = 0;  

        // Criamos uma Lista
        celula *lista = malloc(sizeof(celula));
        lista->seg = NULL;  // A lista começa vazia

        
        char *token = strtok(linha, " ");
        while (token != NULL) {
            insere_sem_duplicata(lista, token);  // Insere sem duplicata
            token = strtok(NULL, " ");  // Avança para o próximo token
        }

        // Ordena a lista encadeada em ordem alfabética
        ordena_lista(lista);

        // Imprime a lista organizada
        imprime_lista(lista);

        // Libera a memória da lista encadeada
        celula *temp;
        while (lista->seg != NULL) {
            temp = lista->seg;
            lista->seg = lista->seg->seg;
            free(temp);
        }
        free(lista);  // Libera a cabeça da lista
    }

    return 0;
}

