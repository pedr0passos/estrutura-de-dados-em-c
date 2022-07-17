#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int info;
    struct no *prox;
}NoLista;

NoLista *criarLista () {
    return NULL;
}

int estaVazia (NoLista *l) {
    return (l == NULL);
}

void insereItem (NoLista **l, int v) {
    NoLista *n = malloc(sizeof(NoLista));
    if ( n != NULL ) {
        n->info = v;
        n->prox = *l;
        *l = n;
    } else {
        printf("Não foi possível alocar espaço na memória!");
    }
}

void imprime (NoLista **l) {
    if (!estaVazia(l)) {
        NoLista *p;
        for (p =*l; p!=NULL; p = p->prox) {
            printf("%d\n", p->info);
        }
    } else {
        printf("Não foi possível imprimir!");
    }
}

int main () {

setlocale (LC_ALL, "portuguese");

    NoLista *lista;
    lista = criarLista();

    insereItem(&lista, 1);
    insereItem(&lista, 7);
    insereItem(&lista, 2);

    imprime (&lista);
    
return 0;
}