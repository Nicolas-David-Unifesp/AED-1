#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel{
    char conteudo[100];
    struct cel *seg;
};
typedef struct cel celula; 

// Função para inserir um novo amigo na lista
void insere(char y[], celula *p) {// Insere antes da celula*p
    celula *nova;
    nova = malloc(sizeof(celula));
    strcpy(nova->conteudo, y);
    nova->seg = p->seg;
    p->seg = nova;
}

// Função para imprimir a lista de amigos
void imprime_lista(celula *p) {
    p = p->seg;  // Pular o nó inicial
    while (p != NULL) {
        printf("%s", p->conteudo);
        if (p->seg != NULL) {
            printf(" ");  // Imprimir espaço entre os nomes
        }
        p = p->seg;
    }
    printf("\n");
}

// Função para verificar se um amigo está na lista
celula* busca_amigo(celula *lista, char amigo[]) {
    lista = lista->seg;  // Pular o nó inicial
    while (lista != NULL) {
        if (strcmp(lista->conteudo, amigo) == 0) {
            return lista;  // Retorna o ponteiro para o amigo encontrado
        }
        lista = lista->seg;
    }
    return NULL;  // Retorna NULL se o amigo não for encontrado
}

int main() {
    char A[1000], B[1000], S[100];
    celula *lista_luiggy, *lista_novos_amigos, *temp;
    
    // Inicializa a lista de amigos de Luiggy
    lista_luiggy = malloc(sizeof(celula));
    lista_luiggy->seg = NULL;  // Inicialmente a lista está vazia
    
    // Inicializa a lista de novos amigos
    lista_novos_amigos = malloc(sizeof(celula));
    lista_novos_amigos->seg = NULL;  // Inicialmente a lista de novos amigos está vazia

    // Leitura da lista de amigos de Luiggy
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    fgets(S, sizeof(S), stdin);
    
    // Remover o caractere de nova linha (\n) no final das strings
    A[strcspn(A, "\n")] = 0;
    B[strcspn(B, "\n")] = 0;
    S[strcspn(S, "\n")] = 0;

    /* Vou inserir a lista de amigos atual de Luiggy. 
    Além disso, strtok serve para dividir a string em substrings, tendo o espaço como delimitador delas*/ 
    
    char *token = strtok(A, " "); // Atribui ao char ponteiro o primeiro termo
    while (token != NULL) {
        insere(token, lista_luiggy);// Enquanto char de token existir vai adcionando à lista!
        token = strtok(NULL, " "); // Vai alterando o token para entre os outros nomes!
    }
    
    // Vou inserir a nova lista de amigos, a segunda lista com o mesmo processo.
    token = strtok(B, " ");
    while (token != NULL) {
        insere(token, lista_novos_amigos);
        token = strtok(NULL, " ");
    }

    /* Vamos, então verificar onde inserir a lista!*/
    
    if (strcmp(S, "nao") != 0) {
        // Se não achar "nao", vai procurar o amigo S na lista de Luiggy
        temp = busca_amigo(lista_luiggy, S);
        if (temp != NULL) {
            // Insere a nova lista antes do amigo S
            celula *nova_lista = lista_novos_amigos->seg;// Essa celula começa no primeiro termo da segunda lista (lista_novos_amigos->seg)
            while (nova_lista != NULL) {
                insere(nova_lista->conteudo, temp);// Insere antes da lista que começa com o amigo citado.
                nova_lista = nova_lista->seg;
            }
        }
    } else {
        // Inserir a nova lista no final da lista de Luiggy
        temp = lista_luiggy;// Como é final da lista não usamos seg.
        while (temp->seg != NULL) {
            temp = temp->seg;
        }
        // Adicionar todos os novos amigos no final
        celula *nova_lista = lista_novos_amigos->seg;// Começa pelo primeiro termo da lista
        while (nova_lista != NULL) {
            insere(nova_lista->conteudo, temp);
            nova_lista = nova_lista->seg;
        }
    }
    
    
    imprime_lista(lista_luiggy);
    free(lista_luiggy);
    free(lista_novos_amigos);

    return 0;
}

