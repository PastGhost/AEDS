// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_H_
#define SET_H_

#include <stdbool.h>

// Tipo dos elementos no conjunto.
typedef float Type;

// Tipo de dado set (Conjunto).
// Os elementos não estão organizados em uma ordem específica.
// Para garantir o ecapsulamento, 'struct set_t' só é definido em set.c.
typedef struct set_t* set;

// Cria um conjunto vazio.
set new_set();

// Testa se o cojunto está vazio.
bool empty(set s);

// Retorna o número de elementos no conjunto.
int size(set s);

// Retorna um elemento qualquer de s.
Type element(set s);

// Verifica se k pertence a s.
bool find(Type k, set s);

// Insere k no conjunto.
// Caso k já pertença ao conjunto, um novo elemento NÃO é inserido.
void insert(Type k, set s);

// Remove k do conjunto (caso lá ele esteja).
void erase(Type k, set s);

// Remove todos os elementos do conjunto.
void clear(set s);

// Faz com que o conjunto q contenha exatamente os mesmos elementos
// do cojunto s.
void copy(set s, set q);

// Libera toda a memória alocada para o conjunto.
void delete_set(set s);

#endif  // SET_H_
