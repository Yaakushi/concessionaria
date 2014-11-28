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

int listaInsere(Lista *l, Objeto obj, int pos) {
    if(!l || pos < 1 || pos > l->tamanho+1) return 0;
    No *novo = malloc(sizeof(No));
    if(!novo) return 0;
    novo->obj = obj;
    if(pos == 1) {
        if(l->tamanho == 0) l->ultimo = novo;
        else l->primeiro->ant = novo;
        novo->prox = l->primeiro;
        novo->ant = NULL;
        l->primeiro = novo;
    } else if(pos == l->tamanho+1) {
        if(l->tamanho == 0) l->primeiro = novo;
        else l->ultimo->prox = novo;
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

Objeto listaRemove(Lista *l, int pos) {
    if(!l || pos < 1 || pos > l->tamanho) return NULL;
    int i;
    No *aux = l->primeiro;
    for(i = 1; i < pos; i++) aux = aux->prox;
    if(aux->ant) aux->ant->prox = aux->prox;
    else l->primeiro = aux->prox;
    if(aux->prox) aux->prox->ant = aux->ant;
    else l->ultimo = aux->ant;
    Carro *obj = aux->obj;
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

int posicaoNo(Lista *l, No *no) {
    int pos;
    No *aux = l->primeiro;
    for(pos = 1; aux != no; pos++) {
        if(aux->prox == NULL) return l->tamanho + 1;
        else aux = aux->prox;
    }
    return pos;
}

No *getNo(Lista *l, int pos) {
    if(pos < 1 || pos > l->tamanho) return NULL;
    int i;
    No *aux = l->primeiro;
    for(i = 1; i < pos; i++) aux = aux->prox;
    return aux;
}
