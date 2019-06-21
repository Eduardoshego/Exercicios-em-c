#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;
struct fila
{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}
void fila_insere(Fila *f, int v)
{
    Lista *n = (Lista *)malloc(sizeof(Lista));
    n->info = v;        //armazena informação
    n->prox = NULL;     //novo nó passa a ser o último
    if (f->fim != NULL) //verifica se a lista não estava vazia
        f->fim->prox = n;
    else //fila estava vazia
        f->ini = n;
    f->fim = n; //fila aponta para novo elemento
}

int fila_retira(Fila *f)
{
    Lista *t;
    int v;
    if (fila_vazia(f))
    {
        printf("Fila vazia. \n");
        exit(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(t);
    return v;
}

int fila_vazia(Fila *f)
{
    return (f->ini == NULL);
}

void fila_libera(Fila *f)
{
    Lista *q = f->ini;
    while (q != NULL)
    {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}
void fila_imprime(Fila *f)
{
    Lista *q;
    for (q = f->ini; q != NULL; q = q->prox)
        printf("%d\n", q->info);
}

void main(){
    Fila *f;
    fila_cria();
    fila_insere(f,12);
    fila_insere(f,12);
    fila_insere(f,12);
    fila_insere(f,12);
    fila_insere(f,12);
    fila_insere(f,12);
    fila_retira(f);
    fila_imprime(f);

}