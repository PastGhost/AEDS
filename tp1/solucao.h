#ifndef SOLUCAO_H_
#define SOLUCAO_H_
#include "grafo.h"


// Realiza uma busca em largura no grafo
// Caso um caminho ate o cliente  seja encontrado, retorna 1, caso nao seja encontrado retorna 0
// O caminho ate o cliente e salvo no vetor pai
int BFS(TipoGrafo* grafo, TipoVertice* pai);

// Retorna o menor de dois numeros
TipoPeso menor(TipoPeso a, TipoPeso b);

// faz o caminho partindo do cliente ate se chegar na franquia, guardando o valor da menor franquia
TipoPeso achar_fluxo_caminho(TipoGrafo* grafo, TipoVertice *pai, TipoVertice franquia, TipoVertice cliente);

// Adiciona o fluxo que passa no caminho em cada aresta que pertence a ele
void adicionar_uso_caminho(TipoGrafo* grafo, TipoVertice *pai, TipoVertice franquia, TipoVertice cliente, TipoPeso fluxo_caminho);

// Encontra e retorna o fluxo maximo que se pode circular no grafo partida das franquias ate os clientes
// Enquando a Busca em largura encontrar um caminho entre uma das franquias ate um dos clientes, pega esse caminho encontrado
// E descobre o fluxo maximo que se pode circular nele, pegando a menor capacidade das arestas do caminho, e adiciona esse valor encontrado
// ao fluxo total
TipoPeso achar_fluxo(TipoGrafo* grafo);


#endif