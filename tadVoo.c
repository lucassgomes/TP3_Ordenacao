#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadVoo.h"

/**
 * Inicializa o TADVoo com valores 0 em campos INT e valores NULL('\0') em campos char
 * @param voo Endereço do Voo
 */
void inicializa(tadVoo* voo){
    voo->vid = 0;
    voo->hrDecolagem[0] = '\0';
    voo->hrPrevPouso[0] = '\0';
    voo->aeroportoDecolagem[0] = '\0';
    voo->aeroportoPrevPouso[0] = '\0';
    voo->pistaDecolagem = 0;
}

/**
 * Função de retorno de VID de Voo
 * @param voo Endereço do Voo
 * @return int VID do voo
 */
int getVid(tadVoo* voo){
    return voo->vid;
}

/**
 * Retorna um ponteiro (início) da cadeia de caracteres que contém a hora de decolagem do Voo
 * @param voo Endereço do Voo
 * @return char hrDecolagem do voo
 */
char* getHrDecolagem(tadVoo* voo){
    return voo->hrDecolagem;
}

/**
 * Retorna um ponteiro (início) da cadeia de caracteres que contém a hora prevista de pouso do Voo
 * @param voo Endereço do Voo
 * @return char hrPrevPouso do voo
 */
char* getHrPrevPouso(tadVoo* voo){
    return voo->hrPrevPouso;
}

/**
 * Retorna um ponteiro (início) da cadeia de caracteres que contém o aeroporto de decolagem do Voo
 * @param voo Endereço do Voo
 * @return aeroportoDecolagem de voo
 */
char* getAeroportoDecolagem(tadVoo* voo){
    return voo->aeroportoDecolagem;
}

/**
 * Retorna um ponteiro (início) da cadeia de caracteres que contém o aeroporto previsto de pouso do Voo
 * @param voo Endereço do Voo
 * @return aeroportoPrevPouso de voo
 */
char* getAeroportoPrevPouso(tadVoo* voo){
    return voo->aeroportoPrevPouso;
}

/**
 * Retorna um INT contendo o número da pista de decolagem do Voo
 * @param voo Endereço do Voo
 * @return int pistaDecolagem do voo
 */
int getPistaDecolagem(tadVoo* voo){
    return voo->pistaDecolagem;
}

/**
 * Seta a informação(INT) VID do Voo recebida como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param vid VID a ser inserido
 * @return int 0 caso sucesso
 */
int setVid(tadVoo* voo, int vid){
    voo->vid = vid;
    return 0;
}

/**
 * Seta a informação (CHAR) hora de decolagem como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param hrDecolagem String de hora de decolagem a ser inserida
 * @return int 0 caso sucesso
 */
int setHrDecolagem(tadVoo* voo, char hrDecolagem[]){
    strcpy(voo->hrDecolagem, hrDecolagem);
    return 0;
}

/**
 * Seta a informação (CHAR) hora prevista de pouso como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param hrPrevPouso String de hora de previsão depouso a ser inserida
 * @return int 0 caso sucesso
 */
int setHrPrevPouso(tadVoo* voo, char hrPrevPouso[]){
    strcpy(voo->hrPrevPouso, hrPrevPouso);
    return 0;
}

/**
 * Seta a informação (CHAR) aeroporto de decolagem como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param aeroportoDecolagem String de aeroporto de decolagem a ser inserido
 * @return int 0 caso sucesso
 */
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]){
    strcpy(voo->aeroportoDecolagem, aeroportoDecolagem);
    return 0;
}

/**
 * Seta a informação (CHAR) aeroporto previsto de pousco como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param aeroportoPrevPouso String de aeroporto de previsão de pouso a ser inserido
 * @return int 0 caso sucesso
 */
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]){
    strcpy(voo->aeroportoPrevPouso, aeroportoPrevPouso);
    return 0;
}

/**
 * Seta a informação(INT) pista de decolagem do Voo recebida como parâmetro e retorna 0 caso execute a operação com sucesso
 * @param voo Endereço do Voo
 * @param pistaDecolagem Pista de decolagem a ser inserida
 * @return int 0 caso sucesso
 */
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem){
    voo->pistaDecolagem = pistaDecolagem;
    return 0;
}