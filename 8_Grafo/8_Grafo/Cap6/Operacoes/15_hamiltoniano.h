#ifndef HAMILTONIANO_H
#define HAMILTONIANO_H

#include "0_structs.h"
#include "9_existeCaminho.h"
#include <stdio.h>

/* Verifica se um grafo é hamiltoniano e imprime o processo */
pDLista ehHamiltonianoRecursivo(pDGrafo grafo, pVertice vAtual, pDLista visitados, FuncaoComparacao fc) {
    printf("Visitando vértice %d\n", *((int *)vAtual->info));

    if (visitados->quantidade == grafo->listaVertices->quantidade) {
        printf("Caminho Hamiltoniano encontrado!\n");
        return visitados;
    }

    pNoh atual = vAtual->listaAdjacencias->primeiro;
    while (atual != NULL) {
        if (contemInfo(visitados, atual->info, fc) == 0) {
            incluirInfo(visitados, atual->info);
            printf("Adicionando vértice %d ao caminho\n", *((int *)((pVertice)atual->info)->info));

            pDLista resultado = ehHamiltonianoRecursivo(grafo, atual->info, visitados, fc);
            if (resultado != NULL) {
                return resultado;
            }

            printf("Removendo vértice %d do caminho (retrocedendo)\n", *((int *)((pVertice)atual->info)->info));
            excluirInfo(visitados, atual->info, fc);
        }
        atual = atual->prox;
    }

    return NULL;
}

pDLista ehHamiltoniano(pDGrafo grafo, FuncaoComparacao fc) {
    if (grafo->listaVertices->quantidade == 0) {
        printf("O grafo está vazio.\n");
        return NULL;
    }

    printf("Iniciando verificação de caminho Hamiltoniano...\n");
    pVertice vInicial = (pVertice)grafo->listaVertices->primeiro->info;
    pDLista visitados = criarLista();
    incluirInfo(visitados, vInicial);

    return ehHamiltonianoRecursivo(grafo, vInicial, visitados, fc);
}

#endif /* HAMILTONIANO_H */
