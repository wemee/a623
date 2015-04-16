#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void) {
	int n, m, a, b, *ary, i, j, result;
	while(scanf("%d%d", &n, &m)!=EOF){
		a = m;
		b = n-m;
		if(a<b) swap(&a, &b);
		
		ary = malloc((n-a)*sizeof(int));
		
		for(i=n, j=0; i>a; i--, j++)
			ary[j] = i;
		
		for(i=b; i>1; i--)
			for(j=0; j<(n-a); j++)
				if(ary[j]%i == 0){
					ary[j]/=i;
					break;
				}
		
		result = 1;
		for(i=0; i<(n-a); i++)
			result *= ary[i];
		
		printf("%d\n", result);
		
		free(ary);
	}
	return 0;
}
