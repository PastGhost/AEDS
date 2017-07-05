#ifndef STREET_H_
#define STREET_H_

typedef struct pair{
	long even;
	long uneven;
}Pair;

// Verifica se duas bandeiras indicadas por i e j podem ser levantadas juntas
// Se possivel retorna 1
int is_compatible(Pair street[],long i, long j);

// Verifica se o conjuto solucao indicado por pair_flag e valido
// Um conjunto solucao e valido se todas a bandeiras levantadas sao compativeis entre si
int verify_solution(Pair street[],long size, int pair_flag[]);

// Funcao de leitura, le os pares de bar/casa, separando-os pelo lado da rua
void read_street(Pair street[], long pair_number);

#endif
