#include <stdio.h>
#include <stdlib.h>
#include "brute_force_solution.h"

// Retorna a quantidade de bandeira que pertencem a solucao
// Solucao ja deve ser valida
long flag_number(int pair_flag[], long size) {
	long quantity = 0;
	for(long i = 0;i < size;i++)
		if(pair_flag[i] != 0)
			quantity++;
	return quantity;
}

// Percorre toda
long recursive_enumerate(Pair street[],long size,long pos,int pair_flag[]) {

	//Caso base: final do vetor de bares
	// Verifica se a solucao e valida e retorna a quantidade de bandeiras caso seja
	if(pos == size) {
		if(verify_solution(street,size,pair_flag)) {
			return flag_number(pair_flag,size);
		}
		else
			return 0;
	}

	// Bifuracacao para colocando a bandeira e nao colocando
	// Salva o valor e retorna o maior dos dois
	pair_flag[pos] = 1;
	long flag_added = recursive_enumerate(street,size,pos+1,pair_flag);
	
	pair_flag[pos] = 0;
	long flag_not_added = recursive_enumerate(street,size,pos+1,pair_flag);
	
	if(flag_added > flag_not_added)
		return flag_added;
	
	return flag_not_added;
}

long enumerate(Pair street[],long size) {

	// pair_flag sinaliza se a bandeira de um par de bar/casa esta com a bandeira levantada
	// 1 para levantada, 0 caso contrario
	int *pair_flag = calloc(size,sizeof(int));
	
	long max_flag = recursive_enumerate(street,size,0,pair_flag);
	
	free(pair_flag);
	return max_flag;

}