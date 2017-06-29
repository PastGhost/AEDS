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
    Type* aux = (Type*) malloc(sizeof(Type) * s->capacity);
    for (int i = 0; i < s->size; i++) {
      aux[i] = s->array[i];
    }
    free(s->array);
    s->array = aux;
  }
}

stack new_stack() {
  stack s = malloc(sizeof(struct stack_t));
  s->size = 0;
  s->capacity = 16;
  s->array = malloc(sizeof(Type) * s->capacity);
  return s;
}

bool empty(stack s) {
  return s->size == 0;
}

int size(stack s) {
  return s->size;
}

Type top(stack s) {
  return s->array[s->size - 1];
}

void push(Type k, stack s) {
  if (s->size == s->capacity) {
    reserve(2 * s->capacity, s);
  }
  s->array[s->size] = k;
  s->size++;
}

void pop(stack s) {
  s->size--;
}

void copy(stack p, stack s) {
  reserve(p->capacity, s);
  s->size = p->size;
  for (int i = 0; i < p->size; i++) {
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
