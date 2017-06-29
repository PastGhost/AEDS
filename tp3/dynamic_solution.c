#include <stdio.h>
#include <stdlib.h>
#include "dynamic_solution.h"


void heapify(Pair street[], unsigned long size, unsigned long parent) {
	Pair aux;
    unsigned long largest = parent;  
    unsigned long left_child = 2*parent + 1;
    unsigned long right_child = 2*parent + 2;

    if (left_child < size && street[left_child].even > street[largest].even)
        largest = left_child;
 
    if (right_child < size && street[right_child].even > street[largest].even)
        largest = right_child;

    if (largest != parent) {

        aux = street[0];
        street[0] = street[parent];
        street[parent] = aux;

        heapify(street, size, largest);
    }
}

void sort_pair(Pair street[], unsigned long size) {
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

unsigned long find_ceil(unsigned long *sequence,unsigned long key,unsigned long low,unsigned long high) {
	while(high >= low){
		unsigned long mid = (low + high)/2;
		if(sequence[mid] >= key)
			high = mid -1;
		else
			low = mid + 1;

	}
	return high;
}

unsigned long LIS(Pair street[],unsigned long size) {

	unsigned long *sequence = (unsigned long*) malloc(sizeof(unsigned long)*size);
	sequence[0] = street[0].uneven;
	unsigned long length = 1;
	
	for(unsigned long i = 1; i < size; i++) {
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