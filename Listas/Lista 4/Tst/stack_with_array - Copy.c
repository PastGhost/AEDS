// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "stack.h"

#include <stdlib.h>

// Os elementos da pilha estão distribuídos sequencialmento no vetor.
// O primeiro elemento está no índice 0.
// O topo da pilha está no índice 'size - 1'.
struct stack_t{
  Type* array;  // Vetor que contém os elementos da pilha.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na pilha.
};

void reserve(int m, stack s) {
  if (m > s->capacity) {
    s->capacity = m;
    Type* aux = malloc(sizeof(struct stack_t) * s->capacity);
    for (int i = 0; i < s->size; i++) {
      aux[i] = s->array[i];
    }
    free(s->array);
    s->array = aux;
  }
}

stack new_stack() {
  stack s = malloc(sizeof(struct stack_t) ) ;
  s->size = 0;
  s->capacity = 16;
  s->array = malloc(sizeof(struct stack_t ) * s->capacity );

  return s;
}

int empty(stack s) {
  return s->size == 0;
}

int size(stack s) {
  return s->size;
}

Type top(stack s) {
  return  s->array[0];
}

void push(Type k, stack s) {
  if(s->size == s->capacity) {
    reserve(s->capacity * 2, s);
  }
  s->array[s->size] = k;
  s->size++;
}

void pop(stack s) {
  int i;
  for(i=0 ;i < s->size -1; i++ ) {
    s->array[i] = s->array[i+1];
  }
  s->size--;
}
// s = p
void copy(stack p, stack s) {
  if(s->capacity < p->size) {
    reserve(p->capacity,s);
  }
  s->size = p->size;
  for(int i = 0; i< s->size; i++ ) {
    s->array[i] = p->array[i];
  }
}

void swap(stack p, stack s) {
  struct stack_t aux = *s;
  *s = *p;
  *p = aux;

}

void delete_stack(stack s) {
  free(s->array);
  free(s);
}
