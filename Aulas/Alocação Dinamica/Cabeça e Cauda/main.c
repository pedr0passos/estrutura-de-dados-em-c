#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int info;
    struct no *prox;
}NoLista;

typedef struct lista {
    NoLista *cab;
    NoLista *caud;
}Lista;

Lista cria_lista (Lista *l) {
    l->cab = (NoLista*)malloc(sizeof(NoLista));
    l->caud = (NoLista*)malloc(sizeof(NoLista));
    l->cab->prox = l->caud;
    l->caud->prox = NULL;
}

int esta_vazia (Lista *l) {
    if (l->cab->prox == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insere_item_cab (Lista *l, int v) {
    NoLista *n = malloc(sizeof(NoLista));
        n->info = v;
        n->prox = l->cab->prox;
        l->cab->prox = n;
}

void insere_item_caud (Lista *l, int v) {
    NoLista *n = malloc(sizeof(NoLista));
        n->info = v;
        n->prox = l->caud;
        for ( NoLista *p = l->cab->prox; p != n; p = p->prox) {
            if ( p->prox == l->caud ) {
                p->prox = n;
                break;
            }
        }
}

void remove_element (Lista *l, int v) {    
    if (!esta_vazia(l)){
        NoLista *p, *ant = l->cab;
        for ( p = l->cab->prox ; p->info != v ;p = p->prox){
            ant = p;
        }
            if (ant->info == v){
                l->cab->prox = p->prox;
            } else {
                ant->prox = p->prox;
            }
        free(p);
    }
}

void liberar (Lista *l) {
    for (NoLista *p = l->cab->prox; p->prox != NULL; p=p->prox){
        free(p);
    }
    l->cab = malloc(sizeof(NoLista));
    l->caud = malloc (sizeof(NoLista));
    l->cab->prox = l->caud;
    l->caud->prox = NULL;
    printf("Lista Vazia!");
}

void imprime (Lista *l) {
        NoLista *p;
        if ( !esta_vazia(l)) {
        for ( p = l->cab->prox; p != l->caud; p = p->prox) {
            printf("%d\n", p->info);
        }
    }
}


int main () {
setlocale(LC_ALL,"portuguese");
Lista lista;

cria_lista(&lista);
insere_item_cab(&lista, 1);
insere_item_cab(&lista, 2);
insere_item_cab(&lista, 3);
printf("\n\n------LISTA------\n\n");
imprime(&lista);
printf("\n\n------LISTA COM ITEM NO FINAL------\n\n");
insere_item_caud(&lista, 0);
insere_item_caud(&lista, -1);
insere_item_caud(&lista, -2);
imprime(&lista);
printf("\n\n------REMOVENDO ITENS 2 E -2------\n\n");
remove_element(&lista, 2);
remove_element(&lista, -2);
imprime(&lista);
printf("\n\n------LIMPANDO LISTA------\n\n");
liberar(&lista);
imprime(&lista);
return 0;
}