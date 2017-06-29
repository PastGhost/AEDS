#include <stdio.h>
#include <stdlib.h>
#include "brute_force_solution.h"

unsigned long flag_number(int pair_flag[], unsigned long size) {
	unsigned long quantity = 0;
	for(unsigned long i = 0;i < size;i++)
		if(pair_flag[i] != 0)
			quantity++;
	return quantity;
}

unsigned long recursive_enumerate(Pair street[],unsigned long size,unsigned long pos,int pair_flag[]) {
	if(pos == size) {
		if(verify_solution(street,size,pair_flag)) {
			return flag_number(pair_flag,size);
		}
		else
			return -1;
	}

	pair_flag[pos] = 1;
	unsigned long flag_added = recursive_enumerate(street,size,pos+1,pair_flag);
	pair_flag[pos] = 0;
	unsigned long flag_not_added = recursive_enumerate(street,size,pos+1,pair_flag);
	if(flag_added > flag_not_added)
		return flag_added;
	return flag_not_added;
}

unsigned long enumerate(Pair street[],unsigned long size) {
	int *pair_flag = calloc(size,sizeof(int));
	
	unsigned long max_flag = recursive_enumerate(street,size,0,pair_flag);
	free(pair_flag);
	return max_flag;

}