#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
	srand(time(NULL));
	long l = 100000000;
	// long m;
	// int *x = calloc(l,sizeof(int));
	// int *y = calloc(l,sizeof(int));

	// for(long i = 0; i < l/10;i++) {
	// 	m = rand() % l + 1;
	// 	while(x[m] == 1 )
	// 		m = rand() % l;
	// 	x[m] = 1;
	// 	printf("%ld ",m);
	// 	m = rand() % l + 1;
	// 	while(y[m] == 1 )
	// 		m = rand() % l;
	// 	y[m] = 1;
	// 	printf("%ld\n",m);

	// }
	printf("d\n");
	printf("%ld\n",l);
	for(long i = 0; i < l;i++) {
		printf("%ld %ld\n",i,l - i);

	}


	return 0;
}