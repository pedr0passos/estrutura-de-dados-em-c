#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// ÁRVORES

// estrutura da árvore
typedef struct arv_binarie {
   int info;                 //armazena a informação da arvore
   struct arv_binarie *esquerda;     //ponteiro para a esquerda de um suposto filho da arvore
   struct arv_binarie *direita;      // ponteiro para a direita de um suposto filho da arvore
}arvore;

// FUNÇÕES 

//cria uma linha separadora 
void l() {
    printf("\n------------------------------------------------------------\n");
}

arvore *criar_arvore() {
    return NULL;
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
                free(a);
                a = NULL;
            }
            else if ( a->direita == NULL ) {
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

int maior (arvore *a) {
    if ( vazia(a)) {
        return 0;
    } else {
        if ( a->direita != NULL ) {
            maior(a->direita);
        } else {
            return a->info;
        }
    }
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

int ocorrencias (arvore *a, int x) {
    if (!vazia(a)) {
        if ( x == a->info ) {
            return 1 + ocorrencias(a->direita, x);
        }else if ( x > a->info ) {
            return 0 + ocorrencias(a->direita, x);
        } else {
            return 0 + ocorrencias(a->esquerda, x);
        }
    } else {
        return 0;
    }
}

void imprime_folhas_decres (arvore *a) {
    if (!vazia(a)) {
        if (a->direita == NULL && a->esquerda == NULL ) {
            printf("%d ", a->info);
        } else {
            imprime_folhas_decres(a->direita);
            imprime_folhas_decres(a->esquerda);
        }
    }
}

int quantidade_de_numeros (arvore *a, int c) {
    if ( vazia(a)) {
        return 0;
    } else {
        if ( a->info == c ) {
            return 1 + (quantidade_de_numeros(a->direita, c));
        } else if ( c > a->info ) {
            return quantidade_de_numeros(a->direita, c);
        } else {
            return quantidade_de_numeros(a->esquerda, c);
        }
    }
}

int de_busca(arvore *a) {
    if(vazia(a)) {
        return 1;
    } else {
        if (a->info < a->esquerda->info || a->info > a->direita->info) {
            return 0;
        } else if (a->info > a->esquerda->info && a->info < a->direita->info ) {
            return ( 1 && de_busca(a->esquerda) && de_busca(a->direita));
        } else if ( a->direita == NULL && a->esquerda == NULL ) {
            return 1;
        }
    }
}

int main() {
setlocale(LC_ALL, "portuguese");

    // variaveis
    arvore *arv = criar_arvore();
    //criando arvore
    arv = insere(arv, 10);
    arv = insere(arv, 7);
    arv = insere(arv, 2);
    arv = insere(arv, 11);
    arv = insere(arv, 72);
    arv = insere(arv, 5);
    arv = insere(arv, 41);
    arv = insere(arv, 9);
    
    // imprimindo arvore padrão
    l();
    printf("Arvore:\n");
    imprime(arv);
    l();
    printf("É uma Arvore de Busca ?\n");
    if (de_busca(arv) == 1) {
        printf("SIM.");
    } else {
        printf("NÃO.");
    }
    //removendo um termo da arvore 
    // int numero = 3;
    // printf("Removendo %d da arvore:\n", numero);
    // arv  = remover(arv, numero);
    // imprime(arv);
    // l();
    // printf("Maior Elemento:\n");
    // printf("%d", maior(arv));
    // l();
    // printf("Quantidade de 2 na arvore:\n");
    // printf("%d", ocorrencias(arv, 12));
    // l();
    // printf("Quantidade de 5 na arvore:\n");
    // printf("%d", quantidade_de_numeros(arv, 5));
    // l();
    // printf("Folhas:\n");
    // imprime_folhas_decres(arv);
    
    return 0;
}

