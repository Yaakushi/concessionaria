#include "lista.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Lista *l = listaInicia();
    if(!l) return 1;
    Carro carros[6];
    int i;
    carros[0].nome = "Zafira";
    carros[1].nome = "Sem carro";
    carros[2].nome = "Bubina";
    carros[3].nome = "Caminhoneta";
    carros[4].nome = "Caminhonete";
    carros[5].nome = "Maverick";
    for(i = 0; i < 6; i++) {
        listaInsere(l, &(carros[i]), 1);
        printf("%s - ", carros[i].nome);
    } printf("\n");
    insertSort(l, l->primeiro, l->ultimo);
    for(i = 0; i < 6; i++) printf("%d. %s\n", i, listaRemove(l, 1)->nome);
}
