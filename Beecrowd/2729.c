/*
  * nome: 2729.c
  * descrição: Lista de Compras
  * data: 07/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Lista Encadeada
struct cel {
    char conteudo[1000];
    struct cel *seg;
};

typedef struct cel celula;

// Função para inserir no final da lista
void insere_final(celula *lista, char y[]) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->conteudo, y);
    nova->seg = NULL;

    celula *temp = lista;
    while (temp->seg != NULL) {
        temp = temp->seg;
    }
    temp->seg = nova;
}

// Função para imprimir a lista
void imprime_lista(celula *lista) {
    celula *temp = lista->seg;
    while (temp != NULL) {
        printf("%s", temp->conteudo);
        if (temp->seg != NULL) {
            printf(" "); // Dá espaço entre os nomes
        }
        temp = temp->seg;
    }
    printf("\n");
}


// Exclui Frutas Repetidas
void excluir_repetidos(celula *lista) {
    celula *var = lista->seg;  // Ponteiro para percorrer a lista

    // Percorre a lista
    while (var != NULL) {
        celula *anterior = var;
        celula *temp = var->seg;

        
        while (temp != NULL) {
            if (strcmp(var->conteudo, temp->conteudo) == 0) {
                // Se encontrar um conteúdo igual, remove o nó 'temp'
                anterior->seg = temp->seg;  
                free(temp);                  
                temp = anterior->seg;        
            } else {
                anterior = temp;           
                temp = temp->seg;           
            }
             /*Se: O nó anterior aponta para o próximo nó de 'temp'. Após isso, ele libera a memória do nó.
             Logo, depois é movido para o próximo nó após a exclusão. Senão, trocam-se as ordens dos ponteiros*/
        }
        var = var->seg;  // Move o ponteiro 'var' para o próximo nó
    }
}

// Ordena em Ordem Alfabética
void ordem_alfabetica(celula *lista) {
    if (lista->seg == NULL || lista->seg->seg == NULL) {
        // Já está ordenado
        return;
    }

    celula *sorted = NULL;  // Esta será a lista ordenada
    celula *current = lista->seg;  // Começa no primeiro nó real

    while (current != NULL) {
        // Armazena o próximo nó para continuar o loop
        celula *next = current->seg;

        // Inserir o nó 'current' na lista 'sorted'
        celula *prev = NULL;
        celula *temp = sorted;

        // Encontra a posição correta para inserir 'current'
        while (temp != NULL && strcmp(temp->conteudo, current->conteudo) < 0) {
            prev = temp;
            temp = temp->seg;
        }

        // Começa no inicio da lista
        if (prev == NULL) {
            current->seg = sorted;
            sorted = current;
        } else {
            prev->seg = current;
            current->seg = temp;
        }

        // Move o nó
        current = next;
    }
    // Atualiza a lista original
    lista->seg = sorted;
}

        


int main() {
    char A[1000];
    int N;
    celula *lista_val;

    // Inicializa a lista 1
    lista_val = malloc(sizeof(celula));
    lista_val->seg = NULL; // Deixa, de inicio, vazia

    scanf("%d",& N);
    getchar();
    for(int i = 0 ; i < N; i++){
        memset(A, 0, sizeof(A));  // Ou A[0] = '\0';
        fgets(A, sizeof(A), stdin);

        A[strcspn(A, "\n")] = 0;

        char *token = strtok(A, " ");
        while (token != NULL) {
            insere_final(lista_val, token);
            token = strtok(NULL, " ");
        }
    }
    excluir_repetidos(lista_val);
    ordem_alfabetica(lista_val);
    imprime_lista(lista_val);

    
    return 0;

}
