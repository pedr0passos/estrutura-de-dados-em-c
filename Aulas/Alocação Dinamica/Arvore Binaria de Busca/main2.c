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

arvore *remove (arvore *arv, int v) {
    if ( vazia(arv) ) {
        return NULL;
    } else {

        if ( v < arv->info ) {

            arv->esquerda = remove(arv->esquerda, v);

        } else if ( v > arv->info ) {

            arv->direita = remove(arv->direita, v );

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
                arv->esquerda = remove(arv->esquerda, v);
            }
        }
        return arv;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
