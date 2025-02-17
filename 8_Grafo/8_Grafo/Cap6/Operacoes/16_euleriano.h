#ifndef EULERIANO_H
#define EULERIANO_H

#include "0_structs.h"
#include "../Grafo.h"

int ehEuleriano(pDGrafo grafo) {
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0) {
        printf("Grafo invalido ou vazio.\n");
        return 0;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL) {
        pVertice v = (pVertice) atual->info;
        int grau = v->listaAdjacencias->quantidade;
        printf("Vertice %d - Grau: %d\n", *((int *)v->info), grau);

        if (grau % 2 != 0) {
            printf("Vertice %d tem grau impar. Grafo NAO e Euleriano.\n", *((int *)v->info));
            return 0;
        }

        atual = atual->prox;
    }

    printf("Todos os vertices tem grau par. Grafo e Euleriano.\n");
    return 1;
}

#endif //EULERIANO_H
