// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.c o TAD set.
//
// Questão 2.
// Escreva uma função "void Imprimir(set s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.

#include "set.h"

#include <stdio.h>
#include <stdlib.h>

// Questão 2.
void Imprimir(set s) {
  set q = new_set();
  copy(s, q);
  printf("{ ");
  while (!empty(q)) {
    float k = element(q);
    printf("%.1f ", k);
    erase(k, q);
  }
  printf("}#%d", size(s));
  delete_set(q);
}

int main() {
  set s = new_set();
  set p = new_set();
  for (int i = 0; i < 10; i++) {
    insert(i, s);
    printf("Size: %d\n",size(s));
  }
  for (int i = 1; i < 10; i = i + 2) {
    erase(i, s);
    printf("Size: %d\n",size(s));
  }
  copy(s, p);
  clear(s);

  if (empty(s)) {
    printf("O conjunto s esta vazio.\n");
  }
  if (find(4, p)) {
    printf("O numero 4 pertence ao conjunto.\n");
  }
  if (!find(5, p)) {
    printf("O numero 5 nao pertence ao conjunto.\n");
  }
  Imprimir(p);
  printf("\n");
  delete_set(p);
  delete_set(s);
  //system("pause");
  return 0;
}
