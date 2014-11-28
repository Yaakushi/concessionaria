#include <stdio.h>
#include "lista.h"
#include "sort.h"
#include "leitor.h"

int main() {

    int vetSize, i;
    Carro *vetCar = leEntrada(&vetSize);
    if(!vetCar) {
        fputs("* Houve um erro na leiturada da entrada.\n", stderr);
        return 1;
    }

    printf("Ordenado por [Nome] utilizando [Selection Sort]\n");
    selectSort(vetCar, 0, vetSize-1);
    for(i = 0; i < vetSize; i++) {
        printf("%s %s ", vetCar[i].nome, vetCar[i].marca);
        printNum(vetCar[i].preco);
        printf("\n");
    }

    printf("\nOrdenado por [Marca] utilizando [Merge Sort]\n");
    mergeSort(vetCar, 0, vetSize-1);
    for(i = 0; i < vetSize; i++) {
        printf("%s %s ", vetCar[i].nome, vetCar[i].marca);
        printNum(vetCar[i].preco);
        printf("\n");
    }

    printf("\nOrdenado por [Valor] utilizando [Quick Sort]\n");
    quickSort(vetCar, 0, vetSize-1);
    for(i = 0; i < vetSize; i++) {
        printf("%s %s ", vetCar[i].nome, vetCar[i].marca);
        printNum(vetCar[i].preco);
        printf("\n");
    }

    Lista *lCar = listaInicia();
    if(!lCar) return 0;
    for(i = 0; i < vetSize; i++) {
        if(!listaInsere(lCar, &(vetCar[i]), 1)) {
            fputs("* Houve um erro na inserção na lista.\n", stderr);
            return 2;
        }
    }

    printf("\nOrdenado por [Nome] utilizando [Insert Sort] em lista encadeada\n");
    insertSort(lCar, 1, vetSize);
    for(i = 0; i < vetSize; i++) {
        Carro *aux = listaRemove(lCar, 1);
        printf("%s %s ", aux->nome, aux->marca);
        printNum(aux->preco);
        printf("\n");
    }
    return 0;
}
