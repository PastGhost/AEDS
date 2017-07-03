#ifndef BRUTE_FORCE_SOLUTION_H_
#define BRUTE_FORCE_SOLUTION_H_

#include "street.h"

long flag_number(int pair_flag[], long size);

long recursive_enumerate(Pair street[],long size,long pos,int pair_flag[]);

long enumerate(Pair street[],long size);


#endif