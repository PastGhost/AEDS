// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <stdbool.h>
#include "solucao.h"

// Tipo de dado priority_queue (fila de prioridade).
// Para garantir o ecapsulamento, 'struct priority_queue_t' só é definido em priority_queue.c.
typedef struct priority_queue_t* priority_queue;

// Cria uma fila vazia.
priority_queue new_priority_queue(int size);

// Testa se a fila está vazia.
bool empty(priority_queue q);

// Retorna o número de elementos na fila.
int size(priority_queue q);

// Retorna o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
Type top(priority_queue q);

// Insere k na fila.
void push(Type k, priority_queue q, int flag);

// Insere k na fila sem estebelecer a prioridade
void fill(Type k, priority_queue q, int flag);

// Estabelece a prioridade usando a flag de cada registro
void sort_queue_flag(priority_queue q);

// Estabelece a prioridade na fila sem usar a flag
void sort_queue(priority_queue q);

// Insere k na fila e usa a flag como prioridade
void push_flag(Type k, priority_queue q, int flag);

// Remove o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
void pop(priority_queue q);

// Troca a posicao de maior prioridade por k
// Nao considera a flag
void switch_top(Type k, priority_queue q,int flag);

// Remove o menor elemento da fila.
// Considera a flag
// Precondição: a fila não pode estar vazia.
void pop_flag(priority_queue q);

// Troca a posicao de maior prioridade por k
// Nao considera a flag
void switch_top_flag(Type k, priority_queue q,int flag);

// Retorna a flag da maior posicao
int top_flag(priority_queue q);

// Libera a memória alocada para a fila.
void delete_priority_queue(priority_queue q);


#endif  // PRIORITY_QUEUE_H_
