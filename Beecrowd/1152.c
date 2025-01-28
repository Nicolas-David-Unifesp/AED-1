#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para usar INT_MAX

typedef struct {
    int u, v, w;
    //os dois vertices e o peso da aresta
} Aresta;

Aresta *g; // vetor de arestas (alocado dinamicamente)
int *p; // vetor para Union-Find (alocado dinamicamente)

int parent(int x) { // recebe um vértice em específico para conferir seu parentesco e retorná-lo
    if (x != p[x]) { 
        p[x] = parent(p[x]); // faz a chamada recursiva até que o vértice seja seu próprio parente
    }
    return p[x];
}

int kruskal(int x) { // recebe o número de arestas após ordenação destas
    int y, z; // os dois parentes dos vértices de cada aresta 
    int aux = 0;

    for (int i = 0; i < x; i++) {
        y = parent(g[i].u);
        z = parent(g[i].v);

        if (y != z) { // se os parentescos são diferentes, um ciclo não é formado
            p[y] = z; // une os parentescos para evitar repetição
            aux += g[i].w; // soma da árvore mínima
        }
    }
    return aux;
}

int compara(const void *a, const void *b) { // substituir por uma função de ordenação, mas para usar qsort, uma função compara é essencial
    Aresta *aresta1 = (Aresta *)a;
    Aresta *aresta2 = (Aresta *)b;
    return aresta1->w - aresta2->w; // a função ordena de modo crescente a partir da diferença dos pesos das arestas
}

void AddStruct(int A, int tot){
    for (int i = 0; i < A; i++) { // percorre todas as arestas e as adiciona na struct arestas dentro de g
            scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
            tot += g[i].w; // tamanho total das arestas
    }
}
void DefinePaiInicial(int V){
    for (int i = 0; i < V; i++) { // define os parentes iniciais
            p[i] = i;
    }
}

int main() {
    int V, A;// V = Verices e A = Arestas

    while (scanf("%d %d", &V, &A), V && A) // repete enquanto V e A != 0
    {
        int tot = 0;
        // Alocação Dinâmica com base no número de arestas e vértices
        g = (Aresta *)malloc(A * sizeof(Aresta)); // armazena as arestas// Vetor Dinâmico
        p = (int *)malloc(V * sizeof(int));       // armazena os pais (Union-Find)// Vértices
        
        AddStruct(A, tot);//Add na struct arestas em g
        
        qsort(g, A, sizeof(Aresta), compara); // g-primeiro elemento do array, A-número de elementos, tamanho dos elementos, função compara
        
        DefinePaiInicial(V);// Para o Union-Find
        
        printf("%d\n", tot - kruskal(A)); // número da economia para Kruskal pelo número de arestas
        
        free(g);
        free(p);
    }

    return 0;
}
