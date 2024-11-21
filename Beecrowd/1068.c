/*
  * nome: 1068.c
  * descrição: Balanço de Parenteses
  * data: 13/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */




#include <string.h>
#include <stdio.h>

int main(){
    char expressao[1001];
    int i, tam, parenteses;

    while(scanf("%s\n", &expressao) != EOF){//Lê até que não aja mais o que ler
        parenteses = 0;// Começa em 0 o número de parenteses que vão sobrar
        tam = strlen(expressao); // tamanho da expressão

        for(i = 0; i < tam; ++i){
            if(expressao[i] == '('){
                ++parenteses;// Se for ( adciona ao parenteses
            }else if(expressao[i] == ')'){//se ) retira dos parenteses
                if(parenteses > 0)  --parenteses;// Garante tbm que o número seja positivo
                else                break;// Quebra o looping se for negativo!
            }
        }

        if(i == tam && parenteses == 0) printf("correct\n");
        else                            printf("incorrect\n");
    }

    return 0;
}
