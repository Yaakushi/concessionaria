#ifndef SORT_H_
#define SORT_H_ 

//Importando pelo tipo Carro
#include "lista.h"

//void quickSort(Carro *vet, int inicio, int fim);

//void particiona(Carro *vet, int inicio, int fim);

void mergeSort(Carro *vet, int inicio, int fim);

void intercala(Carro *vet, int inicio, int fim);

// Copia o vetor "src" (de tamanho "length") para "dest" (a partir do indice "inicio").
void copiaVetor(Carro *dest, int inicio, Carro *src, int length);

void insertSort(Lista *l, int inicio, int fim);

// Select sort em lista duplamente encadeada.
void selectSort(Carro *vet, int inicio, int fim);

// Busca sequencial por nome.
int buscaSeqNome(Lista *l, Objeto obj, No *inicio, No *fim);

// Retorna o índice do elemento com o "menor" nome (lexicamente).
int minimoNome(Carro *vet, int inicio, int fim);

//void copia(Carro *vet, int destino, int origem);

// Troca a posição de vet[x] com vet[y].
void troca(Carro *vet, int x, int y);

#endif
