#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct binarie_busca {
    int info;
    struct binarie_busca *esquerda;
    struct binarie_busca *direita;
}arvore;

int vazia(arvore * arv) {
    return (arv == NULL); 
}

arvore *busca(arvore *arv, int v) {
    if ( !vazia(arv)) {
        if ( v == arv->info) {
            return arv;
        } else if ( v < arv->info ) {
            return busca(arv->esquerda, v);
        } else {
            return busca(arv->direita, v);
        }
    } else {
        return NULL;
    }
}

arvore *insere ( arvore* arv, int v) {
    if ( vazia(arv)) {
        arv = malloc(sizeof(arvore));
        arv->info = v;
        arv->esquerda = arv->direita = NULL;
    } else if ( v < arv->info ){
        arv->esquerda = insere(arv->esquerda, v);
    } else if ( v > arv->info) {
        arv->direita = insere(arv->direita, v);
    }
    return arv;
}

arvore *remover (arvore *arv, int v) {
    if ( vazia(arv) ) {
        return NULL;
    } else {

        if ( v < arv->info ) {

            arv->esquerda = remover(arv->esquerda, v);

        } else if ( v > arv->info ) {

            arv->direita = remover(arv->direita, v );

        } else {

            if ( arv->direita == NULL && arv->esquerda == NULL ) {

                free(arv);
                arv = NULL;

            } else if ( arv->esquerda == NULL ) {
                arvore*t = arv;
                arv = arv->direita;
                free(t);
            } else if ( arv->direita == NULL ) {
                arvore *t = arv;
                arv = arv->esquerda;
                free(t);
            } else {
                arvore *f = arv->esquerda;
                while ( f->direita != NULL ) {
                    f = f->direita;
                } 
                arv->info = f->info;
                f->info = v;
                arv->esquerda = remover(arv->esquerda, v);
            }
        }
        return arv;
    }
}

void imprime(arvore *a) {
    if(!vazia(a)) {
        printf("%d\n", a->info);
        imprime(a->esquerda);
        imprime(a->direita);
    } 
 }

int main() {
    
    arvore *arv;
    arv = insere(arv, 5);
    arv = insere(arv, 25);
    arv = insere(arv, 31);
    arv = insere(arv, 839);
    imprime(arv);

    return 0;
}
