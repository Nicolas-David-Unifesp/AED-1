/*
  * nome: 1029.c
  * descrição:
  * data: 15/01/2025
  *Resolvido por Nicolas David da Cruz Santos
*/
#include <stdio.h>

int calls=-1;

int fib(int n)
{
	calls++;  // Incrementa o contador
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1)+fib(n-2);  // Chamada calculo Fibonacci
}

int main()
{
	int e, n, fi;
	scanf("%d",&e); 
	while(e--)
	{
		scanf("%d",&n);  
		fi = fib(n);  
		printf("fib(%d) = %d calls = %d\n",n,calls,fi);  
		calls=-1;  // Reseta o contador
	}
	
	return 0;
}
