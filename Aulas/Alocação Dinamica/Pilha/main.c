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

//imprime a pilha
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

//imprime o topo da pilha
float ver_topo (pilha *p) {
    return (p->primeiro->info);
}

void concatena_v1(pilha *p1, pilha *p2) {
    pilha *p3 = criar();
    if (!vazia(p1) && !vazia(p2)) {
        while (p2->primeiro != NULL) {
            push(p3, pop(p2));
        }
        while (p3->primeiro != NULL ) {
            push(p1, pop(p3));
        }
    }
}

void concatena_v2(pilha *p1, pilha*p2) {
    if ( !vazia(p1) && !vazia(p2)) {
        float v = pop(p2);
        concatena_v2(p1, p2);
        push(p1, v);
    }
}

//concatena usando apenas ponteiros 
void concatena_v3(pilha*p1, pilha *p2) {
    nopilha *q;
    for (q = p2->primeiro; q->proximo != NULL; q = q->proximo);
    q->proximo = p1->primeiro;
    p1->primeiro = p2->primeiro;
    free(p2);
}

int main () {
setlocale(LC_ALL,"portuguese");

    // criando a pilha
    pilha *p1 = criar();
    pilha *p2 = criar();
    //inserindo na pilha
    push(p1, 3);
    push(p1, 2);
    push(p1, 1); 

    push(p2, 6);
    push(p2, 5);
    push(p2, 4);

    l();
    printf("Pilha 1:\n");
    imprime(p1);
    l();
    printf("Pilha 2:\n");
    imprime(p2);
    l();
    printf("Topo Atual da Pilha 1:\n");
    printf("%.1f", ver_topo(p1));
    l();
    printf("Topo Atual da Pilha 2:\n");
    printf("%.1f", ver_topo(p2));
    l();
    // pop(p1);
    // printf("Removendo Pilha 1:\n");
    // remove(p1);
    // imprime(p1);
    // l();
    // pop(p2);
    // printf("Removendo Pilha 2:\n");
    // remove(p2);
    // imprime(p2);
    // l();
    printf("Topo Atual da Pilha 1:\n");
    printf("%.1f", ver_topo(p1));
    l();
    printf("Topo Atual da Pilha 2:\n");
    printf("%.1f", ver_topo(p2));
    l();
    printf("Concatenando com a Versão 3 da Função:\n");
    concatena_v2(p1,p2);
    imprime(p1);


    return 0;
}