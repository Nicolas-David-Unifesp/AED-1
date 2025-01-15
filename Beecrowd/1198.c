/*
  * nome: 1198.c
  * descrição:
  * data: 15/01/2025
  *Resolvido por Nicolas David da Cruz Santos
*/
#include <stdio.h>

int main(){
    long long x, y;

    while(scanf("%lld", &x) != EOF){
        scanf("%lld", &y);
        if(x > y)
            printf("%lld\n", x-y);
        else
            printf("%lld\n", y-x);
    }

    return 0;
}
