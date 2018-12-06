#include <stdio.h>
#include <stdlib.h>
#include "tadListaDeVoo.h"

//ED do TAD item da matriz
typedef struct {
    tadListaVoo listaVoo;
    int numVoos;
    char horarioAtualizacao[9];
} tadItemMatriz;

/**
 * Inicializa o TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 */
void inicializarTadItemMatriz(tadItemMatriz *itemMatriz);

/**
 * Retorna a lista encadeada a partir do endereço do TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @return tadListaVoo lista encadeada de voos
 */
tadListaVoo getListaVoo(tadItemMatriz* itemMatriz);

/**
 * Retorna o número de voos a partir do endereço do TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @return int número de voos do TAD item da matriz
 */
int getNumVoos(tadItemMatriz* itemMatriz);

/**
 * Retorna um ponteiro (início) da cadeia de caracteres que contém a hora de atualização do TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @return char hora de atualização do TAD item da matriz
 */
char* getHorarioAtualizacao(tadItemMatriz* itemMatriz);

/**
 * Seta a (tadListaVoo) lista encadeada de voos e retorna 0 caso tenha sucesso
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @param listaVoo cópia da lista encadeada de voos
 * @return int 0 caso tenha sucesso
 */
int setListaVoo(tadItemMatriz* itemMatriz, tadListaVoo listaVoo);

/**
 * Seta a informação (INT) número de voos do TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @param numVoos int numero de voos do TAD item da matriz
 * @return int 0 caso sucesso
 */
int setNumVoos(tadItemMatriz* itemMatriz, int numVoos);

/**
 * Seta a informação (CHAR) horário de atualização de voos do TAD item da matriz
 * @param itemMatriz Endereço para ED do TAD item da matriz
 * @param horaAtualizacao char hora de atualização do TAD item da matriz
 * @return int 0 caso sucesso
 */
int setHorarioAtualizacao(tadItemMatriz* itemMatriz, char horaAtualizacao[]);