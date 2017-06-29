// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "set.h"

#include <stdlib.h>

// Os elementos do conjunto estão distribuídos sequencialmente num vetor.
// O primeiro elemento está no índice 0.
struct set_t {
  Type* array;  // Vetor que contém os elementos do conjunto.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos no conjunto.
};

void reserve(int m, set s) {
  if (m > s->capacity) {
    s->capacity = m;
    Type* aux = malloc(m * sizeof(Type));
    for (int i = 0; i < s->size; i++) {
      aux[i] = s->array[i];
    }
    free(s->array);
    s->array = aux;
  }
}

set new_set() {
  set s = malloc(sizeof(struct set_t));
  s->size = 0;
  s->capacity = 16;
  s->array = malloc(s->capacity * sizeof(Type));
  return s;
}

bool empty(set s) {
  return s->size == 0;
}

int size(set s) {
  return s->size;
}

Type element(set s) {
  return s->array[s->size - 1];
}

bool find(Type k, set s) {
  for (int i = 0; i < s->size; i++) {
    if (s->array[i] == k) {
      return true;
    }
  }
  return false;
}

void insert(Type k, set s) {
  if (!find(k, s)) {
    if (s->size == s->capacity) {
      reserve(2 * s->capacity, s);
    }
    s->array[s->size] = k;
    s->size++;
  }
}

void erase(Type k, set s) {
  for (int i = 0; i < s->size; i++) {
    if (s->array[i] == k) {
      // Sobreescreve k com o valor do último elemento.
      s->array[i] = s->array[s->size - 1];
      s->size--;
    }
  }
}

void clear(set s) {
  s->size = 0;
}

void copy(set s, set q) {
  reserve(s->size, q);
  q->size = s->size;
  for (int i = 0; i < s->size; i++) {
    q->array[i] = s->array[i];
  }
}

void delete_set(set s) {
  free(s->array);
  free(s);
}
