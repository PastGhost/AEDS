#ifndef BRUTE_FORCE_SOLUTION_H_
#define BRUTE_FORCE_SOLUTION_H_

#include "street.h"

unsigned long flag_number(int pair_flag[], unsigned long size);

unsigned long recursive_enumerate(Pair street[],unsigned long size,unsigned long pos,int pair_flag[]);

unsigned long enumerate(Pair street[],unsigned long size);


#endif