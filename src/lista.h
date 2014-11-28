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

// listaInicia
// Tenta alocar uma lista na memória. Em caso de sucesso, inicia a lista e retorna um ponteiro para ela.
// Em caso de falha, retorna NULL.
Lista *listaInicia();

// listaInsere
// Tenta criar e inserir um novo nó na lista, na posição indicada (1 = inicio, tamanho+1 = final).
// Retorna 1 caso haja sucesso, 0 em caso de falha.
int listaInsere(Lista *l, Objeto obj, int pos);

// listaRemove
// Tenta remover o nó específico da lista. Retorna o objeto do nó caso sucedido, NULL caso contrário.
Objeto listaRemove(Lista *l, int pos);

// listaVazia
// Retorna 1 caso a lista esteja vazia, 0 caso contário.
int listaVazia(Lista *l);

// listaDestroi
// Desaloca todos os nós da lista, e em segui,da a lista propriamente dita.
void listaDestroi(Lista *l);

// posicaoNo
// Retorna o "índice" do nó especificado. Retorna tamanho + 1 caso o nó não exista.
int posicaoNo(Lista *l, No *no);

// getNo
// Retorna o nó especificado pelo "índice". Retorna NULL caso o índice seja inválido.
No *getNo(Lista *l, int pos);

#endif
