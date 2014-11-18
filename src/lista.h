#ifndef LISTA_H_
#define LISTA_H_

typedef struct {
    char *nome, *marca;
    int preco;
} Carro;

typedef Carro* Objeto;

typedef struct No {
    Objeto obj; // Ponteiro para o objeto do no
    struct No *prox, *ant; // Ponteiro para os nos adja
} No;

typedef struct {
    No *primeiro, *ultimo;
    int tamanho;
} Lista;


Lista *listaInicia();

int listaInsere(Lista *l, Objeto obj, int pos);

Objeto listaRemove(Lista *l, int pos);

int listaVazia(Lista *l);

void listaDestroi(Lista *l);

int posicaoNo(Lista *l, No *no);

No *getNo(Lista *l, int pos);

#endif
