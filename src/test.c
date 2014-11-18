#include "lista.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARNUM 10

int main() {
    Lista *l = listaInicia();
    if(!l) return 1;
    Carro carros[CARNUM];
    int i;
    for(i = 0; i < CARNUM; i++) {
        carros[i].nome = malloc(sizeof(char) * 100);
        scanf("%s", carros[i].nome);
    }
    for(i = 0; i < CARNUM; i++) {
        listaInsere(l, &(carros[i]), 1);
        printf("%s - ", carros[i].nome);
    } printf("%d\n", l->tamanho);
    insertSort(l, 1, l->tamanho);
    for(i = 0; i < CARNUM; i++) printf("%d. %s\n", i, listaRemove(l, 1)->nome);
}
