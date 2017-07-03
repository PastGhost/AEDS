#include <stdio.h>
#include <stdlib.h>
#include "brute_force_solution.h"

long jo;

long flag_number(int pair_flag[], long size) {
	long quantity = 0;
	for(long i = 0;i < size;i++)
		if(pair_flag[i] != 0)
			quantity++;
	return quantity;
}

long recursive_enumerate(Pair street[],long size,long pos,int pair_flag[]) {
	jo++;
	printf("%lu\n",jo );
	if(pos == size) {
		if(verify_solution(street,size,pair_flag)) {
			return flag_number(pair_flag,size);
		}
		else
			return 0;
	}

	pair_flag[pos] = 1;
	long flag_added = recursive_enumerate(street,size,pos+1,pair_flag);
	pair_flag[pos] = 0;
	long flag_not_added = recursive_enumerate(street,size,pos+1,pair_flag);
	if(flag_added > flag_not_added)
		return flag_added;
	return flag_not_added;
}

long enumerate(Pair street[],long size) {
	int *pair_flag = calloc(size,sizeof(int));
	jo = 0;
	long max_flag = recursive_enumerate(street,size,0,pair_flag);
	free(pair_flag);
	return max_flag;

}