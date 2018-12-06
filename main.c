#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tadMatrizDeVoo.h"

int geraVID();
void selecionaModo();
void modoInterativo();
void modoArquivo();
int escolhaCenario();

int geraVID() {
    return (0 + rand() % (100 + 1 - 0));
}

void selecionaModo() {
    int sair = 0, modo;
    printf("----------------------------------------------------------");
    printf("\n|            SISTEMA DE ORDENAÇÃO DE VOOS v1.0           |\n");
    printf("----------------------------------------------------------\n");
    while (sair == 0) {
        printf("Selecione uma das opções para iniciarmos: \n1 - Modo Interativo\n2 - Modo Arquivo\n0 - Sair\nDigite sua opção: ");
        scanf("%d", &modo);
        switch (modo) {
            case 1:
                modoInterativo();
                break;
            case 2:
                modoArquivo();
                break;
            case 0:
                sair = 1;
                break;
            default:
                printf("Inválido!\n");
                selecionaModo();
                break;
        }
    }
}

void modoInterativo() {
    int voltar = 0, opcao, tamVet, div, qtdVoos, *v;
    tadMatrizDeVoo *vet, *aux;
    tadVoo voo;
    inicializa(&voo);
    while (voltar == 0) {
        opcao = escolhaCenario();
        switch (opcao) {
            case 0:
                exit(0);
                break;
            case 1:
                tamVet = 365;
                div = tamVet * 0.2;
                qtdVoos = 10;
                break;
            case 2:
                tamVet = 365;
                div = tamVet;
                qtdVoos = 10;
                break;
            case 3:
                tamVet = 365;
                div = tamVet * 0.2;
                qtdVoos = 100;
                break;
            case 4:
                tamVet = 365;
                div = tamVet;
                qtdVoos = 100;
                break;
            case 5:
                tamVet = 3650;
                div = tamVet * 0.2;
                qtdVoos = 10;
                break;
            case 6:
                tamVet = 3650;
                div = tamVet;
                qtdVoos = 10;
                break;
            case 7:
                tamVet = 3650;
                div = tamVet * 0.2;
                qtdVoos = 100;
                break;
            case 8:
                tamVet = 3650;
                div = tamVet;
                qtdVoos = 100;
                break;
            case 9:
                tamVet = 36500;
                div = tamVet * 0.2;
                qtdVoos = 10;
                break;
            case 10:
                tamVet = 36500;
                div = tamVet;
                qtdVoos = 10;
                break;
            case 11:
                tamVet = 36500;
                div = tamVet * 0.2;
                qtdVoos = 100;
                break;
            case 12:
                tamVet = 36500;
                div = tamVet;
                qtdVoos = 100;
                break;
            case 13:
                selecionaModo();
                break;
            default:
                printf("Inválido!");
        }
        vet = (tadMatrizDeVoo *) malloc(tamVet * sizeof (tadMatrizDeVoo));
        aux = (tadMatrizDeVoo *) malloc(tamVet * sizeof (tadMatrizDeVoo));
        v = (int *) malloc((tamVet + 1) * sizeof (int));
        int erro;
        for (int i = 0; i < 3; i++) {
            inicializarTadMatrizDeVoo(&vet[i]);
            for (int j = 0; j < 3; j++) {
                geraVooAleatorio(&voo);
                printf("%d\n", getVid(&voo));
                printf("PISTA: %d\n", getPistaDecolagem(&voo));
                printf("AE DEC: %s\n", getAeroportoDecolagem(&voo));
                printf("AE POU: %s\n", getAeroportoPrevPouso(&voo));
                printf("HR DEC: %s\n", getHrDecolagem(&voo));
                printf("HR POU: %s\n", getHrPrevPouso(&voo));
//                insereVooMatriz(&vet[i], voo);
            }
        }
    }
}

void modoArquivo() {
    FILE *arq = NULL;
    char nomeArquivo[255];
    int i, j, pista, tamVet, div, qtdVoos, optAlg, numPista;
    char c, horaD[6], horaP[6], pistaD[4], pistaP[4];
    tadVoo voo;
    printf("Entre com o caminho e a extensão do arquivo: ");
    scanf(" %s", nomeArquivo);
    arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("%s nao existe.\nEntre com um caminho/arquivo válido!", nomeArquivo);
        modoArquivo();
        return 0;
    } else {
        tadMatrizDeVoo *vet, *aux;
        if(strcmp(nomeArquivo, "cenario1.txt") == 0){
            tamVet = 365;
            div = tamVet * 0.2;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario2.txt") == 0) {
            tamVet = 365;
            div = tamVet;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario3.txt") == 0) {
            tamVet = 365;
            div = tamVet*0.2;
            qtdVoos = 100;
        } else if(strcmp(nomeArquivo, "cenario4.txt") == 0) {
            tamVet = 365;
            div = tamVet;
            qtdVoos = 100;
        } else if(strcmp(nomeArquivo, "cenario5.txt") == 0) {
            tamVet = 3650;
            div = tamVet*0.2;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario6.txt") == 0) {
            tamVet = 3650;
            div = tamVet;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario7.txt") == 0) {
            tamVet = 3650;
            div = tamVet*0.2;
            qtdVoos = 100;
        } else if(strcmp(nomeArquivo, "cenario8.txt") == 0) {
            tamVet = 3650;
            div = tamVet;
            qtdVoos = 100;
        } else if(strcmp(nomeArquivo, "cenario9.txt") == 0) {
            tamVet = 36500;
            div = tamVet*0.2;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario10.txt") == 0) {
            tamVet = 36500;
            div = tamVet;
            qtdVoos = 10;
        } else if(strcmp(nomeArquivo, "cenario11.txt") == 0) {
            tamVet = 36500;
            div = tamVet*0;2;
            qtdVoos = 100;
        } else if(strcmp(nomeArquivo, "cenario12.txt") == 0) {
            tamVet = 36500;
            div = tamVet;
            qtdVoos = 100;
        }
        int vetor[div];
        for(i=0;i<div;i++){
            fscanf(arq, "%d", &vetor[i]);
        }
        vet = (tadMatrizDeVoo *) malloc(tamVet*sizeof(tadMatrizDeVoo));
        aux = (tadMatrizDeVoo *) malloc(tamVet*sizeof(tadMatrizDeVoo));
        for(i=0;i<div;i++){
            for(j=0;j<qtdVoos;j++){
                fscanf(arq, "%s", horaD);
                fscanf(arq, "%s", horaP);
                fscanf(arq, "%s", pistaD);
                fscanf(arq, "%s", pistaP);
                fscanf(arq, "%d", &numPista);
                printf("%s\n", horaD);
                setVid(&voo, geraVID());
                setHrDecolagem(&voo, horaD);
                setHrPrevPouso(&voo, horaP);
                setAeroportoDecolagem(&voo, pistaD);
                setAeroportoPrevPouso(&voo, pistaP);
                setPistaDecolagem(&voo, numPista);
                insereVooMatriz(&vet[vetor[i]], voo);
            }
            aux[i] = vet[i];
        }
    }
    fclose(arq);
}

int escolhaCenario() {
    int opt;
    printf("Escolha um dos 12 cenários: ");
    scanf("%d", &opt);
    return opt;
}

int main() {
    srand(time(NULL));
    selecionaModo();
}