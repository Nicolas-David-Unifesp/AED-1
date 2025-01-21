/*
  * nome: 1123.c
  * descrição: Desvio de Rota
  * data: 21/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 260
#define LIMITE 9999999

//**************************************************************************//

typedef struct {
    int cidade, custo;
} ii;

typedef struct {
    ii elementos[MAXN * MAXN];
    int tamanho;
} MinHeap;// HeapMin

//**************************************************************************//

void inserir(MinHeap *heap, ii elemento) {// Inserção Heap Min
    heap->elementos[heap->tamanho] = elemento;
    int i = heap->tamanho;
    heap->tamanho++;

    while (i != 0 && heap->elementos[i].custo < heap->elementos[(i - 1) / 2].custo) {
        ii temp = heap->elementos[i];
        heap->elementos[i] = heap->elementos[(i - 1) / 2];
        heap->elementos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

//**************************************************************************//

ii extrairMinimo(MinHeap *heap) {// Extrai o elemento mínimo do heap min
    ii raiz = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    int i = 0;

    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (menor + 1 < heap->tamanho && heap->elementos[menor + 1].custo < heap->elementos[menor].custo) {
            menor++;
        }
        if (heap->elementos[i].custo <= heap->elementos[menor].custo) {
            break;
        }
        ii temp = heap->elementos[i];
        heap->elementos[i] = heap->elementos[menor];
        heap->elementos[menor] = temp;
        i = menor;
    }

    return raiz;
}
//**************************************************************************//

// Variaveis Globais ( Tive que colocá-las aqui para ficar mais organizado)
int visitado[MAXN];
ii grafo[MAXN][MAXN];
int grau[MAXN];

// ************************************************************************//

int main() {
    int n, m, c, k;
    while (scanf("%d %d %d %d", &n, &m, &c, &k) && (n || m || c || k)) {// Vai lendo até 0 0 0 0
        for (int i = 0; i <= n; i++) {
            grau[i] = 0;
            visitado[i] = 0;
        }

        while (m--) {// Construindo o Grafo
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            grafo[u][grau[u]].cidade = v;
            grafo[u][grau[u]++].custo = peso;
            grafo[v][grau[v]].cidade = u;
            grafo[v][grau[v]++].custo = peso;
        }

        MinHeap dijkstra;
        dijkstra.tamanho = 0;
        ii inicial = {k, 0};
        inserir(&dijkstra, inicial);
     
        // DIJSKTRA
        while (dijkstra.tamanho > 0) {
            ii davez = extrairMinimo(&dijkstra);
            if (visitado[davez.cidade]) continue;// Se já foi visitado pula
            visitado[davez.cidade] = 1;// Marca como Visitado
            if (davez.cidade == c - 1) {// Aqui é para caso chegue ao destino, aí quebra o ciclo
                printf("%d\n", davez.custo);
                break;
            }
            // Se está na rota de serviço, só vamos considerar a rota!!!
            if (davez.cidade <= c - 1) {
                for (int i = 0; i < grau[davez.cidade]; i++) {
                    if (grafo[davez.cidade][i].cidade == davez.cidade + 1) {
                        ii novo = {davez.cidade + 1, grafo[davez.cidade][i].custo + davez.custo};
                        inserir(&dijkstra, novo);
                        break;
                    }
                }
            } else {// Caso não esteja, considera o resto!
                for (int i = 0; i < grau[davez.cidade]; i++) {
                    ii novo = {grafo[davez.cidade][i].cidade, grafo[davez.cidade][i].custo + davez.custo};
                    inserir(&dijkstra, novo);
                }
            }
        }
    }

    return 0;
}
