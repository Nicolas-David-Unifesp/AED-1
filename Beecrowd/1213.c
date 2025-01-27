#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int resto = 1 % n;
        int length = 1;
        
        while (resto != 0) {
            resto = (resto * 10 + 1) % n;
            length++;
        }
        
        printf("%d\n", length);
    }

    return 0;
}
