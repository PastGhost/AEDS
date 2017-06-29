// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "fila.h"

#include <stdlib.h>

// Define como os elementos da fila serão organizados na memória.
struct no {
  Tipo key;
  struct no* ant;
  struct no* prox;
};

struct fila_t{
  struct no* fim;  // Ponteiro para o sentinela.
  int tamanho;  // Número de elementos na fila.
};

fila nova_fila() {
  fila q = malloc(sizeof(struct fila_t));
  q->tamanho = 0;
  q->fim = malloc(sizeof(struct no));
  q->fim->ant = q->fim;
  q->fim->prox = q->fim;
  return q;
}

int vazia(fila q) {
  return q->tamanho == 0;
}

Tipo frente(fila q) {
  return q->fim->prox->key;
}

void push(Tipo k, fila q) {
  struct no* ultimo = q->fim->ant;
  struct no* ins = malloc(sizeof(struct no));
  ins->key = k;
  ins->prox = q->fim;
  ins->ant = ultimo;
  ultimo->prox = ins;
  q->fim->ant = ins;
  q->tamanho++;
}

void pop(fila q) {
  struct no* popped = q->fim->prox;
  popped->ant->prox = popped->prox;
  popped->prox->ant = popped->ant;
  free(popped);
  q->tamanho--;
}

void delete_fila(fila q) {
  while (!vazia(q)) {
    pop(q);
  }
  free(q->fim);
  free(q);
}

