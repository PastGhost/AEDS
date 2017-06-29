// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue.h"

#include <stdlib.h>

// Define como os elementos da fila serão organizados na memória.
// Os elementos estão ordanados do menor para o maior na lista encadeada.
struct Node {
  Type key;
  struct Node* prev;
  struct Node* next;
};

struct priority_queue_t{
  struct Node* end;  // Ponteiro para o sentinela.
  int size;  // Número de elementos na fila.
};

priority_queue new_priority_queue() {
  priority_queue q = malloc(sizeof(struct priority_queue_t));
  q->size = 0;
  q->end = malloc(sizeof(struct Node));
  q->end->next = q->end;
  q->end->prev = q->end;
  return q;
}

bool empty(priority_queue q) {
  return q->size == 0;
}

int size(priority_queue q) {
  return q->size;
}

Type top(priority_queue q) {
  return q->end->next->key;
}

void push(Type k, priority_queue q) {
  // Idendifica qual é o nó anterior ao nó onde k vai ficar,
  // ou seja, o nó com o maior elemento menor que k.
  struct Node* x = q->end;
  while (x->next != q->end && x->next->key < k) {
    x = x->next;
  }
  // Cria um novo nó e define o valor dos seus campos.
  struct Node* node = malloc(sizeof(struct Node));
  node->key = k;
  node->prev = x;
  node->next = x->next;
  // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
  node->prev->next = node;
  node->next->prev = node;
  q->size++;
}

void pop(priority_queue q) {
  struct Node* first = q->end->next;  // Ponteiro para o primeiro elemento na fila.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  free(first);
  q->size--;
}

void copy(priority_queue q, priority_queue p) {
  // Apaga todos os elementos em p.
  while (!empty(p)) {
    pop(p);
  }
  // Insere os elementos de q em p.
  for (struct Node* i = q->end->next; i != q->end; i = i->next) {
    push(i->key, p);
  }
}

void swap(priority_queue q, priority_queue p) {
  struct priority_queue_t aux = *q;
  *q = *p;
  *p = aux;
}

void delete_priority_queue(priority_queue q) {
  // Primeiramente, remove todos os elementos da fila.
  while (!empty(q)) {
    pop(q);  // A função pop() libera a memórima de cada nó removido da fila;
  }
  // Em seguida, libera a memória alocada ao sentinela.
  free(q->end);
  free(q);
}
