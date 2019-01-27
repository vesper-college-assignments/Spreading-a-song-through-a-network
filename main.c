/* 
===========================================
Universidade Federal de Minas Gerais
Departamento de Ciência da Computação
AEDS 3
TP 0 - Hit do Verão
Valéria Pereira de Souza 2016/118541
===========================================
*/


#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main(){


    int n1, n2, count=0, v, e, i, primeiro;
    scanf("%d %d", &v,&e);


    //== 1. Cria vetor de struct Vértice de tamanho "v" =============
    Vertice *grafo;
    grafo = criaGrafo(v);

    //== 2. Recebe e atribui ID e idades =============
    for(i=0; i<v; i++){
        scanf ("%d %d", &n1, &n2);
        grafo[i].id = n1;
        grafo[i].idade = n2;
    }

    //== 3. Recebe par de relacionamentos e insere Aresta nos dois sentidos ============
    for (i=0; i<e; i++){
        scanf ("%d %d", &n1, &n2);
        insereAresta(grafo, n1, n2);
    }

    //== 4. Recebe o primeiro a ouvir a música e roda a função espalhaHit =============
    scanf("%d", &primeiro);
    DFS_espalhaHit(grafo, primeiro);


    //== 5. Itera no vetor de Vértices contando o marcador "gostou" =============
    for(i=0; i<v; i++)
        if(grafo[i].gostou ==1)
            count++;


    //== 6. Desaloca as estruturas =============
    limpaGrafo(grafo, v);


    //== 7. Imprime o total =============
    printf("%d\n", count);

    return 0;

}
