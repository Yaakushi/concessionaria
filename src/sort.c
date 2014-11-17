#include "lista.h"
#include "sort.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void insertSort(Lista *l, No *inicio, No *fim) {
    if(inicio != fim) {
        insertSort(l, inicio, fim->ant);
        int newPos = buscaSeqNome(l, fim->obj, inicio, fim->ant);
        int oldPos = posicaoNo(l, fim);
        No *aux = inicio;
        printf("[%d -> %d] ", oldPos, newPos);
        while(aux != NULL) {
            printf("%s - ", aux->obj->nome);
            aux = aux->prox;
        }
        printf("\n");
        listaInsere(l, listaRemove(l, oldPos), newPos);
    }
    //fim->prox = aux->prox;
    //if(fim != aux) {
    //    fim->ant = aux;
    //    aux->prox = fim;
    //}
    //if(aux->prox) aux->prox->ant = fim;
    //if(fim->ant) fim->ant->prox = fim->prox;
    //if(fim->prox) fim->prox->ant = fim->ant;
}

int buscaSeqNome(Lista *l, Objeto *obj, No *inicio, No *fim) {
    int pos = posicaoNo(l, inicio);
    No *aux = inicio;
    while(aux != fim->prox && strcmp(obj->nome, aux->obj->nome) == -1) {
        pos++;
        aux = aux->prox;
    }
    return pos;
}
