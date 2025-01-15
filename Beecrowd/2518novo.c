/*
  * nome: 2518.c
  * descrição:
  * data: 15/01/2025
  *Resolvido por Nicolas David da Cruz Santos
*/
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	int h, c, l;
	double hip, area;
	while(scanf("%d",&n)!=EOF){
		scanf("%d%d%d",&h,&c,&l);
		hip = sqrt(pow(h,2)+pow(c,2));
		area = (l*hip*n)/10000.0;
		printf("%.4lf\n",area);
	}
	
	return 0;
}
