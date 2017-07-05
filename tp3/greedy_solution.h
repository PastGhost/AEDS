#ifndef GREEDY_SOLUTION_H_
#define GREEDY_SOLUTION_H_
#include "street.h"

// Calcula qual a distancia de cada bar a casa do dono e salva no vertor distance
void calculate_distance(Pair street[], long size, long distance[]); 

// Heapsort ordena o vetor street e baseado nas distancias salvas em distance
void sort_pair_distance(Pair street[],long size, long distance[]);

// Adiciona a bandeira do par de bar/casa indicado por addition
// a solucao caso esta seja compativel com as bandeiras ja levantadas
// Retorna 1 caso uma bandeira foi adicionada 
int add_flag(Pair street[],int pair_flag[],long addition);

// Cria uma solucao a partir do vetor street ja ordenado a partir de uma caracteristica
long create_solution(Pair street[],long size);

#endif