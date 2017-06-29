#include <stdio.h>
#include "solucao.h"
#include "grafo.h"

int main() {
	TipoGrafo* grafo;
	int vertices, franquias, arestas, clientes;
	TipoVertice v1, v2;
	TipoPeso peso, total;
	scanf("%d %d %d %d",&vertices,&arestas,&franquias,&clientes);
	grafo = criar_grafo(vertices);
	for(int i = 0;i < arestas; i++) {
		scanf("%d %d %lu",&v1,&v2,&peso);
		adicionar_aresta(grafo,v1,v2,peso);
	}
	for(int i = 0; i < franquias; i++) {
		scanf("%d",&v1);
		adicionar_franquia(grafo,v1);
	}
	for(int i = 0; i < clientes; i++) {
		scanf("%d",&v1);
		adicionar_cliente(grafo,v1);
	}
	total = achar_fluxo(grafo);
	printf("%lu\n",total);
	destruir_grafo(grafo);
	return 0;

}