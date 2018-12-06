#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tadMatrizDeVoo.h"

void bubble_sort(tadMatrizDeVoo *vet, int tamVet);
void selection_sort(tadMatrizDeVoo *vet, int tamVet);
void insertion_sort(tadMatrizDeVoo *vet, int tamVet);
void shell_sort(tadMatrizDeVoo *vet, int n);
void Particao(int Esq, int Dir, int *i, int *j, tadMatrizDeVoo *vet, int *Comp, int *Mov);
void Ordena(int Esq, int Dir, tadMatrizDeVoo *vet, int *Comp, int *Mov);
void quick_sort(tadMatrizDeVoo *vet, int n);
void troca(tadMatrizDeVoo *vetA, tadMatrizDeVoo *vetB);
void heapify(tadMatrizDeVoo *vet, int n, int i, int *Mov, int *Comp);
void heap_sort(tadMatrizDeVoo *vet, int n);