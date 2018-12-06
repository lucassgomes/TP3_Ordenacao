#include <stdio.h>
#include <stdlib.h>
#include "tadVoo.h"

//Ponteiro apontador
typedef struct tipoCelula *tipoApontador;

//ED para célula da lista encadeada
typedef struct tipoCelula{
    tadVoo voo; //Lista Linear - TADVoo (info)
    tipoApontador prox; //Apontamento para próxima célula (prox)
} tipoCelula;

//ED para células cabeça da lista encadeada
typedef struct {
    tipoApontador primeiro, ultimo; //Apontamento para primeiro e último elemento da lista
} tadListaVoo;

/**
 * Inicializa a lista vazia
 * @param listaVoo Endereço da lista encadeada de voos
 */
void fazListaVazia(tadListaVoo* listaVoo);

/**
 * Verifica se a lista é vazia com a condição de o apontador primeiro ser igual ao apontador último
 * @param listaVoo Endereço da lista encadeada de voos
 * @return int 1 caso a lista esteja vazia
 */
int vazia(tadListaVoo listaVoo);

/**
 * Insere um voo na lista encadeada de voos
 * @param listaVoo Endereço da lista encadeada de voos
 * @param voo cópia da estrutura de dados do TAD voo
 * @return
 */
int insereVoo(tadListaVoo* listaVoo, tadVoo voo);

/**
 * Retira um voo na lista encadeada a partir de um determinado identificador (VID)
 * @param listaVoo Endereço da lista encadeada de voos
 * @param vid Identificador (VID) do voo
 * @param voo Endereço da ED para retorno do TAD voo retirado da lista
 * @return int 1 caso a retirada seja feita
 */
int retornaVoo(tadListaVoo* listaVoo, int vid, tadVoo* voo);

/**
 * Procura um voo na lista encadeada a partir de um determinado identificador (VID)
 * @param listaVoo Endereço da lista encadeada de voos
 * @param vid Identificador (VID) do voo
 * @param voo Endereço da ED do TAD voo encontrado
 * @return int 1 caso encontre o voo
 */
int procuraVoo(tadListaVoo* listaVoo, int vid, tadVoo* voo);

/**
 * Imprimir voos da lista encadeada de voos
 * @param listaVoo Endereço da lista encadeada de voos
 */
void imprimeVoo(tadListaVoo listaVoo);

/**
 * Função que contém os printf's da ED do TAD voo
 * @param voo Endereço da ED do TAD voo
 */
void imprimeGets(tadVoo *voo);