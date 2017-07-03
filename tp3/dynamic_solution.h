#ifndef DYNAMIC_SOLUTION_H_
#define DYNAMIC_SOLUTION_H_

#include "street.h"

void heapify(Pair street[], long size, long parent);

void sort_pair(Pair street[], long size);

long find_ceil(long *sequence,long key,long low,long high);

long LIS(Pair street[],long size);

#endif