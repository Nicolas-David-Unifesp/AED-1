/*
  * nome: 2460.c
  * descrição: 
  * data: 12/11/2024
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

void 


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


int main (){
  

}
