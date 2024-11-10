/*
  * nome: 2728.c
  * descrição: 
  * data: 10/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel {
    char conteudo[21]; 
    struct cel *seg;
};
typedef struct cel celula;

void insere(celula* lista, char* token) {
    // Cria um novo nó
    celula* novo = malloc(sizeof(celula));
    strncpy(novo->conteudo, token, sizeof(novo->conteudo) - 1);  // Copia o token para o novo nó
    novo->conteudo[sizeof(novo->conteudo) - 1] = '\0';  // Garante a terminação do string

    novo->seg = lista->seg;
    lista->seg = novo;  // Coloca o novo nó no começo da lista
}

int var(celula*lista, char cobol[] , char COBOL[]){
    celula *temp = lista-> seg;
    int n = 0;
      while (temp != NULL) {
        if (temp-> conteudo[0] == cobol[n] || temp-> conteudo[0] == COBOL[n] ||temp-> conteudo[strlen(temp->conteudo)-1] == cobol[n] || temp-> conteudo[strlen(temp->conteudo)-1] == COBOL[n]){
            n++;
        }
        temp = temp->seg;
    }
    if(n==5){
         return 1; 
    }
    else{
       return 0;  
    }
   
   
}
    void imprime_lista(celula *lista) {
    celula *temp = lista->seg; 
    while (temp != NULL) {
        printf("%s", temp->conteudo);
        if (temp->seg != NULL) {
            printf(" "); 
        }
        temp = temp->seg;
    }
    printf("\n");
}
int main() {
    char cobol[6];
    cobol[0] = 'l';
    cobol[1] = 'o';
    cobol[2] = 'b';
    cobol[3] = 'o';
    cobol[4] = 'c';
    cobol[5] = '\0';
    char COBOL[6];
    COBOL[0] = 'L';
    COBOL[1] = 'O';
    COBOL[2] = 'B';
    COBOL[3] = 'O';
    COBOL[4] = 'C';
    COBOL[5] = '\0';
    
    
    char linha[1001]; 
    fgets(linha, 1001, stdin);
    linha[strcspn(linha, "\n")] = 0;
    
    celula* vo_lista = malloc(sizeof(celula));
    vo_lista -> seg = NULL;
    
    char *token = strtok(linha, "-");
    while (token != NULL) {
        insere(vo_lista, token);  
        token = strtok(NULL, "-");  // Avança para o próximo token
        }

    if (var(vo_lista, cobol,COBOL) == 1) printf("GRACE HOPPER\n");
    else{
        printf("BUG\n");
    }
     celula* temp;
    while (vo_lista != NULL) {
        temp = vo_lista;
        vo_lista = vo_lista->seg;
        free(temp);
    }

    return 0;
}
