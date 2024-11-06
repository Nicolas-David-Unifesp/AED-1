#include <stdio.h>

int main() {
    int total_dias;
    scanf("%d", &total_dias);
    
    // Calcula os anos
    int anos = total_dias / 365;
    
    // Calcula os meses
    int meses = (total_dias % 365) / 30;
    s
    // Calcula o número de dias restantes
    int dias = (total_dias % 365) % 30;
  
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    
    return 0;
}
