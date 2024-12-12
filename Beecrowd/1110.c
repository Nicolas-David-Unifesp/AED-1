#include <stdio.h>
#include <stdlib.h>

// Struct
struct cel {
    int carta;
    struct cel *seg;
};

typedef struct cel pilha;

// Empilha no Topo
void Empilhar(int y, pilha *p) {
    pilha *nova;
    nova = malloc(sizeof(pilha));
    nova->carta = y;
    nova->seg = p->seg;
    p->seg = nova;
}

// Remove e coloca no final
int CartaRestante(pilha *r) {
    if (r->seg == NULL) return -1; // Caso não haja cartas, retorna -1.
    
    while (r->seg->seg != NULL) { // Enquanto houver mais de uma carta na pilha:
        // Remove a carta e imprime.
        pilha *lixo = r->seg;
        r->seg = lixo->seg;
        if (lixo->carta == 1) {
            printf(" %d", lixo->carta);
        } else {
            printf(", %d", lixo->carta);
        }
        free(lixo);

        // Coloca no fim da pilha
        pilha *atual = r->seg;
        r->seg = atual->seg;
        atual->seg = NULL;

        pilha *aux = r;
        while (aux->seg != NULL) { // Encontra o Fim
            aux = aux->seg;
        }
        aux->seg = atual;
    }
    return r->seg->carta; // Retorna a carta que restou no fim de todos os processos
}

int main() {
    int n, i;
    pilha *p;
    
    while (1) {// Lê até que seja digitado 0
        p = malloc(sizeof(pilha));
        p->seg = NULL;
        scanf("%d", &n);
        if (n == 0)
            break;
        
        // Empilha as cartas as cartas que o usuário queira e as numera
        for (i = n; i >= 1; i--) {
            Empilhar(i, p);
        }
        
        // Processo de descarte e alocação da carta no final da pilha
        printf("Discarded cards:");
        int j = CartaRestante(p);
        printf("\nRemaining card: %d\n", j);

        free(p);
    }

    return 0;
}