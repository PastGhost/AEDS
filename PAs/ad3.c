#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int n,a,k;
	int c,b;
	int m[1001][1001],l[1001];
	int flag = 0;
	int i,j,p;
	while(scanf("%d %d %d",&n,&a,&k) > 0){
		getchar();
		memset(m,0,sizeof(int)*1001*1001);
		memset(l,0,sizeof(int)*1001 );
		for(i = 0;i < a;i++) {
			scanf("%d %d",&c,&b);
			getchar();
			m[c][b]++;
			m[b][c]++;
			l[c]++;
			l[b]++;
		}
		flag = 1;
		while(flag != -1) {
			flag = -1;
			for(i = 1; i <= n;i++)
				if(k > l[i] && l[i] != 0){
					for(j = 1;j < n; j++) {
						if(m[i][j] != 0){
							l[j]--;
							m[i][j] = 0;
							m[j][i] = 0;
						}
						l[i] = 0;
					}
					flag++;
				}

		}
		p = 0;

		for(i = 1; i <= n;i++) {
			if(l[i] >= k){
				p++;
				printf("%d ",i);
			}
		}





		// for(i = 1;p == 0 && i <= n;i++) {
		// 	if(l[i] >= k){
		// 		p++;
		// 		printf("%d",i);
		// 	}

		// }
		// for(; i <= n;i++) {
		// 	if(l[i] >= k){
		// 		p++;
		// 		printf(" %d",i);
		// 	}
		// }
		if( p == 0)
			printf("0");
		printf("\n");
	}
}