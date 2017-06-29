#include "street.h"

int is_compatible(Pair street[],unsigned long i, unsigned long j) {
	if(  ( (signed) (street[i].even - street[j].even) * ( (signed) (street[i].uneven - street[j].uneven) ) ) >= 0)
		return 1;
	return 0;
}

int verify_solution(Pair street[],unsigned long size, int pair_flag[]) {
	
	for(unsigned long i = 0;i < size; i++) {
		
		if(pair_flag[i] == 1) {
			
			for(unsigned long j = 0;j < size; j++) {
			
				if(pair_flag[j] == 1) { 
			
					if(!(is_compatible(street,i,j)))
						return 0;
			
				}
			}
		}
	}

	return 1;
}