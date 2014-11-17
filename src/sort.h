#ifndef SORT_H_
#define SORT_H_ 
#include "lista.h"

void quickSort(Lista *l, No *inicio, No *fim);

void particiona(Lista *l, No *inicio, No *fim);

void mergeSort(Lista *l, No *inicio, No *fim);

void intercala(Lista *l, No *inicio, No *meio, No *fim);

void insertSort(Lista *l, No *inicio, No *fim);

void selectSort(Lista *l, No *inicio, No *fim);

int buscaSeqNome(Lista *l, Objeto *obj, No *inicio, No *fim);

int buscaSeqFabricante(Lista *l, Objeto *obj, No *inicio, No *fim);

int buscaSeqValor(Lista *l, Objeto *obj, No *inicio, No *fim);

No *minimo(Lista *l, No *inicio, No *fim);

void copia(Lista *l, No *destino, No *origem);

void inverte(Lista *l, No* x, No* y);

#endif
