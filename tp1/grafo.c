#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "grafo.h"

// Mat : Matriz de adjacencia do grafo
// franquia e cliente: vertice equivalente as franquias e aos cliente, respectivamente.
// peso_max : Indica o maior valor que uma aresta pode ter de capacidade, definido pela ULONG_MAX
struct tipografo{
	
	int quant_vertices;
	TipoVertice** mat;
	TipoVertice franquia;
	TipoVertice cliente;
	TipoPeso peso_max;
};
// Recebe as especifacoes do grafo e retorna um ponteiro para um grafo que as segue.
// Usa-se calloc para a matriz pois uma posicao igual e zero indica que nao ha uma aresta
// cap_saida igual a menos significa que ainda n foi definida, pode haver cap_saida com valor 0
// Como o menor valor possivel de uma aresta e 1, coloca-se o peso_max para 0.
TipoGrafo* criar_grafo(int quant_vertices) {
	
	TipoGrafo* grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));
	
	grafo->quant_vertices = quant_vertices + 2;
	grafo->franquia = quant_vertices;
	grafo->cliente = quant_vertices + 1;
	
	grafo->mat = (TipoVertice**) malloc(sizeof(TipoVertice*) * grafo->quant_vertices );
	for(int i = 0;i < grafo->quant_vertices; i++){
		grafo->mat[i] = (TipoVertice*)calloc(grafo->quant_vertices,sizeof(TipoVertice) );
	}
	
	grafo->peso_max = ULONG_MAX;
	
	return grafo;
}
// Retorna a quantidade de vertices
int pegar_quantidade_vertices(TipoGrafo* grafo) {
	return grafo->quant_vertices;
}
// Retorna o peso maximo de uma aresta
TipoPeso pegar_peso_max(TipoGrafo* grafo) {
	return grafo->peso_max;
}
// Adiciona uma aresta ao grafo
void adicionar_aresta(TipoGrafo* grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso) {
	grafo->mat[v1][v2] = peso;
}
// Faz um vertice se tornar uma franquia
// O grafo real possui varias franquias, porem para simplificar, cria-se uma franquia equivalente a todas outras,
// tornando-a a unica franquia e criando um caminho de peso_max e criando um caminho dela a todas as outras
void adicionar_franquia(TipoGrafo* grafo, TipoVertice franquia) {
	adicionar_aresta(grafo,grafo->franquia,franquia,grafo->peso_max);
}
// Retorna a unica franquia
TipoVertice pegar_franquia(TipoGrafo* grafo) {
	return grafo->franquia;
}
// Faz um vertice se tornar um cliente
// O grafo real possui varios clientes, porem para simplificar, cria-se um cliente equivalente a todos outros,
// tornando-o o unico cliente e criando um caminho de capacidade peso_max de todos clientes a ele.
void adicionar_cliente(TipoGrafo* grafo, TipoVertice cliente) {
	adicionar_aresta(grafo,cliente,grafo->cliente,grafo->peso_max);
}
// Retorna o unico cliente
TipoVertice pegar_cliente(TipoGrafo* grafo) {
	return grafo->cliente;
}
// Adiciona fluxo a aresta
// Adicionar fluxo significa retirar capacidade
// Adiciona-se capacidade no sentido oposto para permitir o algoritmos considerar todos caminhos possiveis
void adicionar_uso(TipoGrafo* grafo,TipoVertice v1,TipoVertice v2, TipoPeso uso) {
	grafo->mat[v1][v2] -= uso;
	grafo->mat[v2][v1] += uso;
}
// Retorna o peso maximo de uma aresta
TipoPeso pegar_peso_aresta(TipoGrafo* grafo, TipoVertice v1,TipoVertice v2) {
	return grafo->mat[v1][v2];
}

// retorna o primeiro vizinho do vertice e -1 caso ele n possua vizinho e atribui o peso da aresta caso possua vizinho
TipoVertice primeiro_vizinho(TipoGrafo* grafo, TipoVertice vertice, TipoPeso* peso ) {
	TipoVertice vizinho;
	for(vizinho = 0; vizinho < pegar_quantidade_vertices(grafo); vizinho++ )
		if(grafo->mat[vertice][vizinho] != 0 ){
			*peso = grafo->mat[vertice][vizinho];
			return vizinho;
		}
	return -1;	
}
// retorna o proximo vizinho do vertice depois do recebido e -1 caso ele n possua mais vizinhos e atribui o peso da aresta caso possua vizinho
TipoVertice proximo_vizinho(TipoGrafo* grafo, TipoVertice vertice, TipoVertice vizinho, TipoPeso* peso ) {
	for(vizinho += 1; vizinho < pegar_quantidade_vertices(grafo); vizinho++ )
		if(grafo->mat[vertice][vizinho] != 0 ) {
			*peso = grafo->mat[vertice][vizinho];
			return vizinho;
		}
	return -1;		
}
// Libera a memoria do grafo
void destruir_grafo(TipoGrafo* grafo) {
	for(int i = 0;i < pegar_quantidade_vertices(grafo); i++){
		free(grafo->mat[i]);
	}
	free(grafo->mat);
	free(grafo);
}