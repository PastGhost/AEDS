#ifndef GREEDY_SOLUTION_H_
#define GREEDY_SOLUTION_H_
#include "street.h"

void calculate_distance(Pair street[], long size, long distance[]); 

void sort_pair_distance(Pair street[],long size, long distance[]);

int add_flag(Pair street[],int pair_flag[],long addition);

long create_solution(Pair street[],long size);

#endif