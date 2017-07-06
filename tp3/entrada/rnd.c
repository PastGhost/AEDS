#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
	srand(time(NULL));
	long l = 200000000;
	long k = l/2;
	long m,i;
	long j = 0;
	// int *x = calloc(l,sizeof(int));
	// int *y = calloc(l,sizeof(int));
	// int x[200000000];
	int *x = malloc(l*sizeof(int));
	// int *y =(int*) malloc(l*sizeof(int));
	
	printf("d\n");
	printf("%ld\n",k);
	for(i = 0; i < k && j/l < 20;i++) {
		m = (rand() * rand() * rand() ) % l;
		// printf("%ld 1 ",m);
		j++;
		// printf("%ld 1.2 ",m);
		while(x[m] == 1 && j/l < 20 ){
			j++;
			m = (m + 1) % l;
			// printf("%ld %d %ld %ld |||||| ",j,x[m],m,i);
		}
		printf("%ld ",m);
		// printf("%ld 2.2 ",m);
		x[m] = 1;
		// printf("%ld 3 ",m);
		j++;
		m = (rand() * rand() * rand() ) % l;
		// printf("%ld 4 %d ",m,m < l);
		while(x[m] == 1 && j/l < 20) {
			j++;
			m = (m + 1) % l;
			// printf("%ld %d %ld %ld |||||||||||",j,x[m],m,i);
		}
		// printf("%ld 5.5",m);
		x[m] = 1;
		printf("%ld\n",m);

	}
	m = 0;
	j = 0;
	for(;i < k;i++) {
		m = j + 1;
		while(x[m] == 1 && m < l)
			m++;
		j = m + 1;
		while(x[j] == 1 && j < l)
			j++;
		printf("%ld %ld\n",m,j);
	}
	
	free(x);
	// free(y);
	// for(long i = 0; i < l;i++) {
		// printf("%ld %ld\n",i,l - i);

	// }


	return 0;
}