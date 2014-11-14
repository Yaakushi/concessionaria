#include <stdlib.h>
#include "lista.h"

Lista *listaInicia() {
    Lista *l = malloc(sizeof(Lista));
    if(!l) return NULL;
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanho = 0;
    return l;
}

int listaInsere(Lista *l, void *obj, int pos) {
    if(!l || pos < 1 || pos > l->tamanho+1) return 0;
    No *novo = malloc(sizeof(No));
    if(!novo) return 0;
    novo->obj = obj;
    if(pos == 1) {
        novo->prox = l->primeiro;
        novo->ant = NULL;
        l->primeiro = novo;
    } else if(pos == l->tamanho+1) {
        novo->prox = NULL;
        novo->ant = l->ultimo;
        l->ultimo = novo;
    } else {
        No *aux = l-> primeiro;
        int i;
        for(i = 1; i < pos-1; i++) aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
        novo->prox->ant = novo;
    }
    l->tamanho++;
    return 1;
}

void *listaRemove(Lista *l, int pos) {
    if(!l || pos < 1 || pos > l->tamanho) return 0;
    int i;
    No *aux = l->primeiro;
    for(i = 1; i < pos; i++) aux = aux->prox;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    void *obj = aux->obj;
    free(aux);
    l->tamanho--;
    return obj;
}

int listaVazia(Lista *l) {
    return (l->tamanho <= 0) ? 1 : 0;
}

void listaDestroi(Lista *l) {
    while(!listaVazia(l)) listaRemove(l, 1);
    free(l);
    return;
}
