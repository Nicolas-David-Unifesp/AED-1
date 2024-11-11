#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    if(a%2 == 0){
        int i =1;
         while(i < a){
            printf("%d\n", i);
            i+=2;
         }
    }
    else{
        int i =1;
        while(i != a){
            printf("%d\n", i);
            i+=2;
         }
          printf("%d\n", i);
    }
    return 0;
}
