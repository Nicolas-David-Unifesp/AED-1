/*
  * nome: 1238.c
  * descrição: Combinador
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <string.h>

void combinar_strings(char str1[], char str2[], char resultado[]) {
    int i = 0, j = 0, k = 0;
    int len1 = strlen(str1), len2 = strlen(str2);
    
    while (i < len1 && j < len2) {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }
    
    while (i < len1) {
        resultado[k++] = str1[i++];
    }
    
    while (j < len2) {
        resultado[k++] = str2[j++];
    }
    
    resultado[k] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char str1[51], str2[51], resultado[101];
        scanf("%s %s", str1, str2);
        
        combinar_strings(str1, str2, resultado);
        
        printf("%s\n", resultado);
    }
    
    return 0;
}
