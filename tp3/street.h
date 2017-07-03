#ifndef STREET_H_
#define STREET_H_

typedef struct pair{
	long even;
	long uneven;
}Pair;

void read_street(Pair street[], long pair_number);

int is_compatible(Pair street[],long i, long j);

int verify_solution(Pair street[],long size, int pair_flag[]);

#endif
