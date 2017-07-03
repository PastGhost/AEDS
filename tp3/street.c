#include "street.h"
#include <stdio.h>

int is_compatible(Pair street[],long i, long j) {
	if(( (street[i].even - street[j].even) * ( street[i].uneven - street[j].uneven ) ) >= 0)
		return 1;
	return 0;
}

int verify_solution(Pair street[],long size, int pair_flag[]) {
	
	for(long i = 0;i < size; i++) {
		
		if(pair_flag[i] == 1) {
			
			for(long j = 0;j < size; j++) {
			
				if(pair_flag[j] == 1) { 
			
					if(!(is_compatible(street,i,j)))
						return 0;
			
				}
			}
		}
	}

	return 1;
}

void read_street(Pair street[], long pair_number) {
	long i,cx,cy;
	for(i = 0; i < pair_number; i++) {
		scanf("%lu %lu",&cx,&cy);
		if((cx % 2) == 0 ) {
			street[i].even = cx;
			street[i].uneven = cy;
		}
		else {
			street[i].even = cy;
			street[i].uneven = cx;
		}
	}
}