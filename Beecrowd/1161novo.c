#include <stdio.h>
#include <math.h>

int main(){
	
	long long int M, N, fat1, fat2; 
	int i;
	
	while(scanf("%lld %lld", &M, &N) != EOF){
	fat1 = 1;
	fat2 = 1;
		for(i=M; i>0; i--){
			fat1 *= M;
			M--;
		}
		for(i=N; i>0; i--){
			fat2 *= N;
			N--;
		}
	printf("%lld\n", fat1 + fat2);
	}
	
	return 0;
}
