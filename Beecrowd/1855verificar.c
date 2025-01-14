#include <stdio.h>
 
int main() {
    int x, y, x1 = 0, y1 = 0;
    char c;
    int count = 0;
    scanf("%d %d", &x,&y);
    if(x<100 && y<100){
        int mat[x][y];
        int matc[x][y];
        for(int i = 0; i<x; i++){
            for(int k = 0; k< y; k++){
                mat[i][k] = 0;
                
            }
        }
        mat[0][0] = 1;
        while(x1>= 0 && x1< x && y1>= 0 && y1< y){
            scanf("%c", &c);
            if(c == EOF) break;
            else{
                if(c == '>'){
                    x1++;
                    mat[x1][y1] = 1;
                }
                else if(c == '<'){
                    x1--;
                    mat[x1][y1] = 2;
                }
                else if(c == '^'){
                    y1--;
                    mat[x1][y1] = 3;
                }
                else if(c == 'v'){
                    y1++;
                    mat[x1][y1] = 4;
                }
                else if(c == '.'){
                    if(mat[x1][y1] == 1){
                       x1++;
                       mat[x1][y1] = 1; 
                    }
                    else{
                       x1--;
                       mat[x1][y1] = 2; 
                    }
                }
                else if(c == '*'){
                    count ++;
                }
            }
        }
        if(x1< 0 && x1>= x && y1< 0 && y1>= y){
            printf("!\n");
        }
        else if(count == 1){
            printf("*\n")
        }
        else{
            printf("!\n");
        }
    }
        
    }
    else{
        printf("!\n");
    }
    
   
 
    return 0;
}
