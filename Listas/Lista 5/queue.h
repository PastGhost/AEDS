// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef QUEUE_H_
#define QUEUE_H_

// Tipo dos elementos na fila.
typedef int Type;

// Tipo de dado queue (fila).
// Para garantir o ecapsulamento, 'struct queue_t' só é definido no arquivo ".c".
typedef struct queue_t* queue;

// Cria uma fila vazia  em O(1).
queue new_queue();

// Testa se a fila está vazia em O(1).
int empty(queue q);

// Retorna o número de elementos na fila em O(1).
int size(queue q);

// Retorna o elemento que está no início da fila em O(1).
// Precondição: a fila não pode estar vazia.
Type front(queue q);

// Retorna o elemento que está no final da fila em O(1).
// Precondição: a fila não pode estar vazia.
Type back(queue q);

// Insere k no final da fila em O(1).
void push(Type k, queue q);

// Remove o elemento que está no início da fila em O(1).
// Precondição: a fila não pode estar vazia.
void pop(queue q);

// Faz a fila p ter os mesmos elementos que a fila q em O(n + m),
// onde n = size(p) e m = size(q).
void copy(queue q, queue p);

// Troca o conteúdo da fila p com o da fila q em O(1).
void swap(queue q, queue p);

// Libera a memória alocada para a fila em O(n).
void delete_queue(queue q);

#endif  // QUEUE_H_
