// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)
#include "grafo.h"
#ifndef fila_H_
#define fila_H_

// Tipo dos elementos na fila.
typedef TipoVertice Tipo;

// Tipo de dado fila (fila).
// Para garantir o ecapsulamento, 'struct fila_t' só é definido no arquivo ".c".
typedef struct fila_t* fila;

// Cria uma fila vazia  em O(1).
fila nova_fila();

// Testa se a fila está vazia em O(1).
int vazia(fila q);

// Retorna o elemento que está no início da fila em O(1).
// Precondição: a fila não pode estar vazia.
Tipo frente(fila q);

// Insere k no final da fila em O(1).
void push(Tipo k, fila q);

// Remove o elemento que está no início da fila em O(1).
// Precondição: a fila não pode estar vazia.
void pop(fila q);

// Libera a memória alocada para a fila em O(n).
void delete_fila(fila q);

#endif  // fila_H_
