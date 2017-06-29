#include <stdio.h>
#include <stdlib.h>
#include "solucao.h"
#include "grafo.h"
#include "fila.h"


// Realiza uma busca em largura no grafo
// Caso um caminho ate o cliente  seja encontrado, retorna 1, caso nao seja encontrado retorna 0
// O caminho ate o cliente e salvo no vetor pai
int BFS(TipoGrafo* grafo, TipoVertice* pai) {
	
	int *visitou = (int*)calloc(pegar_quantidade_vertices(grafo),sizeof(int) );
	int retorno = 0;
	fila q = nova_fila();
	TipoVertice franquia, cliente, u, v;
	franquia = pegar_franquia(grafo);
	cliente = pegar_cliente(grafo);
	TipoPeso peso;
	push(franquia,q);
	visitou[franquia] = 1;
	// Busca em largura normal
	// Visita-se todos os vertices vizinhos ao inicial, adiciona-os a pilha e coloca o vertice a partir do qual o encontrou no vetor pai
	while(!vazia(q)) {
	
		u = frente(q);
		pop(q);
		// Enquanto houver um vizinho a esse vertice
		for( v = primeiro_vizinho(grafo,u,&peso); v != -1; v = proximo_vizinho(grafo,u,v,&peso) ) {
			if(visitou[v] == 0 ) {
				push(v,q);
				pai[v] = u;
				visitou[v] = 1;
				
			}
		}
		
	}
	delete_fila(q);
	if(visitou[cliente] == 1){
		retorno = 1;
	}
	free(visitou);
	return retorno;
	
}

// Retorna o menor de dois numeros
TipoPeso menor(TipoPeso a, TipoPeso b) {
	if(a > b) 
		return b;
	else
		return a;
}

// faz o caminho partindo do cliente ate se chegar na franquia, guardando o valor da menor franquia
TipoPeso achar_fluxo_caminho(TipoGrafo* grafo, TipoVertice *pai, TipoVertice franquia, TipoVertice cliente) {
	
	TipoVertice u, v;
	TipoPeso fluxo_caminho = pegar_peso_max(grafo);
	for( v = cliente; v != franquia; v = u  ) {
		u = pai[v];
		fluxo_caminho = menor(fluxo_caminho,pegar_peso_aresta(grafo,u,v) );
	}
	return fluxo_caminho;
}

// Adiciona o fluxo que passa no caminho em cada aresta que pertence a ele
void adicionar_uso_caminho(TipoGrafo* grafo, TipoVertice *pai, TipoVertice franquia, TipoVertice cliente, TipoPeso fluxo_caminho) {
	TipoVertice u, v;
	for( v = cliente; v != franquia; v = u  ) {
		u = pai[v];
		adicionar_uso(grafo,u,v,fluxo_caminho);
	}

}

// Encontra e retorna o fluxo maximo que se pode circular no grafo partida das franquias ate os clientes
// Enquando a Busca em largura encontrar um caminho entre uma das franquias ate um dos clientes, pega esse caminho encontrado
// E descobre o fluxo maximo que se pode circular nele, pegando a menor capacidade das arestas do caminho, e adiciona esse valor encontrado
// ao fluxo total
TipoPeso achar_fluxo(TipoGrafo* grafo) {
	
	TipoVertice* pai = (TipoVertice*)calloc(pegar_quantidade_vertices(grafo),sizeof(TipoVertice) );
	
	TipoVertice franquia, cliente;
	franquia = pegar_franquia(grafo);
	cliente = pegar_cliente(grafo);
	TipoPeso fluxo_total, fluxo_caminho;
	// TipoVertice u, v;
	
	fluxo_total = 0;
	
	while(BFS(grafo,pai)) {
		
		fluxo_caminho = achar_fluxo_caminho(grafo,pai,franquia,cliente);

		adicionar_uso_caminho(grafo,pai,franquia,cliente,fluxo_caminho);

		fluxo_total += fluxo_caminho;
		
	}
	free(pai);
	return fluxo_total;
	
	
	
	
	
}









