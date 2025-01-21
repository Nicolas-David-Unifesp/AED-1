#include <stdio.h>
#include <stdlib.h>

int main () {
    int hi, mi, hf, mf, i, countH = 0, countM = 0;

    scanf ("%d %d %d %d", &hi, &mi, &hf, &mf);

    do {
        countH++;

        if (hi != 24)
            hi++;
        else
            hi = 1;

        if (hf == 0 && hi == 24)
            break;
    }
    while (hi != hf);

    countM = mf - mi;

    if (countM < 0) {
        countH--;
        countM += 60;
    }

    if (countH == 24 && countM >= 1)
        countH = 0;

    printf ("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", countH, countM);

    return 0;
}