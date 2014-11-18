#include "lista.h"
#include "sort.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void insertSort(Lista *l, int inicio, int fim) {
    if(inicio != fim) {
        insertSort(l, inicio, fim-1);
        No *nInicio = getNo(l, inicio), *nFim = getNo(l, fim);
        int newPos = buscaSeqNome(l, nFim->obj, nInicio, nFim->ant);
        listaInsere(l, listaRemove(l, fim), newPos);
    }
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
