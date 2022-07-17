#include <stdlib.h>
#include <stdio.h>

typedef struct lista_amigos {

    int id;
    struct lista_amigos *proximo;

}Amigos;

//Remove um amigo
void remove_amigo ( Amigos **l, int v ) {

    Amigos *p, *ant = NULL;
    
    for ( p = *l; p !=NULL && p->id != v; p = p->proximo) { 

        ant = p;

    } 
    
    if ( ant == NULL ) {  

        *l = p->proximo;

    } else {

        ant->proximo = p->proximo;

    } 

    free(p);

}

//Insere um amigo
void inserir_amigo ( Amigos **l, int v) {

    Amigos *amigo = malloc(sizeof(Amigos));

    if ( amigo != NULL) {

        amigo->id = v;
        amigo->proximo = *l;
        *l = amigo;

    }

    else {

        printf ("Não foi possí­vel alocar espaço!");

    }

}