#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 50

// PILHA COM VETOR

//estrutura que representa a pilha
typedef struct p {
    float info[N];
    int n;
}pilha;

void l() {
    printf("\n--------------------------\n");
}

//cria a pilha, alocando espaço para ela, e retornando o endereço de onde foi alocado
pilha *criar_pilha() {
    pilha *p = malloc(sizeof(pilha));
    p->n = 0;
    return p;
}

//verifica se a pilha está vazia ou não, retornando 1 ou 0
int vazia( pilha *p ) {
    return (p->n == 0);
}

//verifica se a pilha está cheia ou não, retornando 1 ou 0
int cheia( pilha *p ) {
    return (p->n == N);
}

//push ( empilhar ) significa que irá colocar uma informação na pilha, ou seja, insere_pilha
void push( pilha *p, float v ) {
    if (!cheia(p)) {
        p->info[p->n] = v;
        p->n++;
    } else {
        printf("Pilha Cheia!");
    }
}

//pop( desempilhar ) significa que irá retirar uma informação do topo da pilha, ou seja, remove_pilha
float pop( pilha *p)  {
    if (!vazia(p)) {
        float v = p->info[p->n - 1];
        p->n--;
        return v;
    } else {
        printf("Pilha Vazia!");
    }
}

// libera todo o espaço que foi alocado para a pilha
void liberar( pilha *p ) {
    free(p);
}

//função que imprime a pilha nas duas ordens, do topo pra baixo, e de baixo para topo
void imprime( pilha *p ) {
    for (int i = (p->n - 1); i >= 0; i--) {
        printf("%.1f\n", p->info[i]);
    }
    // for ( int i = 0; i < p->n; i++) {
    //     printf("%.1f\n", p->info[i]);
    // }
}

//função que retorna o valor que está no topo da pilha
float ver_topo( pilha *p) {
    if ( !vazia(p) ) {
        return p->info[p->n - 1];
    } else {
        printf("Pilha está Vazia!\n");
    }
}

int main () {
setlocale(LC_ALL,"portuguese");

// cria a pilha e envia o endereço para o ponteiro criado
pilha *p = criar_pilha();

    l();
    printf("PILHA COM VETOR:");
    l();
    push(p, 70);
    push(p, 620);
    push(p, 180);
    push(p, 928);
    push(p, 4);
    printf("Pilha Comum:\n");
    imprime(p);
    l();
    printf("Removendo o topo:\n");
    pop(p);
    imprime(p);
    l();
    printf("Retornando o valor do topo:\n");
    printf("%.1f", ver_topo(p));
    l();

return 0;
}