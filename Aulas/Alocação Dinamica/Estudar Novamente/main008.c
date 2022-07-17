
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
}NoLista;

typedef struct descritor {
    NoLista *prim, *ult;
    int n;
}Descritor;

void criar_lista (Descritor *l) {
    l->prim = NULL;
    l->ult = NULL;
    l->n = 0;
}

int esta_vazia (Descritor *l) {
    if ( l->n == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

void insere_inicio ( Descritor *l, int v) {
    NoLista *n = malloc(sizeof(NoLista));
    if ( n!=NULL ) {
       n->info = v;
       n->prox = l->prim;
       l->prim = n;
       if ( esta_vazia(l)) {
           l->ult = n;
       }
       l->n++;
    } else {
        printf("O Programa foi jogar no Vasco!");
    }
}

void imprime (Descritor *l) {
    NoLista *p;
    if ( !esta_vazia(l)) {
        for ( p = l->prim; p!=NULL; p = p->prox ) {
            printf("%d\n", p->info);
        }
    }
}

int main () {

    Descritor lista;
    criar_lista(&lista);
    insere_inicio(&lista, 18);
    insere_inicio(&lista, 9);
    insere_inicio(&lista, 8);
    imprime(&lista);
    
    return 0;
}
