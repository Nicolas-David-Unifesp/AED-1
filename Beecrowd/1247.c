/*
  * nome: 1247.c
  * descrição: Guarda Costeira
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <math.h>

int main() {
    int D, VF, VG;
    while (scanf("%d %d %d", &D, &VF, &VG) != EOF) {
        double tF = 12.0 / VF;
        double distanciaGuardia = sqrt(D * D + 12 * 12);
        double tG = distanciaGuardia / VG;
        if (tG <= tF) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
