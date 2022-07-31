#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    float info;
    struct no* prox;
}NoPilha;

typedef struct pilha {
    NoPilha* prim;
}Pilha;

Pilha* criaPilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->prim = NULL;

    return p;
}

Pilha* estaVazia(Pilha *p){
    return(p->prim == NULL);
}

void push(Pilha *p, float num){
    NoPilha* n = malloc(sizeof(NoPilha));
    if ( n != NULL ) {
        n->info = num;
        n->prox = p->prim;
        p->prim = n;
    } else {
        printf("Não foi possivel alocar espaço.\n");
    }
}

void imprimePilha (Pilha *p) {
    NoPilha* aux;
    if ( !estaVazia(p)) {
        for(aux = p->prim; aux != NULL; aux = aux->prox) {
            printf("%.1f\n", aux->info);
        }
    } else {
        printf("Está vazia!");
    }

}

float pop(Pilha *p) {
    if (!estaVazia(p)) {
        NoPilha*temp = p->prim;
        float v = temp->info;
        p->prim = temp->prox;
        free(temp);
        return v;
    } else {
        printf("Pilha Vazia!\n");
        exit(1);
    }
}

void libera(Pilha *p){
    if(!estaVazia(p)){
        NoPilha *aux, *temp;
        for(aux = p->prim; aux != NULL; aux = temp){
            temp = aux->prox;
            free(aux);
        }
        free(p);
        p = criaPilha();
    }
}

void concatena_pilha (Pilha *p1, Pilha *p2) {
    Pilha *aux = criaPilha();
    NoPilha *temp;
    for ( NoPilha *p = p2->prim; p!= NULL; p = temp ) {
        temp = p->prox;
        push(aux, pop(p2));
    }
    for ( NoPilha *p = aux->prim; p!=NULL; p = temp ) {
        temp = p->prox;
        push(p1, pop(aux));
    }
    printf("\n------------------------\n");
    imprimePilha(p1);
}

int main(){

    Pilha *p1 = criaPilha();
    Pilha *p2 = criaPilha();
    push(p1, 5012);
    push(p1, 390);
    push(p1, -133);

    push(p2, 3);
    push(p2, 25);
    push(p2, 38);
    
    imprimePilha(p1);
    printf("\n------------------\n");
    imprimePilha(p2);
    concatena_pilha(p1, p2);
    imprimePilha(p2);

}