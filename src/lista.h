typedef struct No {
    void *obj; // Ponteiro para o objeto do no
    struct No *prox, *ant; // Ponteiro para os nos adja
} No;

typedef struct {
    No *primeiro, *ultimo;
    int tamanho;
} Lista;

Lista *listaInicia();

int listaInsereHead(Lista *l, void *obj);

int listaInsereTail(Lista *l, void *obj);

int listaInsere(Lista *l, void *obj, int pos);

void *listaRemoveHead(Lista *l);

void *listaRemoveTail(Lista *l);

void *listaRemove(Lista *l);

int listaVazia(Lista *l);

void listraDestroi(Lista *l);
