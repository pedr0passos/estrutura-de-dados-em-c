#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// PILHA COM LISTA ENCADEADA (ALOCAÇÃO DINAMICA)

//estrutura que representa a pilha e dos nós da pilha
typedef struct no {
    float info;
    struct no *proximo;
}nopilha;

typedef struct p {
    nopilha *primeiro;
}pilha;

//FUNÇÕES:

void l() {
    printf("\n-------------------------------------\n");
}

//cria uma pilha vazia
pilha *criar() {
    pilha *p = malloc(sizeof(pilha));
    p->primeiro = NULL;
    return p;
}

//verifica se a pilha está vazia
int vazia(pilha *p) {
    return (p->primeiro == NULL);
}

//insere um elemento no topo da pilha ( p->primeiro )
void push(pilha *p, float v) {
    nopilha *novo = malloc(sizeof(nopilha));
    if ( novo != NULL ) {
        novo->info = v;
        novo->proximo = p->primeiro;
        p->primeiro = novo;
    } else {
        l();
        printf("Não foi possível alocar espaço.");
        l();
    }
}

//remove no topo da pilha (p->primeiro);
float pop(pilha *p) {
    if (!vazia(p)) {
        nopilha *temp = p->primeiro;
        float v = temp->info;
        p->primeiro = temp->proximo;
        free(temp);
        return v;
    } else {
        l();
        printf("Pilha Vazia!");
        l();
        exit(1);
    }
}

//libera a pilha 
void liberar(pilha *p) {
    nopilha *q, *temp;
    for (q = p->primeiro; q!=NULL; q = temp) {
        temp = q->proximo;
        free(q);
    }
    free(p);
    p = criar();
}

void imprime(pilha*p) {
    if (!vazia(p)) {
        for ( nopilha *q = p->primeiro; q!=NULL; q = q->proximo) {
            printf("%.1f\n", q->info);
        }
    } else {
        l();
        printf("Pilha Vazia!");
        l();
    }
}

float ver_topo (pilha *p) {
    return (p->primeiro->info);
}

int main () {

    // criando a pilha
    pilha *p = criar();
    //inserindo na pilha
    push(p, 40);
    push(p, 170);
    push(p, 273);
    push(p, 12); 
    l();
    printf("Pilha:\n");
    imprime(p);
    l();
    printf("Topo da Pilha Atual:\n");
    printf("%.1f", ver_topo(p));
    l();
    pop(p);
    printf("Removendo:\n");
    remove(p);
    imprime(p);
    l();
    printf("Topo da Pilha Atual:\n");
    printf("%.1f", ver_topo(p));
    l();
    
    return 0;
}