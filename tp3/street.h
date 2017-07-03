#ifndef STREET_H_
#define STREET_H_

typedef struct pair{
	unsigned long even;
	unsigned long uneven;
}Pair;

void read_street(Pair street[], unsigned long pair_number);

int is_compatible(Pair street[],unsigned long i, unsigned long j);

int verify_solution(Pair street[],unsigned long size, int pair_flag[]);

#endif
