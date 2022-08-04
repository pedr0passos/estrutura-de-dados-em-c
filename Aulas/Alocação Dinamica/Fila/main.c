#include <stdio.h>
#include <stdlib.h>

// structs da fila com lista 
typedef struct no {
    float info;
    struct no *proximo;
}nofila;

typedef struct f {
    nofila *inicio;    // ponteiro que aponta para o primeiro termo da lista/fila
    nofila *fim;       // ponteiro que aponta para o ultimo termo da lista/fila
}fila;

// FUNÇÕES 


// cria linha

void l(){
    printf("\n-------------------------------------------------------------------\n\n");
}

// cria a fila 
fila *criar_fila() {
    fila *f = malloc(sizeof(fila));
    f->fim = f->inicio = NULL;
    return f;
}

// verifica se a fila está vazia
int vazia(fila *f) {
    return (f->fim == NULL && f->inicio == NULL );
}

// inserir um elemento na fila
void inserir (fila *f, float v) {
    nofila *novo = malloc(sizeof(nofila));
    novo->info = v;
    novo->proximo = NULL;
    if (!vazia(f)) {
        f->fim->proximo = novo;
    } else {
        f->inicio = novo;
    } 
    f->fim = novo;
}

void imprime (fila *f) {
    if (!vazia(f)) {
        nofila* p;
        for ( p = f->inicio; p != NULL; p = p->proximo ) {
            printf("%.1f\n", p->info);
        }
    } else {

    } 

    
}

float remover (fila *f) {
    if ( !vazia(f)) {
        nofila* aux = f->inicio;
        float valor = aux->info;
        f->inicio = aux->proximo;
            if ( f->inicio == NULL ) {
                f->fim = NULL;
            }
        free(aux);
        return valor;
    } else {
        l();
        printf("Está Vazia");
        l();
    }

}

void fura (fila *f, float v) {
    if (!vazia(f)) {
        nofila *p, *aux=NULL;
        for ( p = f->inicio; p->info != v; p = p->proximo ) {
            aux = p;
        }
        if ( aux != NULL ) {
            aux->proximo = p->proximo;
            p->proximo = f->inicio;
            f->inicio = p;
        }

    }
}

// void combinafilas( fila *f_res, fila *f1, fila *f2) {

//     // SEM RECURSIVIDADE

//     // do {
//     //     inserir(f_res, remover(f1));
//     //     inserir(f_res, remover(f2));
//     //     if ( vazia(f1) ) {
//     //         do {
//     //             inserir(f_res, remover(f2));
//     //         }while( !vazia(f2) );
//     //     } else if ( vazia(f2)) {
//     //         do {
//     //            inserir(f_res, remover(f1));
//     //         } while (!vazia(f1));
            
//     //     }
//     // }while ( !vazia(f1) && !vazia(f2));

//     // COM RECURSIVIDADE

//     // if ( !vazia(f1) && !vazia(f2) ) {
//     //     inserir(f_res, remover(f1));
//     //     inserir(f_res, remover(f2));
//     //     combinafilas(f_res, f1,f2);
//     // } else if (vazia(f1) && !vazia(f2)){
//     //     inserir(f_res, remover(f2));
//     //     combinafilas(f_res, f1,f2);
//     // } else if ( !vazia(f1) && vazia(f2)) {
//     //     inserir(f_res, remover(f1));
//     //     combinafilas(f_res, f1,f2);
//     // } else {
//     //     imprime(f_res);
//     // }
// }

int main() {

    fila *f = criar_fila();
    inserir(f, 17);
    inserir(f, 1);
    inserir(f, 28);
    inserir(f, 261);
    inserir(f, 9);

    l();
    printf("Fila:\n");
    imprime(f);
    l();
    printf("Removendo:\n");
    remover(f);
    imprime(f);
    l();
    printf("Furando:\n");
    fura(f, 9);
    imprime(f);

    // combinafilas(fila_resp, fila, fila2);

    return 0;
}
