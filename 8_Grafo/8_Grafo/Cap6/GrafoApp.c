#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"
#include "../Cap3/Utils.h"

int comparaVertice(void *info1, void *info2){

    pVertice v1 = (pVertice) info1;
    pVertice v2 = (pVertice) info2;

    int *id1 = (int *) v1->info;
    int *id2 = (int *) v2->info;

    return *id2 - *id1;
}

/* ----------------------------- */
void imprimeAdjacencia(void *info1){
    pVertice v = (pVertice) info1;
    printf("%d - " , *((int *)(v->info)));
}

/* ----------------------------- */
void imprimeVertice(void *info1){
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - Adjacencias [" , *((int *)v->info));

    imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
    printf("]\n");
}

/* ----------------------------- */
void imprimeVerticeSemAdjacencias(void *info1){
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void* alocaInfoVertice(void *info){
   pVertice pv = (pVertice) malloc(sizeof(Vertice));
   pv->info = alocaInfoInt(((pVertice)info)->info);
   return pv;
}

/* ----------------------------- */
void main(){

    int vertices[] = {1,2,3,4,5};

    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = NULL;

    do{
        printf("\n 0  - Criar novo grafo \n");
        printf("  1  - Incluir Vertice \n");
        printf("  2  - Incluir Aresta \n");
        printf("  3  - Excluir Vertice [implementar] \n");
        printf("  4  - Excluir Aresta  [implementar] \n");
        printf("  5  - Mostrar grafo \n");
        printf("  6  - Busca em profundidade \n");
        printf("  7  - Busca em amplitude [implementar]\n");
        printf("  8  - Existe caminho?  (entre dois vertices) \n");
        printf("  9  - Encontra caminho (entre dois vertices) \n");
        printf("  11  - Criar grafo Hamiltoniano e Euleriano\n");
        printf("  12  - Verifica se o grafo e Hamiltoniano \n");
        printf("  13  - Verifica se o grafo e Euleriano\n");
        printf(" 10 - Sair \n");

        scanf ("%d", &opcao);

        switch (opcao){

         case 0 :
            if (grafo == NULL) {
                grafo = criarGrafo();
                incluirVertice(grafo, &vertices[0], comparaVertice);
                incluirVertice(grafo, &vertices[1], comparaVertice);
                incluirVertice(grafo, &vertices[2], comparaVertice);
                incluirVertice(grafo, &vertices[3], comparaVertice);
                incluirVertice(grafo, &vertices[4], comparaVertice);

                incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
                incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);
                incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
                incluirAresta(grafo, &vertices[2], &vertices[4], comparaVertice);
                incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice);
                incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
            } else {
                printf("\nJa existe um grafo criado.\n");
            }
            mostrarGrafo(grafo, imprimeVertice);
            getchar();
            break;

        case 1 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                pv = (int *)malloc(sizeof(int));
                printf ("ID do vertice : ");
                scanf("%d", pv);
                incluirVertice(grafo, pv, comparaVertice);

                mostrarGrafo(grafo, imprimeVertice);
            }
            getchar();
            break;

        case 2 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                printf ("\nID do vertice origem : ");
                scanf("%d", &vOrigem);
                printf ("\nID do vertice destino : ");
                scanf("%d", &vDestino);
                incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

                mostrarGrafo(grafo,imprimeVertice);
            }
            getchar();
            break;

        case 5 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                mostrarGrafo(grafo, imprimeVertice);
            }
            getchar();
            break;

        case 6 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                buscaEmProfundidade(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
            }
            getchar();
            break;

        case 8 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                printf ("\nID do vertice origem : ");
                scanf("%d", &vOrigem);
                printf ("\nID do vertice destino : ");
                scanf("%d", &vDestino);

                int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
                if (result != 0)
                    printf("Existe caminho!\n");
                else
                    printf("Nao existe caminho!\n");
            }
            getchar();
            break;

        case 9 :
            if (grafo == NULL) {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            } else {
                printf ("\nID do vertice origem : ");
                scanf("%d", &vOrigem);
                printf ("\nID do vertice destino : ");
                scanf("%d", &vDestino);

                pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice, alocaInfoVertice);
                if (caminho->quantidade > 0){
                    printf("\nExiste um caminho: ");
                    imprimirLista(caminho, imprimeVerticeSemAdjacencias);
                } else {
                    printf("\n*** NAO existe um caminho. ***\n");
                }
            }
            getchar();
            break;

         case 11:
            printf("\nCriando grafo Hamiltoniano e Euleriano...\n");
            if (grafo == NULL) {
                grafo = criarGrafo();
                int vertices_ham_eul[] = {1, 2, 3, 4, 5, 6};
                for (int i = 0; i < 6; i++) {
                    incluirVertice(grafo, &vertices_ham_eul[i], comparaVertice);
                }

                incluirAresta(grafo, &vertices_ham_eul[0], &vertices_ham_eul[1], comparaVertice);
                incluirAresta(grafo, &vertices_ham_eul[1], &vertices_ham_eul[2], comparaVertice);
                incluirAresta(grafo, &vertices_ham_eul[2], &vertices_ham_eul[3], comparaVertice);
                incluirAresta(grafo, &vertices_ham_eul[3], &vertices_ham_eul[4], comparaVertice);
                incluirAresta(grafo, &vertices_ham_eul[4], &vertices_ham_eul[5], comparaVertice);
                incluirAresta(grafo, &vertices_ham_eul[5], &vertices_ham_eul[0], comparaVertice);
            } else {
                printf("\nJa existe um grafo criado.\n");
            }
            mostrarGrafo(grafo, imprimeVertice);
            getchar();
            break;

        case 12:
            if (grafo != NULL) {
                if (ehHamiltoniano(grafo, comparaVertice)) {
                    printf("\nO grafo e Hamiltoniano.\n");
                } else {
                    printf("\nO grafo NAO e Hamiltoniano.\n");
                }
            } else {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            }
            getchar();
            break;

        case 13:
            if (grafo != NULL) {
                if (ehEuleriano(grafo)) {
                    printf("O grafo e Euleriano.\n");
                } else {
                    printf("O grafo NAO e Euleriano.\n");
                }
            } else {
                printf("\nCrie um grafo primeiro (opcao 0).\n");
            }
            getchar();
            break;
        }
    } while (opcao != 10);

    return 0;
}
