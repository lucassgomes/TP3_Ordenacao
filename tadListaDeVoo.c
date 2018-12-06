#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadListaDeVoo.h"

/**
 * Função que contém os printf's da ED do TAD voo
 * @param voo Endereço da ED do TAD voo
 */
void imprimeGets(tadVoo *voo) {
    printf("VID: %d\n", getVid(voo)); //
    printf("Hora Decolagem: %s\n", getHrDecolagem(voo));
    printf("Hora Prevista para Pouso: %s\n", getHrPrevPouso(voo));
    printf("Aeroporto Decolagem: %s\n", getAeroportoDecolagem(voo));
    printf("Aeroporto Previsto para Pouso: %s\n", getAeroportoPrevPouso(voo));
    printf("Pista de Decolagem: %d\n\n", getPistaDecolagem(voo));
}

/**
 * Inicializa a lista vazia
 * @param listaVoo Endereço da lista encadeada de voos
 */
void fazListaVazia(tadListaVoo* listaVoo) {
    listaVoo->primeiro = (tipoApontador) malloc(sizeof (tipoCelula));
    listaVoo->ultimo = listaVoo->primeiro;
    listaVoo->primeiro->prox = NULL;
}

/**
 * Verifica se a lista é vazia com a condição de o apontador primeiro ser igual ao apontador último
 * @param listaVoo Endereço da lista encadeada de voos
 * @return int 1 caso a lista esteja vazia
 */
int vazia(tadListaVoo listaVoo) {
    return (listaVoo.primeiro == listaVoo.ultimo);
}

/**
 * Insere um voo na lista encadeada de voos
 * @param listaVoo Endereço da lista encadeada de voos
 * @param voo cópia da estrutura de dados do TAD voo
 * @return
 */
int insereVoo(tadListaVoo* listaVoo, tadVoo voo) {
    tipoApontador posicao, novo;
    posicao = listaVoo->primeiro;
    while (posicao->prox != NULL) {
        if (strcmp(posicao->prox->voo.hrDecolagem, voo.hrDecolagem) >= 0) {
            novo = (tipoApontador) malloc(sizeof (tipoCelula));
            novo->voo = voo;
            novo->prox = posicao->prox;
            posicao->prox = novo;
            return 0;
        }
        posicao = posicao->prox;
    }
    listaVoo->ultimo->prox = (tipoApontador) malloc(sizeof (tipoCelula));
    listaVoo->ultimo = listaVoo->ultimo->prox;
    listaVoo->ultimo->voo = voo;
    listaVoo->ultimo->prox = NULL;
    return 0;
}

/**
 * Retira um voo na lista encadeada a partir de um determinado identificador (VID)
 * @param listaVoo Endereço da lista encadeada de voos
 * @param vid Identificador (VID) do voo
 * @param voo Endereço da ED para retorno do TAD voo retirado da lista
 * @return int 1 caso a retirada seja feita
 */
int retornaVoo(tadListaVoo* listaVoo, int vid, tadVoo* voo) {
    tipoApontador posicao, aux;
    if (vazia(*listaVoo)) return 1;
    posicao = listaVoo->primeiro;
    while (posicao->prox != NULL) {
        if (posicao->prox->voo.vid == vid) {
            aux = posicao->prox;
            *voo = aux->voo;
            posicao->prox = aux->prox;
            if (posicao->prox == NULL) listaVoo->ultimo = posicao;
            free(aux);
            return 1;
        }
        posicao = posicao->prox;
    }
    return 0;
}

/**
 * Procura um voo na lista encadeada a partir de um determinado identificador (VID)
 * @param listaVoo Endereço da lista encadeada de voos
 * @param vid Identificador (VID) do voo
 * @param voo Endereço da ED do TAD voo encontrado
 * @return int 1 caso encontre o voo
 */
int procuraVoo(tadListaVoo* listaVoo, int vid, tadVoo* voo) {
    tipoApontador posicao;
    posicao = listaVoo->primeiro;
    while (posicao->prox != NULL) {
        if (posicao->prox->voo.vid == vid) {
            *voo = posicao->prox->voo;
            return 1;
        }
        posicao = posicao->prox;
    }
    return 0;
}

/**
 * Imprimir voos da lista encadeada de voos
 * @param listaVoo Endereço da lista encadeada de voos
 */
void imprimeVoo(tadListaVoo listaVoo) {
    tipoApontador aux;
    aux = listaVoo.primeiro->prox;
    while (aux != NULL) {
        imprimeGets(&aux->voo);
        aux = aux->prox;
    }
}