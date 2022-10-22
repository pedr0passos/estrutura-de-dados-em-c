#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    printf("\n--------------------------------------------------\n");
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
        printf("Esta Vazia");
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

float maior (fila *f) {
    if ( !vazia(f)) {
        float x = 0;
        for ( nofila*p = f->inicio; p!= NULL; p = p->proximo) {
            if ( p->info > x ) {
                x = p->info;
            }
        }
        return x;
    } else {
        return 0;
    }
}

 void combinafilas( fila *f_res, fila *f1, fila *f2) {

    while ( !vazia(f1) || !vazia(f2)) {
        if ( !vazia(f1 )) {
            inserir(f_res, remover(f1));
        }
        if ( !vazia(f2)) {
            inserir(f_res, remover(f2));
        }
    }

    if (  !vazia(f1) && !vazia(f2)) {
        inserir(f_res, remover(f1));
        inserir(f_res, remover(f2));
        combinafilas(f_res, f1, f2);
    } else if ( vazia(f1) && !vazia(f2)) {
        inserir(f_res, remover(f2));
        combinafilas(f_res, f1, f2);
    } else if ( !vazia(f1) && vazia(f2)) {
        inserir(f_res, remover(f1));
        combinafilas(f_res, f1, f2);
    } else {

    }


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
 }

 int pertence(fila *f, float x) {
    if ( vazia(f)) {
        return -1;
    } else {
        nofila *q;
        for ( q = f->inicio; q != NULL; q = q->proximo) {
            if ( q != NULL ) {
                if ( q->info == x ) {
                    return 1;
                }
            } else {
                return 0;
            }
        }
    }
 }

// void ordenada ( fila *f) {
//     if ( !vazia(f)) {
//         int tam_fila=0;
//         for (nofila* q = f->inicio; q!= NULL; q = q->proximo){
//             if ( q!=NULL) {
//                 tam_fila++;
//             }
//         }
//         printf("Tamanho da Fila: %d\n", tam_fila);
//         int x = tam_fila;
//         float v[x];
//         for ( int i=0; i < x; i++) {
//             v[i] = remover(f);
//         }
//         for ( int i=0; i<x; i++) {
//             printf("Vetor %d: %.1f\n", i, v[i]);
//         }
//         float menor = v[0];
//         printf("Menor: %.1f\n", menor);
//         int aux = x-1;
//         printf("Aux:%d\n", aux);
//             while ( aux != 0 ) {
//                 if ( v[aux] < menor ) {
//                     printf("v[aux]%.1f\n",v[aux]);
//                     menor = v[aux];
//                     printf("Menor %.1f\n", menor);
//                     inserir(f, menor);

//                 } else {
//                     i
//                 }
//                 aux--;
//                 printf("AUX: %d\n", aux);
//             }
//         }
//     }

void inverte(fila *f) {
    if (!vazia(f)) {
        int tam_fila =0;
        for (nofila*q = f->inicio; q!=NULL; q = q->proximo) {
            if (q!=NULL) {
                tam_fila++;
            }
        }
        int i = tam_fila;
        float vet[i];
        for (i = (tam_fila - 1); i>=0; i--) {
            vet[i] = remover(f);
        }
        for (i=0; i<tam_fila; i++) {
            inserir(f, vet[i]);
        }
    }
}

int main() {
setlocale(LC_ALL, "portuguese");


    fila *f = criar_fila();
    fila *fila_resp = criar_fila();
    fila *f2 = criar_fila();
    inserir(f, 2.1);
    inserir(f, 4.5);
    inserir(f, 1);
    inserir(f2, 7.2);
    inserir(f2, 3.1);
    inserir(f2, 9.8);
    inserir(f2, 8);
    inserir(f2, 2.1);
    l();
    printf("Fila:\n");
    imprime(f);
    l();
    printf("Invertendo:\n");
    inverte(f);
    imprime(f);

    // float pert = 2.1;
    // printf("%.1f Pertence a Fila ?\n", pert);
    // if ( pertence(f, pert) == 1 ) {
    //     printf("Pertence\n");
    // } else if ( pertence(f, pert) == -1 )  {
    //     printf("Fila Vazia\n");
    // } else {
    //     printf("Não Pertence\n");
    // }
    // l();
    // printf("Ordenando\n");
    // ordenada(f);
    // imprime(f);
    // l();
    // printf("Fila 2:\n");
    // imprime(f2);
    // l();
    // printf("Combinando:\n");
    // combinafilas(fila_resp, f, f2);
    // imprime(fila_resp);
    // l();
    // printf("Maior Elemento:\n");
    // printf("%.1f", maior(f));
    // l();
    // printf("Removendo:\n");
    // remover(f);
    // imprime(f);
    // l();
    // printf("Furando:\n");
    // fura(f, 28);
    // imprime(f);



    return 0;
}
