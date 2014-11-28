#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "leitor.h"

int getValorFromStr(char *str) {
    if(!str) return 0;
    int i, valor = 0;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] != SEPARADOR_MILHAR) {
            char tmp[2];
            valor *= 10;
            sprintf(tmp, "%c", str[i]);
            valor += atoi(tmp);
        }
    }
    return valor;
}

void printNum(int num) {
    char str[5][4];
    int count = 0;
    while(num) {
        sprintf(str[count++], "%d", num % 1000); 
        num = num / 1000;
    }
    while(count) {
        printf("%s", str[--count]);
        if(count) printf(".");
    }
}

Carro *createCarro(char *input) {
    Carro *new = malloc(sizeof(Carro));
    if(!new) return NULL;
    new->nome = malloc(sizeof(char) * 40);
    new->marca = malloc(sizeof(char) * 40);
    if(!new->nome || !new->marca) {
        free(new);
        return 0;
    }
    char strvalor[20];
    sscanf(input, "%s %s %s", new->nome, new->marca, strvalor);
    new->preco = getValorFromStr(strvalor);
    return new;
}

Carro *leEntrada(int *size) {
    Carro *vetCarro = NULL;
    *size = 0;
    char input[100];
    while(fgets(input, 100, stdin) != NULL) {
        if(strlen(input)) {
            vetCarro = realloc(vetCarro, sizeof(Carro) * ++(*size));
            if(!vetCarro) return NULL;
            input[strlen(input) - 1] = '\0'; //Tira '\n'
            Carro *novo = createCarro(input);
            if(!novo) return NULL;
            vetCarro[(*size) - 1] = *novo;
        }
    }
    return vetCarro;
}

//int main() {
//    int size, i;
//    Carro *vetCar = leEntrada(&size);
//    for(i = 0; i < size; i++) {
//        printf("%s %s por R$%d.\n", vetCar[i].marca, vetCar[i].nome, vetCar[i].preco);
//    }
//}
