#include "solucao.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main() {
	int doc,mem;
	char out[255],in[255];
	scanf("%d %d %s %s",&doc,&mem,in,out);
	inverted_index(in,out,doc,mem);
	return 0;
}

int omain() {
	clock_t start, end;
 	double cpu_time_used,sum;
	char dir[3][20];
	char str[3][30];
	int l;
	strcpy(str[0],"Fixo\0");
	strcpy(str[1],"Rand\0");
	strcpy(str[2],"Memoria\0");
	strcpy(dir[1],"./big1/\0");
	strcpy(dir[2],"./big2/\0");
	printf("%s\n",str[2]);
	for(int j = 1; j < 11; j++) {
		sum = 0;
		for(l = 0;l < 20;l++) {
			int p = pow(3,j);
			start = clock();
			inverted_index(dir[1],dir[1],10,32*p);
			end = clock();
			sum += 	(double) (end - start);
		}
		sum = sum/l;
		cpu_time_used = (sum) / CLOCKS_PER_SEC;
		printf("%d %lf\n",j,cpu_time_used);
		strcpy(dir[1],"./big1/\0");
		strcpy(dir[2],"./big2/\0");
	}
	return 0;
	for(int i = 1; i < 2; i ++) {
		printf("%s\n",str[i - 1]);
		for(int j = 1; j < 11; j++) {
			sum = 0;
			for(l = 0;l < 10;l++) {
				start = clock();
				inverted_index(dir[i],dir[i],j,32*50);
				end = clock();
				sum += 	(double) (end - start);
			}
			sum = sum/l;
			cpu_time_used = (sum) / CLOCKS_PER_SEC;
			printf("%d %lf\n",j,cpu_time_used);
			strcpy(dir[1],"./big1/\0");
			strcpy(dir[2],"./big2/\0");
		}
	}
	return 0;
}