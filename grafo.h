/* 
===========================================
Universidade Federal de Minas Gerais
Departamento de Ciência da Computação
AEDS 3
TP 0 - Hit do Verão
Valéria Pereira de Souza 2016/118541
===========================================
*/

typedef struct vertice {
    int id;
    int idade;
    int visitado;
    int gostou;
    struct aresta *p_primeiro;
    struct aresta *p_ultimo;
} Vertice;


typedef struct aresta{
    int viz;
    struct aresta *p_proximo;
}Aresta;



Vertice* criaGrafo (int v);

void insereAresta(Vertice *grafo, int v, int w);

void DFS_espalhaHit(Vertice *grafo, int atual);

void limpaGrafo(Vertice *grafo, int v);
