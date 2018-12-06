#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tadOrdena.h"

void bubble_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, troca, comp = 0, mov = 0;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tadMatrizDeVoo Aux;
    tempoInicial = clock();
    for (i = 0; i < tamVet - 1; i++) {
        troca = 0;
        for (j = i; j < tamVet - 1; j++) {
            comp++;
            if (vet[i].ID > vet[j].ID) {
                Aux = vet[j];
                vet[j] = vet[i];
                vet[i] = Aux;
                mov += 3;
                troca = 1;
            }
        }
        if (troca = 0) {
            break;
        }
    }
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}

void selection_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, min, comp = 0, mov = 0;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tadMatrizDeVoo aux;
    tempoInicial = clock();
    for (i = 0; i < (tamVet - 1); i++) {
        min = i;
        for (j = (i + 1); j < tamVet; j++) {
            comp++;
            if (vet[j].ID > vet[min].ID) {
                min = j;
            }
        }
        if (vet[i].ID != vet[min].ID) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            mov += 3;
        }
    }
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}

void insertion_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, comp = 0, mov = 0;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tadMatrizDeVoo escolhido;
    tempoInicial = clock();
    for (i = 1; i < tamVet; i++) {
        escolhido = vet[i];
        mov++;
        j = i - 1;
        comp++;
        while ((j >= 0) && (vet[j].ID < escolhido.ID)) {
            vet[j + 1] = vet[j];
            mov++;
            j--;
            comp++;
        }
        vet[j + 1] = escolhido;
        mov++;
    }
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}

void shell_sort(tadMatrizDeVoo *vet, int num) {
    int i, j, comp = 0, mov = 0;
    int h = 1;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tadMatrizDeVoo x;
    do {
        h = (h * 3) + 1;
    } while (h < num);
    tempoInicial = clock();
    do {
        h = h / 3;
        for (i = h; i < num; i++) {
            x = vet[i];
            mov++;
            j = i;
            comp++;
            while (vet[j - h].ID > x.ID) {
                vet[j] = vet[j - h];
                mov++;
                j -= h;
                if (j < h) {
                    break;
                }
                comp++;
            }
            vet[j] = x;
            mov++;
        }
    } while (h != 1);
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}

void Particao(int esq, int dir, int *i, int *j, tadMatrizDeVoo *vet, int *comp, int *mov) {
    int pivo;
    tadMatrizDeVoo aux;
    *i = esq;
    *j = dir;
    pivo = vet[(*i + *j) / 2].ID;
    do {
        (*comp)++;
        while (pivo > vet[*i].ID) {
            (*i)++;
            (*comp)++;
        }
        (*comp)++;
        while (pivo < vet[*j].ID) {
            (*j)--;
            (*comp)++;
        }
        if (*i <= *j) {
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*mov) += 3;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int esq, int dir, tadMatrizDeVoo *vet, int *comp, int *mov) {
    int i, j;
    Particao(esq, dir, &i, &j, vet, comp, mov);
    if (esq < j) {
        Ordena(esq, j, vet, comp, mov);
    }
    if (i < dir) {
        Ordena(i, dir, vet, comp, mov);
    }
}

void quick_sort(tadMatrizDeVoo *vet, int n) {
    int comp = 0, mov = 0;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tempoInicial = clock();
    Ordena(0, n - 1, vet, &comp, &mov);
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}

void troca(tadMatrizDeVoo *vetA, tadMatrizDeVoo * vetB) {
    tadMatrizDeVoo temp = *vetA;
    *vetA = *vetB;
    *vetB = temp;
}

void heap_construct(tadMatrizDeVoo *vet, int n, int i, int *mov, int *comp) {
    int Maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    (*comp)++;
    if ((esq < n) && (vet[esq].ID > vet[Maior].ID)) {
        Maior = esq;
    }
    (*comp)++;
    if ((dir < n) && (vet[dir].ID > vet[Maior].ID)) {
        Maior = dir;
    }
    if (Maior != i) {
        troca(&vet[i], &vet[Maior]);
        (*mov) += 3;
        heap_construct(vet, n, Maior, mov, comp);
    }
}

void heap_sort(tadMatrizDeVoo *vet, int n) {
    int i, mov = 0, comp = 0;
    clock_t tempoFinal, tempoInicial;
    double tempoms;
    tempoInicial = clock();
    for (i = n / 2 - 1; i >= 0; i--) {
        heap_construct(vet, n, i, &mov, &comp);
    }
    for (i = n - 1; i >= 0; i--) {
        troca(&vet[0], &vet[i]);
        mov += 3;
        heap_construct(vet, i, 0, &mov, &comp);
    }
    tempoFinal = clock();
    tempoms = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("------------------            RESULTADO          -----------------------------\n");
    printf("movimentacoes: %d\ncomparacoes: %d\nTempo gasto: %lf ms\n", mov, comp, tempoms);
    printf("------------------------------------------------------------------------------\n");
}