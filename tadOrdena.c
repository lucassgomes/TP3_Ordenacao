#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tadOrdena.h"

void bubble_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, troca, Comp = 0, Mov = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    tadMatrizDeVoo Aux;
    TempInicial = clock();
    for (i = 0; i < tamVet - 1; i++) {
        troca = 0;
        for (j = i; j < tamVet - 1; j++) {
            Comp++;
            if (vet[i].ID > vet[j].ID) {
                Aux = vet[j];
                vet[j] = vet[i];
                vet[i] = Aux;
                Mov += 3;
                troca = 1;
            }
        }
        if (troca = 0) {
            break;
        }
    }
    for (i = 0; i < tamVet - 1; i++) {
        printf("%d\n", vet[i].ID);
    }
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}

void selection_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, min, Comp = 0, Mov = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    tadMatrizDeVoo aux;
    TempInicial = clock();
    for (i = 0; i < (tamVet - 1); i++) {
        min = i;
        for (j = (i + 1); j < tamVet; j++) {
            Comp++;
            if (vet[j].ID > vet[min].ID) {
                min = j;
            }
        }
        if (vet[i].ID != vet[min].ID) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            Mov += 3;
        }
    }
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}

void insertion_sort(tadMatrizDeVoo *vet, int tamVet) {
    int i, j, Comp = 0, Mov = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    tadMatrizDeVoo escolhido;
    TempInicial = clock();
    for (i = 1; i < tamVet; i++) {
        escolhido = vet[i];
        Mov++;
        j = i - 1;
        Comp++;
        while ((j >= 0) && (vet[j].ID < escolhido.ID)) {
            vet[j + 1] = vet[j];
            Mov++;
            j--;
            Comp++;
        }
        vet[j + 1] = escolhido;
        Mov++;
    }
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}

void shell_sort(tadMatrizDeVoo *vet, int n) {
    int i, j, Comp = 0, Mov = 0;
    int h = 1;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    tadMatrizDeVoo x;
    do {
        h = (h * 3) + 1;
    } while (h < n);
    TempInicial = clock();
    do {
        h = h / 3;
        for (i = h; i < n; i++) {
            x = vet[i];
            Mov++;
            j = i;
            Comp++;
            while (vet[j - h].ID > x.ID) {
                vet[j] = vet[j - h];
                Mov++;
                j -= h;
                if (j < h) {
                    break;
                }
                Comp++;
            }
            vet[j] = x;
            Mov++;
        }
    } while (h != 1);
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}

void Particao(int Esq, int Dir, int *i, int *j, tadMatrizDeVoo *vet, int *Comp, int *Mov) {
    int pivo;
    tadMatrizDeVoo aux;
    *i = Esq;
    *j = Dir;
    pivo = vet[(*i + *j) / 2].ID;
    do {
        (*Comp)++;
        while (pivo > vet[*i].ID) {
            (*i)++;
            (*Comp)++;
        }
        (*Comp)++;
        while (pivo < vet[*j].ID) {
            (*j)--;
            (*Comp)++;
        }
        if (*i <= *j) {
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*Mov) += 3;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, tadMatrizDeVoo *vet, int *Comp, int *Mov) {
    int i, j;
    Particao(Esq, Dir, &i, &j, vet, Comp, Mov);
    if (Esq < j) {
        Ordena(Esq, j, vet, Comp, Mov);
    }
    if (i < Dir) {
        Ordena(i, Dir, vet, Comp, Mov);
    }
}

void quick_sort(tadMatrizDeVoo *vet, int n) {
    int Comp = 0, Mov = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    TempInicial = clock();
    Ordena(0, n - 1, vet, &Comp, &Mov);
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}

void troca(tadMatrizDeVoo *vetA, tadMatrizDeVoo * vetB) {
    tadMatrizDeVoo temp = *vetA;
    *vetA = *vetB;
    *vetB = temp;
}

void heapify(tadMatrizDeVoo *vet, int n, int i, int *Mov, int *Comp) {
    int Maior = i;
    int Esq = 2 * i + 1;
    int Dir = 2 * i + 2;
    (*Comp)++;
    if ((Esq < n) && (vet[Esq].ID > vet[Maior].ID)) {
        Maior = Esq;
    }
    (*Comp)++;
    if ((Dir < n) && (vet[Dir].ID > vet[Maior].ID)) {
        Maior = Dir;
    }
    if (Maior != i) {
        troca(&vet[i], &vet[Maior]);
        (*Mov) += 3;
        heapify(vet, n, Maior, Mov, Comp);
    }
}

void heap_sort(tadMatrizDeVoo *vet, int n) {
    int i, Mov = 0, Comp = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    TempInicial = clock();
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(vet, n, i, &Mov, &Comp);
    }
    for (i = n - 1; i >= 0; i--) {
        troca(&vet[0], &vet[i]);
        Mov += 3;
        heapify(vet, i, 0, &Mov, &Comp);
    }
    TempFinal = clock();
    Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
    printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
    printf("------------------------------------------------------------------------------\n\n");
}