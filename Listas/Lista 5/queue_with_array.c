// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "queue.h"

#include <stdlib.h>

// Os elementos da fila estão distribuídos sequencialmento no vetor.
// O primeiro elemento não está necessariamente no índice 0.
// O índice do primeiro elemento é indicando pelo campo 'first'.
// O índice do último elemento é '(first + size - 1) % capacity.
struct queue_t{
  Type* array;  // Vetor que contém os elementos da fila.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na fila.
  int first;  // Índice do primeiro elemento na fila
};

void reserve(int m, queue q) {
  if (m > q->capacity) {
    q->capacity = m;
    Type* aux = malloc(sizeof(struct queue_t) * q->capacity);
    for (int i = 0; i < q->size; i++) {
      aux[i] = q->array[i];
    }
    free(q->array);
    q->array = aux;
  }
}

queue new_queue() {
  queue q = malloc(sizeof(struct queue_t));
  q->first = q->size = 0;
  q->capacity = 16;
  q->array = malloc(sizeof(struct queue_t) * q->capacity);
  return q;
}

int empty(queue q) {
  return q->size == 0;
}

int size(queue q) {
  return q->size;
}

Type front(queue q) {
  return q->array[q->first];
}

Type back(queue q) {
  return q->array[(q->first + q->size - 1) % q->capacity];
}

void push(Type k, queue q) {
  if (q->size == q->capacity) {
    reserve(2 * q->capacity, q);
  }
  q->array[(q->first + q->size) % q->capacity] = k;
  q->size++;
}

void pop(queue q) {
  q->first = (q->first + 1) % q->capacity;
  q->size--;
}

void copy(queue q, queue p) {
  reserve(q->capacity, p);
  p->size = q->size;
  p->first = 0;
  for (int i = 0; i < q->size; i++) {
    p->array[i] = q->array[(i + q->first) % q->capacity];
  }
}

void swap(queue q, queue p) {
  struct queue_t aux = *p;
  *p = *q;
  *q = aux;
}

void delete_queue(queue q) {
  free(q->array);
  free(q);
}
