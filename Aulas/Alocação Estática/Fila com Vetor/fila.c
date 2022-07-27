#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10

typedef struct fila{
    float info[N]; // armazena valores reais
    int n; // num de elem existentes na fila

    int inicio; // primeiro elem da fila
}Fila;

void l() {
    printf("\n------------------------------------------------------------------------------------\n");
}

Fila* criarFila(){
    Fila *f = malloc(sizeof(Fila));

    f->n = 0;
    f->inicio = 0;
    return f;
}

int estaVazia(Fila *f){
    return(f->n == 0);
}

int estaCheia(Fila *f){
    return(f->n == N);
}

void inserir(Fila *f, float v){
    int n = 0;

    if(!estaCheia(f)){
        int fim = (f->inicio + f->n) % N;
        f->info[fim] = v;
        f->n++;
    }
    else {
        printf("\nfila cheia");
    }
}

void imprimeFila(Fila *f){
    int i, x = f->inicio;

    if(!estaVazia(f)){
        for(i = 0; i < f->n; i++){
            printf("\n%.1f", f->info[x]);
            x=(x+1) % N;
        }
    }
}

float remover(Fila *f){
    float v = f->info[f->inicio];
    
    if(!estaVazia(f)){
        f->n--;
        f->inicio = (f->inicio + 1) % N;
        return v;
    }
    else
        printf("\nlista vazia");
}

void liberarFila(Fila *f){
    free(f);
}

float maior (Fila *f) {
    int x= f->inicio;
    float aux = 0;
    for (int i = 0; i < f->n; i++) {
        if ( f->info[x] > aux ) {
            aux = f->info[x];
            x = (x+1) % N;
        } else {
            x = (x+1) % N;
        }
    }
    return aux;
}

int main(){
    // criando a fila
    Fila *f = criarFila();

    // inserindo na fila
    inserir(f, 50);
    inserir(f, 2);
    inserir(f, 70000000);
    inserir(f, 100);
    inserir(f, 22);
    l();
    printf("Fila:\n");
    imprimeFila(f);
    l();
    printf("Maior Elemento:\n");
    float maior_termo = maior(f);
    printf("%.2f", maior_termo);


}