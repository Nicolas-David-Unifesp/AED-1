/*
  * nome: 2253.c
  * descrição: Validador de Senhas
  * data: 28/11/2024
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>

// Verifica se a senha é válida
int Valida(char *senha, int tamanho){
    int i;
    int maiusculas = 0, minusculas = 0, digitos = 0, outros = 0; 

    // Percorre cada caractere para verificar os critérios
    for (i = 0; senha[i] != '\0'; i++){
        if (senha[i] >= 'A' && senha[i] <= 'Z')  // Maiúscula
            maiusculas = 1;
        else if (senha[i] >= 'a' && senha[i] <= 'z')  // Minúscula
            minusculas = 1;
        else if (senha[i] >= '0' && senha[i] <= '9')  // Dígito
            digitos = 1;
        else  // Outros
            outros = 1;
    }

    // Se não houverem caracteres inválidos, retorna que é válida
    if (outros == 0 && maiusculas == 1 && minusculas == 1 && digitos == 1)
        return 1;
    else  // Senão, retorna 0 (inválida)
        return 0;
}

// Função para remover o caractere de nova linha '\n' do final da string
void RemoveBarraN(char *str){
    // Se o último caractere for '\n', substitui por '\0'
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

int main(){
    int i, tamanho = 0;
    char senha[101];

    // Lê as senhas
    while (fgets(senha, 101, stdin) != NULL){
        RemoveBarraN(senha);  // Remove o '\n' no final
        tamanho = strlen(senha); // tamanho

        // Verifica se a senha tem entre 6 e 32 caracteres e sua validade
        if (tamanho >= 6 && tamanho <= 32 && Valida(senha, tamanho) == 1)
            printf("Senha valida.\n");  // Válida
        else  
            printf("Senha invalida.\n");  // Inválida
    }

    return 0;
}
