/* 
===========================================
Universidade Federal de Minas Gerais
Departamento de Ciência da Computação
AEDS 3
TP 0 - Hit do Verão
Valéria Pereira de Souza 2016/118541
===========================================
*/

// Damn, I was pretty verbose with my comments lol

#include <stdio.h>
# include <stdlib.h>
#include "grafo.h"

//== Cria vetor de vértices e inicializa campos ====
Vertice* criaGrafo (int v){
    int i;
    Vertice *grafo;
    grafo = (Vertice*) malloc(v * sizeof(Vertice));

    for(i=0; i<v; i++){
        grafo[i].id = 0;
        grafo[i].idade = 0;
        grafo[i].visitado=0;
        grafo[i].gostou=0;
        grafo[i].p_primeiro =  NULL;
        grafo[i].p_ultimo = NULL;
    }
    return grafo;
}

//== Insere Aresta nos dois sentidos ====
void insereAresta(Vertice *grafo, int v, int w){
        int i, aux;

         for(i=0; i<2; i++){   
            Aresta *novaAresta = (Aresta*) malloc(sizeof(Aresta));

            if(grafo[v-1].p_primeiro==NULL)    // Se for o primeiro relacionamento do vértice, liga na cabeça da lista
                grafo[v-1].p_primeiro = novaAresta;
            else                               // Do segundo relacionamento em diante, liga na última Aresta
                grafo[v-1].p_ultimo->p_proximo = novaAresta;
                
            grafo[v-1].p_ultimo = novaAresta; //Atualiza cauda da lista
            novaAresta->viz = w;              //Atribui ID à novaAresta
            novaAresta->p_proximo = NULL;     //Aterra último ponteiro

            aux=w; //Espelha o relacionamento
            w=v;
            v=aux;
        }

}


void DFS_espalhaHit(Vertice *grafo, int atual){

    if ((grafo[atual-1].visitado)==1)   //se vértice já foi visitado, encerra
        return;

    grafo[atual-1].visitado=1;          //Atualiza flag 'visitado'

    if (grafo[atual-1].idade>=35){      //Se pessoa tem idade >=35, 
        grafo[atual-1].gostou=0;        // atualiza flag 'gostou'e 
        return;                         // encerra
    
    } else if (grafo[atual-1].idade<35){              //Se a pessoa tem menos de 35 anos,
        grafo[atual-1].gostou=1;                    // atualiza flag 'gostou'
        Aresta *aux = grafo[atual-1].p_primeiro;    // Aponta um ponteiro auxiliar para o primeiro item da lista de relacionamentos

        if (aux==NULL)                              //Se aux aponta para NULL, o vértice não tem relacionamento
            return;                                 // encerra

        while(aux!=NULL){                           //Enquanto o vértice tiver relacionamentos,
            DFS_espalhaHit(grafo, aux->viz);    // roda a função para o proximo vizinho
            aux = aux->p_proximo;       // move ponteiro para o próximo vizinho
        }
    }
}


void limpaGrafo(Vertice *grafo, int v){
    int i;
    Aresta *aux;

    for(i=0; i<v; i++)
        while (grafo[i].p_primeiro != NULL){        //Enquanto o vértice tiver relacionamentos alocados, 
            aux = grafo[i].p_primeiro;              // ponteiro aux marca a primeira Aresta
            grafo[i].p_primeiro = aux->p_proximo;   // atualiza cabeça da lista para a próxima Aresta
            free(aux);                              // libera Aresta marcada pelo aux
        }

    free(grafo);    //Libera vetor de Vértices
}
