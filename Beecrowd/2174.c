


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char pomekonsDif[151][1001];
    char auxiliar[1001];
    int i, j = 0, quantPomekon = 0, casos;
    bool tem;

    scanf("%d", &casos);// Escaneia o número de casos

    while (casos--){
        tem = false;
        scanf("%s", auxiliar); // Lê o nome de um pomekon da entrada
        for (i = 0; i < 151; i++){
            if (strcmp(pomekonsDif[i], auxiliar) == 0){
                tem = true;
                break;
            }
        }
        // Se o pomekon não foi encontrado, registra ele
        if (!tem){
            strcpy(pomekonsDif[j], auxiliar);
            j++;
            quantPomekon++;
        }
    }
    // Imprime a quantidade de pomekons faltantes
    printf("Falta(m) %d pomekon(s).\n", 151-quantPomekon);


    return 0;
}
