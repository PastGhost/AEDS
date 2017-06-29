// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue.h"

#include <stdlib.h>

// Os elementos da fila estão distribuídos do maior para o menor no vetor,
// ou seja, o maior elemento está necessariamente no índice 0 do vetor.
struct priority_queue_t{
  Type* array;  // Vetor que contém os elementos da fila.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na fila.
};

void reserve(int m, priority_queue q) {
	Type* array = malloc(sizeof(Type)*m );
	for(int i = 0; i < q->size; i++) {
		array[i] = q->array[i];
	}
	free(q->array);
	q->array = array;
}


void satisfyheap(Type a[], int i, int heapsize) {
  int l, r, largest;
  Type temp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] < a[i])
    largest = l;
  
  else
    largest = i;
  
  if( r <= heapsize && a[r] < a[largest])
    largest = r;
  
  if(largest != i) {
    temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    satisfyheap(a, largest, heapsize);
    
  }
}

void buildheap(Type a[], int n) {
  int i, heapsize;
  heapsize = n - 1;
  for( i= (int) (n/2); i >= 0; i--) {
    satisfyheap(a, i, heapsize);
  } 
}

priority_queue new_priority_queue() {
  priority_queue q = malloc(sizeof(struct priority_queue_t));
  q->size = 0;
  q->array = malloc(sizeof(Type)*16);
  q->capacity = 16;
  return q;
}

bool empty(priority_queue q) {
  return q->size==0;
}

int size(priority_queue q) {
  return q->size;
}

Type top(priority_queue q) {
  return q->array[0];
}

void push(Type k, priority_queue q) {
	if(q->size == q->capacity) {
		reserve(q->capacity*2,q);
	}
	q->array[q->size] = k;
	q->size++;
	buildheap(q->array,q->size);
}

void pop(priority_queue q) {
	q->array[0] = q->array[q->size - 1];
	q->size--;
	buildheap(q->array,q->size);
}

void copy(priority_queue q, priority_queue p) {
	if(q->size > q->capacity) {
		reserve(q->capacity,p);
	}
	for(int i = 0; i < q->size; i++) {
		p->array[i] = q->array[i];
	}
	p->size = q->size;
}

void swap(priority_queue q, priority_queue p) {
	struct priority_queue_t aux = *q;
	*q = *p;
	*p = aux;
}

void delete_priority_queue(priority_queue q) {
	free(q->array);
	free(q);
}
