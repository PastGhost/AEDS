#include "greedy_solution.h"
#include <stdlib.h>

// Calcula qual a distancia de cada bar a casa do dono
void calculate_distance(Pair street[], long size, long distance[]) {
	
	for(long i = 0;i < size;i++) {
	
		distance[i] = labs(street[i].even - street[i].uneven);
	
	}
}

// Heapsort ordena o vetor street e baseado nas distancias salvas em distance
void heapify_distance(Pair street[], long size, long parent, long distance[]) {
	Pair aux_pair;
	
	long aux_dist;
    long largest = parent;  
    long left_child = 2*parent + 1;
    long right_child = 2*parent + 2;

    if (left_child < size && distance[left_child] > distance[largest])
        largest = left_child;
 
    if (right_child < size && distance[right_child] > distance[largest])
        largest = right_child;

    if (largest != parent) {

    	aux_dist = distance[largest];
        distance[largest] = distance[parent];
        distance[parent] = aux_dist;

        aux_pair = street[largest];
        street[largest] = street[parent];
        street[parent] = aux_pair;

        heapify_distance(street, size, largest,distance);
    }
}

void sort_pair_distance(Pair street[],long size, long distance[]) {
	Pair aux_pair;
	long aux_dist;
	long i;
    for (i = (size / 2) - 1; i >= 0; i--)
        heapify_distance(street, size, i,distance);

    for (i = size - 1; i >= 0; i--) {

    	aux_dist = distance[0];
        distance[0] = distance[i];
        distance[i] = aux_dist;

        aux_pair = street[0];
        street[0] = street[i];
        street[i] = aux_pair;
 
        heapify_distance(street, i, 0,distance);
    }
}

// Adiciona a bandeira do par de bar/casa indicado por addition
// a solucao caso esta seja compativel com as bandeiras ja levantadas
// Retorna 1 caso uma bandeira foi adicionada 
int add_flag(Pair street[],int pair_flag[],long addition) {
	
	for(long i = addition - 1; i >= 0;i--) {
	
		if(pair_flag[i] > 0 && !(is_compatible(street,i,addition) ) )
			return 0;
	
	}
	
	pair_flag[addition] = 1;
	
	return 1;
}

// Cria uma solucao a partir do vetor street ja ordenado a partir de uma caracteristica
long create_solution(Pair street[],long size) {
	
	long max_flags = 1;
	
	int *pair_flag = calloc(size,sizeof(int));
	pair_flag[0] = 1;
	
	// Como o vetor street ja esta ordenado, cria a solucao pegando os pares mais provaveis de pertencer a ela baseada na caracterisca definida
	for(long i = 1; i < size; i++) {
	
		max_flags += add_flag(street,pair_flag,i);
	
	}
	
	free(pair_flag);
	return max_flags;
}