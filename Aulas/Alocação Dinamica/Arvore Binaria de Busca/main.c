#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ÁRVORES

// estrutura da árvore
typedef struct arv {
   int info;                 //armazena a informação da arvore
   struct arv *esquerda;     //ponteiro para a esquerda de um suposto filho da arvore
   struct arv *direita;      // ponteiro para a direita de um suposto filho da arvore
}arvore;

// FUNÇÕES 

//cria uma linha separadora 
void l() {
    printf("\n------------------------------------------------------------\n");
}

//verifica se a arvore está vazia
int vazia(arvore *a) {
    return (a == NULL);
}


// busca elemento na arvore
arvore *busca(arvore *a, int v) {
    if (!vazia(a)) {
        if ( v == a->info) {
            return a;
        } else if ( v < a->info ) {
            return busca(a->esquerda, v);
        } else {
            return busca(a->direita, v);
        }
    } else {
        return NULL;
    }
}

//insere um elemento na arvore 
arvore *insere (arvore *a, int v) {
    if ( vazia(a)) {
        a = malloc(sizeof(arvore));
        a->esquerda = a->direita = NULL;
        a->info = v;     
    } else if ( v < a->info){
        a->esquerda = insere(a->esquerda, v);
    } else {
        a->direita = insere (a->direita, v);
    }
    return a;
}

//remove um termo da arvore 
arvore *remover (arvore *a, int v ) {
    if (vazia(a)) {
        return NULL;
    } else {
        if ( v < a->info ){
            a->esquerda = remover(a->esquerda, v);
        } else if ( v > a->info){
            a->direita = remover(a->direita, v);
        } else {
            if ( a->direita == NULL && a->esquerda == NULL ) {
                printf("blabla\n");
                free(a);
                a = NULL;
                printf("blabla2\n");
            }
            if ( a->direita == NULL ) {
                arvore *aux = a->esquerda;
                free(a);
                a = aux;
            } else if (a->esquerda == NULL ) {
                arvore *aux = a->direita;
                free(a);
                a = aux;
            } else {
                arvore *aux = a->esquerda;
                while (aux->direita != NULL ) {
                    aux = aux->direita;
                }
                a->info = aux->info;
                aux->info = v;
                a->esquerda = remover(a->esquerda, v);
            }

        }
  
    }
        return a; 
}

//imprime a arvore
void imprime(arvore *a) {
    printf("<");
    if ( !vazia(a)) {
        printf("%d", a->info);
        imprime(a->esquerda);
        imprime(a->direita);
    }
    printf(">");
}

int main(int argc, char** argv) {
    printf("Main\n");

    // variaveis
    arvore *arv;
    printf("Main2\n");
    //criando arvore
    arv = insere(arv, 6);
    arv = insere(arv, 2);
    arv = insere(arv, 8);
    arv = insere(arv, 1);
    arv = insere(arv, 4);
    arv = insere(arv, 3);
    printf("Main2\n");
    
    // imprimindo arvore padrão
    l();
    printf("Árvore:\n");
    imprime(arv);
    l();

    //removendo um termo da arvore 
    int numero = 3;
    printf("Removendo %d da árvore:\n", numero);
    arv  = remover(arv, numero);
    imprime(arv);
    
    
    return (EXIT_SUCCESS);
}

