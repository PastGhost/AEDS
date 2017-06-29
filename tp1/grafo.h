#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct tipografo TipoGrafo;
typedef int TipoVertice;
typedef unsigned long TipoPeso;
// Definicao da struct no arquivo .c
// Eu escolhi por deixar todo o codigo em portugues, entao as funcoes pegar seriam os "getters", adicionar os "setters", que retornam ou modificam o valor de algo

// Recebe as especifacoes do grafo e retorna um ponteiro para um grafo que as segue.
TipoGrafo* criar_grafo(int quant_vertices);

int pegar_quantidade_vertices(TipoGrafo* grafo);

TipoPeso pegar_peso_max(TipoGrafo* grafo);

void adicionar_aresta(TipoGrafo* grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso);

void adicionar_franquia(TipoGrafo* grafo, TipoVertice franquia);

TipoVertice pegar_franquia(TipoGrafo* grafo);

void adicionar_cliente(TipoGrafo* grafo, TipoVertice cliente);

TipoVertice pegar_cliente(TipoGrafo* grafo);

void adicionar_uso(TipoGrafo* grafo,TipoVertice v1,TipoVertice v2, TipoPeso uso);

TipoPeso pegar_peso_aresta(TipoGrafo* grafo, TipoVertice v1,TipoVertice v2);

TipoVertice primeiro_vizinho(TipoGrafo* grafo, TipoVertice vertice, TipoPeso* peso );

TipoVertice proximo_vizinho(TipoGrafo* grafo, TipoVertice vertice, TipoVertice vizinho, TipoPeso* peso );

void destruir_grafo(TipoGrafo* grafo);

#endif