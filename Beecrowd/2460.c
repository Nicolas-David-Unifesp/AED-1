#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg;
};
typedef struct cel celula;

// Função para remover um elemento da lista
void Busca_Remove(int x, celula** lst) {
    celula *p, *q;
    p = *lst;
    
    // Corrigido: acessando corretamente o ponteiro seg
    q = *lst;  // Começamos com o primeiro elemento
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    
    if (q != NULL) {  // Encontramos o elemento a ser removido
        if (q == *lst) {  // Se o elemento a ser removido for o primeiro
            *lst = q->seg;  // Atualiza o ponteiro da lista
        } else {
            p->seg = q->seg;  // Remove o elemento
        }
        free(q);  // Libera a memória
    }
}

// Função para inserir um elemento no final da lista
void inserefinal(int y, celula** p) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = NULL;

    if (*p == NULL) {  // Se a lista estiver vazia
        *p = nova;  // O novo nó se torna o primeiro
    } else {
        celula *temp = *p;
        while (temp->seg != NULL) {  // Percorre até o final
            temp = temp->seg;
        }
        temp->seg = nova;  // Insere no final
    }
}

int main() {
    int N, M, var[5000], var2[5000];
    
    // Leitura do número de elementos na lista
    scanf("%d", &N);
    celula *fila = NULL;
    
    // Leitura dos elementos para inserir na fila
    for (int i = 0; i < N; i++) {
        scanf("%d", &var[i]);
        inserefinal(var[i], &fila);  // Insere no final da lista
    }
    
    // Leitura do número de elementos a remover
    scanf("%d", &M);
    
    // Leitura dos elementos a serem removidos da fila
    for (int j = 0; j < M; j++) {
        scanf("%d", &var2[j]);
        Busca_Remove(var2[j], &fila);  // Remove o elemento da lista
    }
    
    // Impressão dos elementos restantes na lista (opcional, se necessário)
    celula *temp = fila;
    while (temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->seg;
    }
    printf("\n");
    
    return 0;
}
