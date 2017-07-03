#ifndef DYNAMIC_SOLUTION_H_
#define DYNAMIC_SOLUTION_H_

#include "street.h"

void heapify(Pair street[], unsigned long size, unsigned long parent);

void sort_pair(Pair street[], unsigned long size);

unsigned long find_ceil(unsigned long *sequence,unsigned long key,unsigned long low,unsigned long high);

unsigned long LIS(Pair street[],unsigned long size);

#endif