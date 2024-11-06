#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo a estrutura de célula para a lista encadeada
struct cel {
    char conteudo[100];
    struct cel *seg;
};

typedef struct cel celula;

// Função para inserir um amigo no final da lista
void insere_final(celula *lista, char y[]) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->conteudo, y);
    nova->seg = NULL;

    // Percorrer até o final da lista
    celula *temp = lista;
    while (temp->seg != NULL) {
        temp = temp->seg;
    }
    temp->seg = nova;
}

// Função para inserir um amigo antes de um amigo específico
void insere_antes(celula *lista, char y[], char antes[]) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->conteudo, y);
    nova->seg = NULL;

    // Procurar o amigo 'antes' na lista
    celula *temp = lista;
    while (temp->seg != NULL && strcmp(temp->seg->conteudo, antes) != 0) {
        temp = temp->seg;
    }

    // Se o amigo 'antes' foi encontrado, insere o novo amigo antes dele
    if (temp->seg != NULL) {
        nova->seg = temp->seg;
        temp->seg = nova;
    }
}

// Função para imprimir a lista de amigos
void imprime_lista(celula *lista) {
    celula *temp = lista->seg;
    while (temp != NULL) {
        printf("%s", temp->conteudo);
        if (temp->seg != NULL) {
            printf(" "); // Imprimir espaço entre os nomes
        }
        temp = temp->seg;
    }
    printf("\n");
}

// Função para buscar um amigo na lista
int busca_amigo(celula *lista, char amigo[]) {
    celula *temp = lista->seg;
    while (temp != NULL) {
        if (strcmp(temp->conteudo, amigo) == 0) {
            return 1; // Amigo encontrado
        }
        temp = temp->seg;
    }
    return 0; // Amigo não encontrado
}

int main() {
    char A[1000], B[1000], S[100];
    celula *lista_luiggy, *lista_novos_amigos;

    // Inicializa a lista de amigos de Luiggy
    lista_luiggy = malloc(sizeof(celula));
    lista_luiggy->seg = NULL; // Inicialmente a lista está vazia

    // Inicializa a lista de novos amigos
    lista_novos_amigos = malloc(sizeof(celula));
    lista_novos_amigos->seg = NULL; // Inicialmente a lista de novos amigos está vazia

    // Leitura das listas de amigos de Luiggy e dos novos amigos
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    fgets(S, sizeof(S), stdin);

    // Remover o caractere de nova linha (\n) no final das strings
    A[strcspn(A, "\n")] = 0;
    B[strcspn(B, "\n")] = 0;
    S[strcspn(S, "\n")] = 0;

    // Inserir a lista de amigos de Luiggy
    char *token = strtok(A, " ");
    while (token != NULL) {
        insere_final(lista_luiggy, token);
        token = strtok(NULL, " ");
    }

    // Inserir a lista de novos amigos
    token = strtok(B, " ");
    while (token != NULL) {
        insere_final(lista_novos_amigos, token);
        token = strtok(NULL, " ");
    }

    // Verificar onde inserir os novos amigos
    if (strcmp(S, "nao") != 0) {
        // Se S não for "nao", procurar o amigo S na lista de Luiggy
        if (busca_amigo(lista_luiggy, S)) {
            // Inserir a lista de novos amigos antes do amigo S
            celula *temp = lista_novos_amigos->seg;
            while (temp != NULL) {
                insere_antes(lista_luiggy, temp->conteudo, S);
                temp = temp->seg;
            }
        }
    } else {
        // Se S for "nao", adicionar os novos amigos no final da lista de Luiggy
        celula *temp = lista_novos_amigos->seg;
        while (temp != NULL) {
            insere_final(lista_luiggy, temp->conteudo);
            temp = temp->seg;
        }
    }

    // Imprimir a lista final de amigos
    imprime_lista(lista_luiggy);

    // Liberar memória
    free(lista_luiggy);
    free(lista_novos_amigos);

    return 0;
}
