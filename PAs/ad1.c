#include <stdio.h>
#include <stdlib.h>

int main () {
	int* v;
	unsigned long s = 0,n,k,  l = 0;
	unsigned long i,j;
	scanf("%lu",&n);
	v = (int*) malloc(sizeof(int)*n);
	for(i = 0;i < n;i++) {
		scanf("%d",&v[i]);
		s += v[i];
		if(s % 8 == 0)
			l++;
		k = s;
		for(j = 0;j < i;j++){
			k -= v[j];
			if(k % 8 == 0)
				l++;
		}

	}
	// for(i = 0;i < n; i++){
	// 	s = 0;
	// 	for(j = i;j< n;j++) {
	// 		s += v[j];
	// 		if(s % 8 == 0)
	// 			l++;
	// 	}
	// }
	printf("%lu\n",l);
	free(v);
	return 0;
}