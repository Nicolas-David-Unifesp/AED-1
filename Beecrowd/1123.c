#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 250


typedef struct {
    int cidade1, cidade2, pedagio;
} Estrada;

// dijkstra- encontra o menor custo
int dijkstra(int numCidades, int numServicos, int cidadeConsertada, Estrada estradas[], int numEstradas) {
    int distancias[MAXN];
    int visitado[MAXN] = {0}; 
    int adjacencia[MAXN][MAXN]; // Matriz pra representar as estradas

    // Coloca as distâncias ao infinito
    for (int i = 0; i < numCidades; i++) {
        distancias[i] = INT_MAX;
        for (int j = 0; j < numCidades; j++) {
            adjacencia[i][j] = INT_MAX;
        }
    }

    // Define os valores conforme o que é fornecido
    for (int i = 0; i < numEstradas; i++) {
        adjacencia[estradas[i].cidade1][estradas[i].cidade2] = estradas[i].pedagio;
        adjacencia[estradas[i].cidade2][estradas[i].cidade1] = estradas[i].pedagio;
    }

    distancias[cidadeConsertada] = 0; // distância da cidade concertada é zero, né

    // Algoritmo de Dijkstra
    for (int i = 0; i < numCidades; i++) {
        int cidadeAtual = -1;
        
        // Encontra a cidade não visitada com a menor distância
        for (int j = 0; j < numCidades; j++) {
            if (!visitado[j] && (cidadeAtual == -1 || distancias[j] < distancias[cidadeAtual])) {
                cidadeAtual = j;
            }
        }

        // Se a distância for infinita interrompe o loop
        if (distancias[cidadeAtual] == INT_MAX) break;

        visitado[cidadeAtual] = 1; // Vai maracndo a cidade como visitada

        // Atualiza as distâncias
        for (int v = 0; v < numCidades; v++) {
            if (!visitado[v] && adjacencia[cidadeAtual][v] != INT_MAX && distancias[cidadeAtual] + adjacencia[cidadeAtual][v] < distancias[v]) {
                // Vamos verificar se a cidade faz parte da rota de serviço!!
                if (cidadeAtual >= 0 && cidadeAtual < numServicos && v == cidadeAtual + 1) {
                    distancias[v] = distancias[cidadeAtual] + adjacencia[cidadeAtual][v];
                } else if (cidadeAtual >= numServicos || v >= numServicos) {
                    distancias[v] = distancias[cidadeAtual] + adjacencia[cidadeAtual][v];
                }
            }
        }
    }

    // Retorna o custo mínimo
    return distancias[numServicos - 1];
}

int main() {
    int numCidades, numEstradas, numServicos, cidadeConsertada;
    while (scanf("%d %d %d %d", &numCidades, &numEstradas, &numServicos, &cidadeConsertada) && numCidades && numEstradas && numServicos && cidadeConsertada) {
        Estrada estradas[numEstradas];

        for (int i = 0; i < numEstradas; i++) {
            scanf("%d %d %d", &estradas[i].cidade1, &estradas[i].cidade2, &estradas[i].pedagio);
        }

        // Calcula e imprime o valor do pedágio
        int resultado = dijkstra(numCidades, numServicos, cidadeConsertada, estradas, numEstradas);
        printf("%d\n", resultado);
    }

    return 0;
}
