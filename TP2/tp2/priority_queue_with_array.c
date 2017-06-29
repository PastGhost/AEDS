// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue.h"
#include "solucao.h"
#include <stdlib.h>
#include <stdio.h>

typedef Type Type;
typedef struct typearray {
  int flag;
  Type Key;
} Typearray;

// Os elementos da fila estão distribuídos do maior para o menor no vetor,
// ou seja, o maior elemento está necessariamente no índice 0 do vetor.
struct priority_queue_t{
  Typearray* array;  // Vetor que contém os elementos da fila.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na fila.
};

void satisfyheap(priority_queue q, int i) {
  int l, r, smallest;
  Typearray temp;
  l = 2*i;
  r = 2*i + 1;

  if(l < q->size && compare_key(q->array[l].Key,q->array[i].Key) < 0 )
   smallest = l;
  else
    smallest = i;
 
  if(r < q->size && compare_key(q->array[r].Key,q->array[smallest].Key) < 0)
    smallest = r; 
  
  
  if(smallest != i) {
    temp = q->array[i];
    q->array[i] = q->array[smallest];
    q->array[smallest] = temp;
    satisfyheap(q, smallest);
    
  }
}

void buildheap(priority_queue q) {
  int i;
  for( i= (int) ((q->size -1)/2); i >= 0; i--) {
    satisfyheap(q, i);
  } 
}

void satisfyheap_flag(priority_queue q, int i) {
  int l, r, smallest;
  Typearray temp;
  l = 2*i;
  r = 2*i + 1;
  if(l >= q->size )
    smallest = i;
  else if(q->array[l].flag == q->array[i].flag) {
    if(compare_key(q->array[l].Key,q->array[i].Key) < 0 )
      smallest = l;
    else
      smallest = i;
  }
  else if(q->array[l].flag > q->array[i].flag)
    smallest = i;
  else
    smallest = l;

  if( r < q->size) {
    if(q->array[smallest].flag == q->array[r].flag) {
      if(compare_key(q->array[r].Key,q->array[smallest].Key) < 0)
        smallest = r; 
    }
    else if(q->array[smallest].flag > q->array[r].flag )
      smallest = r;
  }
  
  if(smallest != i) {
    temp = q->array[i];
    q->array[i] = q->array[smallest];
    q->array[smallest] = temp;
    satisfyheap_flag(q, smallest);
    
  }
}

void buildheap_flag(priority_queue q) {
  int i;
  for( i= (int) ((q->size -1)/2); i >= 0; i--) {
    satisfyheap_flag(q, i);
  } 
}

priority_queue new_priority_queue(int size_queue) {
  priority_queue q = malloc(sizeof(struct priority_queue_t));
  q->size = 0;
  q->array = malloc(sizeof(Typearray)*size_queue);
  q->capacity = size_queue;
  return q;
}

bool empty(priority_queue q) {
  return q->size==0;
}

int size(priority_queue q) {
  return q->size;
}

Type top(priority_queue q) {
  return q->array[0].Key;
}

void push_flag(Type k, priority_queue q, int flag) {
	q->array[q->size].Key = k;
  q->array[q->size].flag = flag;
	q->size++;
	buildheap_flag(q);
}

void push(Type k, priority_queue q, int flag) {
  q->array[q->size].Key = k;
  q->array[q->size].flag = flag;
  q->size++;
  buildheap(q);
}

void fill(Type k, priority_queue q, int flag) {
  q->array[q->size].Key = k;
  q->array[q->size].flag = flag;
  q->size++;
}

void sort_queue(priority_queue q) {
  buildheap(q);
}

void sort_queue_flag(priority_queue q) {
  buildheap_flag(q);
}

void pop_flag(priority_queue q) {
	q->array[0] = q->array[q->size - 1];
	q->size--;
	satisfyheap_flag(q,0);
}

void pop(priority_queue q) {
  q->array[0] = q->array[q->size - 1];
  q->size--;
  satisfyheap(q,0);
}

int top_flag(priority_queue q) {
  return q->array[0].flag;
}

void switch_top_flag(Type k, priority_queue q,int flag) {
  q->array[0].Key = k;
  q->array[0].flag = flag;
  satisfyheap_flag(q,0);
}

void switch_top(Type k, priority_queue q,int flag) {
  q->array[0].Key = k;
  q->array[0].flag = flag;
  satisfyheap(q,0);
}

void delete_priority_queue(priority_queue q) {
	free(q->array);
	free(q);
}
