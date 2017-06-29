// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <stdbool.h>

// Tipo dos elementos na fila de prioridades.
typedef float Type;

// Tipo de dado priority_queue (fila de prioridade).
// Para garantir o ecapsulamento, 'struct priority_queue_t' só é definido em priority_queue.c.
typedef struct priority_queue_t* priority_queue;

// Cria uma fila vazia.
priority_queue new_priority_queue();

// Testa se a fila está vazia.
bool empty(priority_queue q);

// Retorna o número de elementos na fila.
int size(priority_queue q);

// Retorna o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
Type top(priority_queue q);

// Insere k na fila.
void push(Type k, priority_queue q);

// Remove o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
void pop(priority_queue q);

// Faz a fila p ter os mesmos elementos que a fila q.
void copy(priority_queue q, priority_queue p);

// Troca o conteúdo da fila p com o da fila q.
void swap(priority_queue q, priority_queue p);

// Libera a memória alocada para a fila.
void delete_priority_queue(priority_queue q);

#endif  // PRIORITY_QUEUE_H_
