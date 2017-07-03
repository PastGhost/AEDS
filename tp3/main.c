#include <stdio.h>
#include <stdlib.h>
#include "street.h"
#include "dynamic_solution.h"
#include "brute_force_solution.h"
#include "greedy_solution.h"

int main() {
	unsigned long pair_number, max_flags;
	char solution_type;
	Pair *street;
	
	scanf("%c",&solution_type);
	scanf("%lu",&pair_number);
	
	street = malloc(sizeof(Pair)*pair_number);
	read_street(street,pair_number);

	switch(solution_type) {
		case'd':
			sort_pair(street,pair_number);
			max_flags = LIS(street,pair_number);
			printf("%lu\n",max_flags );
			break;
		case'b':
			max_flags = enumerate(street,pair_number);
			printf("%lu\n",max_flags );
			break;
		case'g':
		default:
			break;

	}
}