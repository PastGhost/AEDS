// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "queue.h"

#include <stdlib.h>

// Define como os elementos da fila serão organizados na memória.
struct Node {
  Type key;
  struct Node* prev;
  struct Node* next;
};

struct queue_t{
  struct Node* end;  // Ponteiro para o sentinela.
  int size;  // Número de elementos na fila.
};

queue new_queue() {
  queue q = malloc(sizeof(struct queue_t));
  q->size = 0;
  q->end = malloc(sizeof(struct Node));
  q->end->prev = q->end;
  q->end->next = q->end;
  return q;
}

int empty(queue q) {
  return q->size == 0;
}

int size(queue q) {
  return q->size;
}

Type front(queue q) {
  return q->end->next->key;
}

Type back(queue q) {
  return q->end->prev->key;
}

void push(Type k, queue q) {
  struct Node* last = q->end->prev;
  struct Node* ins = malloc(sizeof(struct Node));
  ins->key = k;
  ins->next = q->end;
  ins->prev = last;
  last->next = ins;
  q->end->prev = ins;
  q->size++;
}

void pop(queue q) {
  struct Node* popped = q->end->next;
  popped->prev->next = popped->next;
  popped->next->prev = popped->prev;
  free(popped);
  q->size--;
}

void copy(queue q, queue p) {
  while (!empty(q)) {
    pop(q);
  }
  for (struct Node* i = p->end->next; i != p->end; i = i->next) {
    push(i->key, q);
  }
}

void swap(queue q, queue p) {
  struct queue_t aux = *q;
  *q = *p;
  *p = aux;

}

void delete_queue(queue q) {
  while (!empty(q)) {
    pop(q);
  }
  free(q->end);
  free(q);
}

