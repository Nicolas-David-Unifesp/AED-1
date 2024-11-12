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
    int conteudo; 
    struct cel *seg;
};
typedef struct cel celula;

void Busca_Remove(int x, celula**lst){
    celula *p, *q;
    p = *lst;
    q = *lst->seg;
    while(q!=NULL && q-> conteudo != x){
        p = q;
        q = q-> seg;
    }
    if(q!=NULL){
        p->seg = q->seg;
        free(*q);
    }
}
 void inserefinal(int y, celula**p){
    celula*nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova-> seg = NULL;

    if(*p == NULL){
        *p = nova;
    }else{
        celula *temp = *p;
        while (temp->seg != NULL) {
            temp = temp->seg;
        }
        temp->seg = nova;
    }
}

int main(){
    int N, M, var[5000], var2[5000];
    scanf("%d",&N);
    celula*fila = NULL;
    for(int i = 0 ; i<N; i++){
        scanf("%d", &var[i]);
        inserefinal(var[i], &fila);
    }
    scanf("%d",&M);
    for(int j = 0 ; j<N; j++){
        scanf("%d", &var2[j]);
        Busca_Remove(var2[j], &fila);
    }
    
    return 0;
}
    
