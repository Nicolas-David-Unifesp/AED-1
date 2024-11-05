#include <stdio.h>
#include <string.h>

struct cel{
    char conteudo[1000];
    struct cel *seg;
}
typedef struct cel celula; 

void insere (char y[], celula *p){
    celula * nova;
    nova = malloc (sizeof(celula));
    nova -> conteudo  ; 
}

int main() {
    int i =0, k=0;
    char A[100], B[100], var[100], var2[100];
    gets(A);
    gets(B);
    gets(var);

    while(A[i]!='\0'){
        if (A[i] = ' '){
            for(int j = i-1; A[j]!= ' ' || j = 0; j--){
                var2[k] = A[j];
                k++;
            }
        }
        i++;
    }


 
    return 0;
}
