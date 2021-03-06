#include <stdio.h>
#include <stdlib.h>
#include "dynamic_solution.h"

// Heapsort ordenando o vertor street pelo lado par
void heapify(Pair street[], long size, long parent) {
	Pair aux;
    long largest = parent;  
    long left_child = 2*parent + 1;
    long right_child = 2*parent + 2;

    if (left_child < size && street[left_child].even > street[largest].even)
        largest = left_child;
 
    if (right_child < size && street[right_child].even > street[largest].even)
        largest = right_child;

    if (largest != parent) {

        aux = street[largest];
        street[largest] = street[parent];
        street[parent] = aux;

        heapify(street, size, largest);
    }
}

void sort_pair(Pair street[], long size) {
	Pair aux;
	long i;
    for (i = (size / 2) - 1; i >= 0; i--)
        heapify(street, size, i);

    for (i = size - 1; i >= 0; i--) {

        aux = street[0];
        street[0] = street[i];
        street[i] = aux;
 
        heapify(street, i, 0);
    }
}

// Achar o valor no vetor sequencia que e imediatamente maior ao valor indicado por key
// Realizando uma bysca binaria
long find_ceil(long *sequence,long key,long low,long high) {
    
    while (high - low  > 1) {
    
    	int mid = low + (high - low)/2;
  	
    	if (sequence[mid] >= key)
        	high = mid;
    
    	else
        	low = mid;
    }
 
    return high;
}

// Encontra o tamanho da maior sequencia crescente de numeros do lado impar do vetor street
// Street deve estar ordenado pelo seu lado par
long LIS(Pair street[],long size) {

    // Vetor sequence e usado para armazenar as sequencias, guardando, porem, somente seu valor mais alto
    long *sequence = (long*) malloc(sizeof(long)*size);
    sequence[0] = street[0].uneven;
    long length = 1;

    
    // Quando um valor menor que o de todas sequencias e descoberto, este e colocado na posicao 0
    // Quando um valor maior que o de todas sequencias e descoberto, este e colocado na posicao indicada por length
    // e o tamanho da maior sequencia
    // Caso o valor descoberto esteja entre o maior e o menor, a sequencia que tem o maior valor imediatamente maior ao descoberto
    // tem o primeiro substuido pelo valor descoberto
	for(long i = 1; i < size; i++) {
		
        if(street[i].uneven < sequence[0] )
        	sequence[0] = street[i].uneven;
		
        else if(street[i].uneven > sequence[length -1]  ){
		
        	sequence[length] = street[i].uneven;
			length++;
		
        }
		
        else
			sequence[find_ceil(sequence,street[i].uneven,0,length -1)] = street[i].uneven;

	}

	free(sequence);
	return length;
}