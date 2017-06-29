// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#include "set.h"

#include <stdlib.h>

// Os elementos do conjunto estão distribuídos sequencialmente em uma
// lista duplamente encadeada com sentinela.
struct Node{
  Type key;
  struct Node* prev;  // Nó a esquerda.
  struct Node* next;  // Nó a direita.
};

struct set_t{
  struct Node* end;  // Nó sentinela.
  int size;  // Número de elementos no conjunto.
};

set new_set() {
  set s = malloc(sizeof(struct set_t));
  s->size = 0;
  s->end = malloc(sizeof(struct Node));
  s->end->prev = s->end;
  s->end->next = s->end;
  return s;
}

bool empty(set s) {
  return s->size == 0;
}

int size(set s) {
  return s->size;
}

Type element(set s) {
  return s->end->next->key;
}

bool find(Type k, set s) {
  for(struct Node* i = s->end->next; i != s->end; i = i->next ) {
    if(i->key == k) return true;
  }
  return false;
}

void insert(Type k, set s) {
  if(!find(k,s)) {
    struct Node* last = s->end->prev;
    struct Node* ins = malloc(sizeof(struct Node));
    ins->prev = last;
    ins->next = last->next;
    ins->key = k;
    last->next = ins;
    s->end->prev = ins;
    s->size++;
  }
}

void erase(Type k, set s) {
  struct Node* i;
  int flag = 0;
  for(i = s->end->next; i != s->end && flag != 1; i = i->next ) {
    if(i->key == k){
      i->prev->next = i->next;
      i->next->prev = i->prev;
      free(i);
      s->size--;
      flag = 1;
    }
  }
}

void clear(set s) {
    while(!empty(s)) {
      erase(element(s),s);
    }
}
//q = s
void copy(set s, set p) {
  clear(p);
  for (struct Node* i = s->end->prev; i != s->end; i = i->prev) {
    insert(i->key, p);
  }
  
}

void delete_set(set s) {
  clear(s);
  free(s->end);
  free(s);
}
