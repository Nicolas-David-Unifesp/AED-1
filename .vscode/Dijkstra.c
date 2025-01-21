#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Função para encontrar o vértice com a menor distância
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Função para imprimir o caminho
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Função para imprimir a solução completa
void printSolution(int dist[], int parent[], int V, int src) {
    printf("Vértice\tDistância\tCaminho\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> %d\t%d\t\t", src, i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Implementação do algoritmo de Dijkstra
void dijkstra(int **graph, int src, int V) {
    int dist[V];     // dist[i] armazena a menor distância de src até i
    int sptSet[V];   // sptSet[i] é 1 se o vértice i já foi processado
    int parent[V];   // parent[i] armazena o predecessor de i no caminho mais curto

    // Inicializa as distâncias e o conjunto sptSet
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1; // Nenhum predecessor no início
    }

    dist[src] = 0; // A distância do vértice de origem para ele mesmo é 0

    // Encontra o menor caminho para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice de menor distância
        int u = minDistance(dist, sptSet, V);

        // Marca o vértice como processado
        sptSet[u] = 1;

        // Atualiza as distâncias e os predecessores dos vértices adjacentes
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Atualiza o predecessor
            }
    }

    // Imprime o resultado
    printSolution(dist, parent, V, src);
}

int main() {
    int V;
    printf("Digite o número de vértices: ");
    scanf("%d", &V);

    // Aloca dinamicamente a matriz de adjacência
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    // Entrada da matriz de adjacência
    printf("Digite a matriz de adjacência (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Digite o vértice de origem: ");
    scanf("%d", &src);

    // Executa o algoritmo de Dijkstra
    dijkstra(graph, src, V);

    // Libera a memória alocada
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}