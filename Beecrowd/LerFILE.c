#include <stdio.h>
#include <stdlib.h>

int main(void)
{
FILE *arq; // cria variável ponteiro para o arquivo
char *result, Linha[100];
arq = fopen("arquivo_palavra.txt", "r");
if(arq == NULL)
{ printf("Erro na abertura do arquivo!");

return 1; }
while (!feof(arq)){
result=fgets(Linha, 100, arq);
if (result) printf("%s",Linha);
}

fclose(arq);
}
