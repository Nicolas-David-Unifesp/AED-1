#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *arq; // cria variável ponteiro para o arquivo
    char palavra[20]; // variável do tipo string
    //abrindo o arquivo com tipo de abertura w
    arq = fopen("arquivo_palavra.txt", "w");
    //testando se o arquivo foi realmente criado
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    printf("Escreva uma palavra para gravar no arquivo: ");
    scanf("%s", palavra);
    //usando fprintf para armazenar a string no arquivo
    fprintf(arq, "%s", palavra);
    //usando fclose para fechar o arquivo
    fclose(arq);
    printf("Dados gravados com sucesso!");
    return 0;
}
