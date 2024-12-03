#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel*seg;

}typedef struct cel celula;

void Insere_Fila(int y, célula *p) {
    célula *nova;
    nova = malloc (sizeof (célula));
    nova->conteudo = y;
    nova->seg = NULL;

    celula*temp = p;
    while(temp->seg != NULL){
        temp = temp -> seg;
    }
    temp-> seg = nova;
}

int VerificaFila(int y, celula*p,int varpush){// verifico antes se var e a são iguais
    celula*temp = p;
    int contagem;
    while(temp-> seg!= NULL || temp->conteudo != y) {
        temp = temp->seg;
        contagem++;
    }
    if(temp-> conteudo = y && varpush+1 == contagem){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n, varpush=0, varinsere=0,caso,i=0,num;
    celula lista;
    scanf("%d", &n);
    while(i<n){
        scanf("%d %d", &caso,&num);
        if(caso == 1){
            Insere_Fila(num,lista);
            varinsere++;
        }
        if(caso == 2){
            varpush++;
            int verifica = VerificaFila(num, lista, varpush);
            if(verifica== 0){
                printf("Impossible");
            }
        }
    }
    printf("Possible");
}
