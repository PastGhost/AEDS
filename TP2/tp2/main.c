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
