#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo a estrutura de célula para a lista encadeada
struct cel {
    char conteudo[100];
    struct cel *seg;
};

typedef struct cel celula;

// Função para inserir no final da lista
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

    // Aqui vamos procurar o amigo 'antes' na lista
    celula *temp = lista;
    while (temp->seg != NULL && strcmp(temp->seg->conteudo, antes) != 0) {// temp-> seg-> conteudo indica que está acessando o conteudo do endereço apontado por temp. 
        temp = temp->seg;
    }

    // Se for encontrado, insere o amigo antes dele
    if (temp->seg != NULL) {
        nova->seg = temp->seg;// Troca o ponteiro do anterior pelo novo, agora nova aponta para ele(Amigo Selecionado);
        temp->seg = nova; // O anterior ao amigo selecionado agora aponta para nova;
    }
}
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

int busca_amigo(celula *lista, char amigo[]) {
    celula *temp = lista->seg;
    while (temp != NULL) {
        if (strcmp(temp->conteudo, amigo) == 0) {
            return 1; // Encontrou
        }
        temp = temp->seg;
    }
    return 0; // Não encontrou
}

int main() {
    char A[1000], B[1000], S[100];
    celula *lista_luiggy, *lista_novos_amigos;

    // Inicializa a lista 1
    lista_luiggy = malloc(sizeof(celula));
    lista_luiggy->seg = NULL; // Deixa, de inicio, vazia
    
    lista_novos_amigos = malloc(sizeof(celula));
    lista_novos_amigos->seg = NULL; 

    
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    fgets(S, sizeof(S), stdin);

    
    A[strcspn(A, "\n")] = 0;
    B[strcspn(B, "\n")] = 0;
    S[strcspn(S, "\n")] = 0;

   /* Vou inserir a lista de amigos atual de Luiggy. 
    Além disso, strtok serve para dividir a string em substrings, tendo o espaço como delimitador delas*/
    
    char *token = strtok(A, " ");
    while (token != NULL) {
        insere_final(lista_luiggy, token);
        token = strtok(NULL, " ");
    }

    token = strtok(B, " ");
    while (token != NULL) {
        insere_final(lista_novos_amigos, token);
        token = strtok(NULL, " ");
    }

    // Verifica qual o comando, se precisa colocar ou não antes de algum nome específico
    if (strcmp(S, "nao") != 0) {
        if (busca_amigo(lista_luiggy, S)) {
            celula *temp = lista_novos_amigos->seg;
            while (temp != NULL) {
                insere_antes(lista_luiggy, temp->conteudo, S);// Vou inserir Antes Já que S != 'nao'
                temp = temp->seg;
            }
        }
    } else {
        // Quando S ='nao' só adciono a lista após a primeira
        celula *temp = lista_novos_amigos->seg;
        while (temp != NULL) {
            insere_final(lista_luiggy, temp->conteudo);
            temp = temp->seg;
        }
    }
    imprime_lista(lista_luiggy);
    
    free(lista_luiggy);
    free(lista_novos_amigos);

    return 0;
}
