#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadMatrizDeVoo.h"
#include <string.h>
#define TAMMATRIZ 24
#define TAMCHAR 6

/**
 * Inicializa a ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void inicializarTadMatrizDeVoo(tadMatrizDeVoo* matrizDeVoo) {
    matrizDeVoo->ID = 0;
    for (int k = 0; k < TAMMATRIZ; k++) {
        for (int l = 0; l < TAMMATRIZ; l++) {
            inicializarTadItemMatriz(&(matrizDeVoo->matrizVoos[k][l]));
        }
    }
    matrizDeVoo->numTotVoos = 0;
    strcpy(matrizDeVoo->atualizacaoHorario, __TIME__);
    strcpy(matrizDeVoo->data, __DATE__);
}

void geraVooAleatorio(tadVoo *voo) {
    int i, hr, min, letras;
    char horaD[6], horaP[6], pistaD[4], pistaP[4];
    setVid(voo, rand() % 40000);
    setPistaDecolagem(voo, rand() % 50);
    hr = (rand() % (0 - 23) + 0);
    min = (rand() % (0 - 59) + 0);
    if (min < 10) {
        sprintf(horaD, "%d:0%d", hr, min);
    } else {
        sprintf(horaD, "%d:%d", hr, min);
    }
    setHrDecolagem(voo, horaD);
    hr = (rand() % (0 - 23) + 0);
    min = (rand() % (0 - 59) + 0);
    if (min < 10) {
        sprintf(horaP, "%d:0%d", hr, min);
    } else {
        sprintf(horaP, "%d:%d", hr, min);
    }
    setHrPrevPouso(voo, horaP);
    for (i = 0; i < 3; i++) {
        letras = (65 + rand() % (91-65));
        pistaD[i] = (char) letras;
    }
    setAeroportoDecolagem(voo, pistaD);
    for (i = 0; i < 3; i++) {
        letras = (65 + rand() % (91-65));
        pistaP[i] = (char) letras;
    }
    setAeroportoPrevPouso(voo, pistaP);
//    printf("%d\n", getVid(voo));
//    printf("PISTA: %d\n", getPistaDecolagem(voo));
//    printf("AE DEC: %s\n", getAeroportoDecolagem(voo));
//    printf("AE POU: %s\n", getAeroportoPrevPouso(voo));
//    printf("HR DEC: %s\n", getHrDecolagem(voo));
//    printf("HR POU: %s\n", getHrPrevPouso(voo));
}

/**
 * Insere um voo na matriz de voos a partir de uma cópia do TAD voo e um endereço para ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param voo cópia do TAD voo com as informações a serem inseridas
 * @return int 0 caso sucesso
 */
int insereVooMatriz(tadMatrizDeVoo* matrizDeVoo, tadVoo voo) {
    int horaDecolagem, horaPrevPouso;
    tadListaVoo listaVoo;
    char hrD[TAMCHAR];
    char hrP[TAMCHAR];
    strcpy(hrD, voo.hrDecolagem);
    strcpy(hrP, voo.hrPrevPouso);
    horaDecolagem = converteHoras(hrD);
    horaPrevPouso = converteHoras(hrP);
    listaVoo = getListaVoo(&matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso]);
    insereVoo(&listaVoo, voo);
    matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso].listaVoo = listaVoo;
    matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso].numVoos++;
    matrizDeVoo->numTotVoos++;
    strcpy(matrizDeVoo->atualizacaoHorario, __TIME__);
    setHorarioAtualizacao(&matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso], __TIME__);
    return 0;
}

/**
 * Procura um voo na matriz de voos a partir de um identificador (VID) e coloca em um TAD voo
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param vid int Identificador do voo
 * @param voo Endereço para o TAD Voo
 * @return int 0 caso sucesso
 */
int removeVooMatriz(tadMatrizDeVoo* matrizDeVoo, int vid) {
    tadVoo voo;
    int erro;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (!vazia(matrizDeVoo->matrizVoos[i][j].listaVoo)) {
                erro = retornaVoo(&(matrizDeVoo->matrizVoos[i][j].listaVoo), vid, &voo);
                if (erro) {
                    strcpy(matrizDeVoo->matrizVoos[i][j].horarioAtualizacao, __TIME__);
                    strcpy(matrizDeVoo->atualizacaoHorario, __TIME__);
                    matrizDeVoo->matrizVoos[i][j].numVoos--;
                    matrizDeVoo->numTotVoos--;
                    return 0;
                }
            }
        }
    }
    return 1;
}

/**
 * Remove um voo da matriz de voos a partir de um identificador (VID)
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param vid int Identificador do voo
 * @return int 0 caso sucesso
 */
int procuraVooMatriz(tadMatrizDeVoo* matrizDeVoo, int vid, tadVoo* voo) {
    int erro;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (!vazia(matrizDeVoo->matrizVoos[i][j].listaVoo)) {
                erro = procuraVoo(&(matrizDeVoo->matrizVoos[i][j].listaVoo), vid, voo);
                if (erro) {
                    printf("\nVoo %d encontrado: \n", vid);
                    imprimeGets(voo);
                    printf("\n\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}

/**
 * Imprime os voos que contenham a hora de decolagem(HORA) e a hora de previsão de pouso(HORA) exatamente iguais as que foram passadas como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrDecolagem char hora de decolagem do voo
 * @param hrPrevPouso char hora de previsão de pouso do voo
 */
void imprimeVoosHrDHrP(tadMatrizDeVoo* matrizDeVoo, char hrDecolagem[], char hrPrevPouso[]) {
    int horaDecolagem, horaPrevPouso;
    tadListaVoo listaVoo;
    horaDecolagem = converteHoras(hrDecolagem);
    horaPrevPouso = converteHoras(hrPrevPouso);
    listaVoo = getListaVoo(&matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso]);
    imprimeVoo(listaVoo);
}

/**
 * Imprime os voos que contenham a hora de decolagem(HORA) exatamente igual a que foi passada como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrDecolagem char hora de decolagem do voo
 */
void imprimeVoosHrD(tadMatrizDeVoo* matrizDeVoo, char hrDecolagem[]) {
    int horaDecolagem;
    tadListaVoo listaVoo;
    horaDecolagem = converteHoras(hrDecolagem);
    for (int i = 0; i < TAMMATRIZ; i++) {
        listaVoo = getListaVoo(&matrizDeVoo->matrizVoos[horaDecolagem][i]);
        imprimeVoo(listaVoo);
    }
}

/**
 * Imprime os voos que contenham a hora de previsão de pouso(HORA) exatamente igual a que foi passada como parâmetro
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @param hrPrevPouso char hora de previsão de pouso do voo
 */
void imprimeVoosHrP(tadMatrizDeVoo* matrizDeVoo, char hrPrevPouso[]) {
    int horaPrevPouso;
    tadListaVoo listaVoo;
    horaPrevPouso = converteHoras(hrPrevPouso);
    for (int i = 0; i < TAMMATRIZ; i++) {
        listaVoo = getListaVoo(&matrizDeVoo->matrizVoos[i][horaPrevPouso]);
        imprimeVoo(listaVoo);
    }
}

/**
 * Imprime toda a matriz de voos a partir do endereço da ED do TAD matriz de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void imprimeMatriz(tadMatrizDeVoo* matrizDeVoo) {
    tadListaVoo listaVoo;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            listaVoo = getListaVoo(&matrizDeVoo->matrizVoos[i][j]);
            imprimeVoo(listaVoo);
        }
    }
}

/**
 * Imprime os índices e a quantidade de voos da matriz com maior número de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void maiorNumVoos(tadMatrizDeVoo* matrizDeVoo) {
    int maior;
    int l = 0, c = 0;
    maior = matrizDeVoo->matrizVoos[0][0].numVoos;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (matrizDeVoo->matrizVoos[i][j].numVoos > maior) {
                maior = matrizDeVoo->matrizVoos[i][j].numVoos;
                l = i;
                c = j;
            }
        }
    }
    printf("Indices da posição encontrada: i=%d, j=%d e qtd = %d\n", l, c, maior);
}

/**
 * Imprime os índices e a quantidade de voos da matriz com menor número de voos
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void menorNumVoos(tadMatrizDeVoo* matrizDeVoo) {
    int menor;
    int l = 0, c = 0;
    menor = matrizDeVoo->matrizVoos[0][0].numVoos;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (matrizDeVoo->matrizVoos[i][j].numVoos < menor) {
                menor = matrizDeVoo->matrizVoos[i][j].numVoos;
                l = i;
                c = j;
            }
        }
    }
    printf("Indices da posição encontrada: i=%d, j=%d e qtd = %d\n", l, c, menor);
}

/**
 * Imprime os índices e a hora de atualização da matriz alterada mais recentemente
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void lAlteradaRecente(tadMatrizDeVoo* matrizDeVoo) {
    tadMatrizDeVoo matrizLRAlterada;
    int l = 0, c = 0;
    char recente[9];
    strcpy(recente, matrizDeVoo->matrizVoos[l][c].horarioAtualizacao);
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (strcmp(matrizDeVoo->matrizVoos[i][j].horarioAtualizacao, recente) > 0) {
                strcpy(recente, matrizDeVoo->matrizVoos[i][j].horarioAtualizacao);
                l = i;
                c = j;
            }
        }
    }
    printf("Indices da posição encontrada: i=%d, j=%d e horário da última atualização = %s\n", l, c, recente);
}

/**
 * Imprime os índices e a hora de atualização da matriz alterada menos recentemente
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 */
void lAlteradaNRecente(tadMatrizDeVoo* matrizDeVoo) {
    tadMatrizDeVoo matrizLNRAlterada;
    int l = 0, c = 0;
    char nrecente[9];
    strcpy(nrecente, matrizDeVoo->matrizVoos[l][c].horarioAtualizacao);
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (strcmp(matrizDeVoo->matrizVoos[i][j].horarioAtualizacao, nrecente) < 0) {
                strcpy(nrecente, matrizDeVoo->matrizVoos[i][j].horarioAtualizacao);
                l = i;
                c = j;
            }
        }
    }
    printf("Indices da posição encontrada: i=%d, j=%d e horário da última atualização = %s\n", l, c, nrecente);
}

/**
 * Retorna 1 ou 0 para a afirmação da matriz ser esparça ou não
 * A matriz esparça é aquela que a quantidade de itens das matrizes vazias é igual ao dobro
 * da quantidade de itens das matrizes que tenham pelo menos 1 item
 * @param matrizDeVoo Endereço da ED do TAD matriz de voos
 * @return int 1 caso positivo ou 0 caso negativo
 */
int esparca(tadMatrizDeVoo* matrizDeVoo) {
    int numPosVazia = 0, numPos1Voo = 0;
    for (int i = 0; i < TAMMATRIZ; i++) {
        for (int j = 0; j < TAMMATRIZ; j++) {
            if (vazia(matrizDeVoo->matrizVoos[i][j].listaVoo)) {
                numPosVazia++;
            } else if (matrizDeVoo->matrizVoos[i][j].numVoos == 1) {
                numPos1Voo++;
            }
        }
    }
    if (numPosVazia == (2 * numPos1Voo)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Converte o campo horas de uma determinada cadeia de caracteres para inteiro
 * @param horario char hora a ser convertida
 * @return int resultado da conversão
 */
int converteHoras(char horario[]) {
    int horas;
    for (int i = 0; i < 6; i++) {
        horario[i] = horario[i] - 48;
    }
    horas = (horario[0] * 10) + horario[1];
    return horas;
}