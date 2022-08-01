#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10

// FILA COM VETOR

//estrutura da fila
typedef struct f {
    float info[N];  //vetor que armazena as informações
    int n, inicio;  // inteiros n = número de elementos da fila, e inicio, marca semmpre qual o primeiro termo da fila, sendo ela o inicio da fila.
}fila;

void l() {
    printf("\n---------------------------------------------\n");
}

//cria a fila
fila *criar() {
    fila *f = malloc(sizeof(fila));
    f->n = 0;
    f->inicio = 0;
    return f;
}

//verifica se a fila está vazia
int vazia(fila *f) {
    return (f->n == 0);
}

//verifica se a fila está cheia
int cheia(fila *f) {
    return (f->n == N);
}

void inserir(fila *f, float v) {
    if (!cheia(f)) {
        int fim = (f->inicio + f->n) % N;
        f->info[fim] = v;
        f->n++;
    } else {
        l();
        printf("Fila Cheia!");
        l();
    }
}

void imprime(fila *f) {
    int x = f->inicio;
    if (!vazia(f)) {
        for ( int i = 0; i < f->n; i++) {
            printf("%.1f\n", f->info[x]);
            x = (x+1)%N;
        }
    } else {
        l();
        printf("Está Vazia!");
        l();
    }
}
float remover(fila*f) {
    float v = f->info[f->inicio];
    if ( !vazia(f)) {
        f->n--;
        f->inicio = (f->inicio + 1) % N;
        return v;
    }else {
        l();
        printf("Fila Vazia");
        l();
    }
}
void liberar(fila*f) {
    int x = f->inicio;
    for(int i = 0; i < f->n; i++) {
        f->info[x] = 0;
        x = (x+1) % N;
    }
    free(f);
}

int main(int argc, char const *argv[])
{
    fila *f = criar();
    inserir(f, 14);
    inserir(f, 4);
    inserir(f, 9367);
    inserir(f, 83);
    l();
    printf("Fila:\n");
    imprime(f);
    l();
    remover(f);
    printf("Removendo:\n");
    imprime(f);
    l();
    liberar(f);
    printf("Liberando:\n");
    imprime(f);


    return 0;
}