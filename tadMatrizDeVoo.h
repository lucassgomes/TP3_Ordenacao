#include <stdio.h>
#include <stdlib.h>
#include "tadItemMatriz.h"
#define TAMMATRIZ 24

//ED do TAD matriz de voos
typedef struct {
    int ID;
    tadItemMatriz matrizVoos[TAMMATRIZ][TAMMATRIZ];
    char data[11];
    int numTotVoos;
    char atualizacaoHorario[9];
} tadMatrizDeVoo;

/**
 * Inicializa a ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void inicializarTadMatrizDeVoo(tadMatrizDeVoo* matrizDeVoo, int tamVet);

void geraVooAleatorio(tadVoo *voo);

void geraAeroporto(char *aeroporto);

int numAleatorio(int a, int b);
/**
 * Insere um voo na matriz de voos a partir de uma cópia do TAD voo e um endereço para ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param voo cópia do TAD voo com as informações a serem inseridas
 * @return int 0 caso sucesso
 */
int insereVooMatriz(tadMatrizDeVoo* matrizDeVoo, tadVoo voo);

/**
 * Procura um voo na matriz de voos a partir de um identificador (VID) e coloca em um TAD voo
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param vid int Identificador do voo
 * @param voo Endereço para o TAD Voo
 * @return int 0 caso sucesso
 */
int procuraVooMatriz(tadMatrizDeVoo* matrizDeVoo, int vid, tadVoo* voo);

/**
 * Remove um voo da matriz de voos a partir de um identificador (VID)
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param vid int Identificador do voo
 * @return int 0 caso sucesso
 */
int removeVooMatriz(tadMatrizDeVoo* matrizDeVoo, int vid);

/**
 * Imprime os voos que contenham a hora de decolagem(HORA) e a hora de previsão de pouso(HORA) exatamente iguais as que foram passadas como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrDecolagem char hora de decolagem do voo
 * @param hrPrevPouso char hora de previsão de pouso do voo
 */
void imprimeVoosHrDHrP(tadMatrizDeVoo* matrizDeVoo, char hrDecolagem[], char hrPrevPouso[]);

/**
 * Imprime os voos que contenham a hora de decolagem(HORA) exatamente igual a que foi passada como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrDecolagem char hora de decolagem do voo
 */
void imprimeVoosHrD(tadMatrizDeVoo* matrizDeVoo, char hrDecolagem[]);

/**
 * Imprime os voos que contenham a hora de previsão de pouso(HORA) exatamente igual a que foi passada como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrPrevPouso char hora de previsão de pouso do voo
 */
void imprimeVoosHrP(tadMatrizDeVoo* matrizDeVoo, char hrPrevPouso[]);

/**
 * Imprime toda a matriz de voos a partir do endereço da ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void imprimeMatriz(tadMatrizDeVoo* matrizDeVoo);

/**
 * Imprime os índices e a quantidade de voos da matriz com maior número de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void maiorNumVoos(tadMatrizDeVoo* matrizDeVoo);

/**
 * Imprime os índices e a quantidade de voos da matriz com menor número de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void menorNumVoos(tadMatrizDeVoo* matrizDeVoo);

/**
 * Imprime os índices e a hora de atualização da matriz alterada mais recentemente
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void lAlteradaRecente(tadMatrizDeVoo* matrizDeVoo);

/**
 * Imprime os índices e a hora de atualização da matriz alterada menos recentemente
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void lAlteradaNRecente(tadMatrizDeVoo* matrizDeVoo);

/**
 * Retorna 1 ou 0 para a afirmação da matriz ser esparça ou não
 * A matriz esparça é aquela que a quantidade de itens das matrizes vazias é igual ao dobro
 * da quantidade de itens das matrizes que tenham pelo menos 1 item
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @return int 1 caso positivo ou 0 caso negativo
 */
int esparca(tadMatrizDeVoo* matrizDeVoo);

/**
 * Converte o campo horas de uma determinada cadeia de caracteres para inteiro
 * @param horario char hora a ser convertida
 * @return int resultado da conversão
 */
int converteHoras(char horario[]);