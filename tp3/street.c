#include "street.h"
#include <stdio.h>

// Verifica se duas bandeiras indicadas por i e j podem ser levantadas juntas
// Se possivel retorna 1
int is_compatible(Pair street[],long i, long j) {
	// Duas bandeiras sao compativeis caso elas nao se cruzem, ou seja, 
	// Se a coordenada par de i for maior que a de j, o mesmo deve ocorrer com a coordenada impar
	// Se a coordenada par de i for menor que a de j, o mesmo deve ocorrer com a coordenada impar
	if(( (street[i].even - street[j].even) * ( street[i].uneven - street[j].uneven ) ) >= 0)
	
		return 1;
	
	return 0;
}

// Verifica se o conjuto solucao indicado por pair_flag e valido
// Um conjunto solucao e valido se todas a bandeiras levantadas sao compativeis entre si
int verify_solution(Pair street[],long size, int pair_flag[]) {
	
	for(long i = 0;i < size; i++) {
		
		if(pair_flag[i] == 1) {
			
			for(long j = 0;j < size; j++) {
			
				if(pair_flag[j] == 1) { 
			
					if(!(is_compatible(street,i,j)))
						return 0;
			
				}
			}
		}
	}

	return 1;
}

// Funcao de leitura, le os pares de bar/casa, separando-os pelo lado da rua
void read_street(Pair street[], long pair_number) {
	
	long i,cx,cy;
	
	for(i = 0; i < pair_number; i++) {
	
		scanf("%lu %lu",&cx,&cy);
	
		if((cx % 2) == 0 ) {
	
			street[i].even = cx;
			street[i].uneven = cy;
	
		}
	
		else {
	
			street[i].even = cy;
			street[i].uneven = cx;
	
		}
	}
}