/*
  * nome: 1256.c
  * descrição: Tabelas Hash
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Novo Nó
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

//Insere uma chave na lista encadeada específica
void insert(Node* table[], int index, int key) {
    Node* newNode = createNode(key);
    newNode->next = table[index];
    table[index] = newNode;
}

//Imprime a tabelinha dos números
void printTable(Node* table[], int M) {
    for (int i = 0; i < M; i++) {
        printf("%d -> ", i);
        Node* current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("\\\n");
    }
}

int main() {
    int N; 
    scanf("%d", &N);
    
    while (N--) {
        int M, C;// Número de Endereços e Numero de chaves, respectivamente.
        scanf("%d %d", &M, &C);
        
        // Cria a tabela com m posições todas em NULL
        Node* table[M];
        for (int i = 0; i < M; i++) {
            table[i] = NULL;
        }

        // Leitura de Chaves
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int index = key % M;// Função pedida
            insert(table, index, key);//Insere a Chave na Tabela
        }
        printTable(table, M);
        if (N > 0) {
            printf("\n");
        }
    }

    return 0;
}
