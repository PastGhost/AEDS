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
}

stack new_stack() {
  stack s;
  return s;
}

int empty(stack s) {
  return 0;
}

int size(stack s) {
  return 0;
}

Type top(stack s) {
  Type k;
  return k;
}

void push(Type k, stack s) {
}

void pop(stack s) {
}

void copy(stack p, stack s) {
}

void swap(stack p, stack s) {
}

void delete_stack(stack s) {
}
