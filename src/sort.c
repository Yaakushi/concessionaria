#include "lista.h"
#include "sort.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void mergeSort(Carro *vet, int inicio, int fim) {
    if(inicio >= fim) return;
    mergeSort(vet, inicio, (inicio + fim)/2);
    mergeSort(vet, (inicio + fim)/2 + 1, fim);
    intercala(vet, inicio, fim);
}

void intercala(Carro *vet, int inicio, int fim) {
    Carro *aux = malloc(sizeof(Carro) * (fim - inicio + 1));
    int meio = (inicio+fim)/2, i = inicio, j = meio + 1, cont = 0;
    while(cont < fim - inicio + 1) {
        if(i > meio) aux[cont] = vet[j++];
        else if(j > fim) aux[cont] = vet[i++];
        else if(strcmp(vet[i].marca, vet[j].marca) < 0) aux[cont] = vet[i++];
        else aux[cont] = vet[j++];
        cont++;
    }
    copiaVetor(vet, inicio, aux, cont);
}

void copiaVetor(Carro *dest, int inicio, Carro *src, int length) {
    int i;
    for(i = inicio; i < (inicio + length); i++) dest[i] = src[i - inicio];
}

void insertSort(Lista *l, int inicio, int fim) {
    if(inicio != fim) {
        insertSort(l, inicio, fim-1);
        No *nInicio = getNo(l, inicio), *nFim = getNo(l, fim);
        int newPos = buscaSeqNome(l, nFim->obj, nInicio, nFim->ant);
        listaInsere(l, listaRemove(l, fim), newPos);
    }
}

void selectSort(Carro *vet, int inicio, int fim) {
    if(inicio >= fim) return;
    int min = minimoNome(vet, inicio, fim);
    troca(vet, inicio, min);
    selectSort(vet, inicio+1, fim);
}

int buscaSeqNome(Lista *l, Objeto obj, No *inicio, No *fim) {
    int pos = posicaoNo(l, inicio);
    No *aux = inicio;
    while(aux != fim->prox && strcmp(obj->nome, aux->obj->nome) > 0) {
        pos++;
        aux = aux->prox;
    }
    return pos;
}

int minimoNome(Carro *vet, int inicio, int fim) {
    int min = inicio, i;
    for(i = inicio + 1; i <= fim; i++) {
        if(strcmp(vet[i].nome, vet[min].nome) < 0) min = i;
    }
    return min;
}

void troca(Carro *vet, int x, int y) {
    if(x == y) return;
    Carro aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}
