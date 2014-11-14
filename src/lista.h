typedef struct No {
    void *obj; // Ponteiro para o objeto do no
    struct No *prox, *ant; // Ponteiro para os nos adja
} No;

typedef struct {
    No *primeiro, *ultimo;
    int tamanho;
} Lista;

Lista *listaInicia();

int listaInsere(Lista *l, void *obj, int pos);

void *listaRemove(Lista *l, int pos);

int listaVazia(Lista *l);

void listaDestroi(Lista *l);
