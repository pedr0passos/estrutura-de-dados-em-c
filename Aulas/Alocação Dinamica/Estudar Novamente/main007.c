#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int posicao = 5;
int posicao2 = 5;

typedef struct no {
    int info, p;
    struct no *prox;
}NoLista;

NoLista *criarLista () {
    return NULL;
}

int vazia (NoLista **l) {
    return(*l == NULL);
}

void insereItem (NoLista **l, int v) {
    NoLista *n =  malloc(sizeof(NoLista));
  if ( n != NULL ) {
    
    n->p = posicao;
    posicao--;
    n->info = v;
    n->prox = *l;
    *l = n;


  } else {
      printf("NÃ£o foi possÃ­vel alocar espaÃ§o.");                
  }
}

void imprime(NoLista** l) {
    if (!vazia(l)){
        NoLista *p;
        for (p = *l; p!=NULL; p = p->prox) {
            printf("%d -> Posição: %d\n ", p->info, p->p);
        }
    } else {
        printf("EstÃ¡ Vazia!");
    }
}

NoLista *busca (NoLista **l, int v) {
    NoLista*p;
    for (p = *l; p!=NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        } else {
            return NULL;
        }
    }
}

void remover_item (NoLista **l, int v) {
    NoLista *p, *ant = NULL;
    for (p=*l; p!=NULL && p->info != v; p = p->prox) {
        ant = p;
        }
        if ( ant == NULL) {
            *l = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free(p);   
}

void libera_lista (NoLista **l) {
    NoLista *temp;
    if (!vazia(l)) {
        for (NoLista* p = *l ; p!=NULL; p = temp) {
            temp = p->prox;
            free(p);
        }
    }
    *l = NULL;
}

void insereOrdenado (NoLista **l, int v) {

    NoLista *p, *ant = NULL;
    NoLista *n = (NoLista*)malloc(sizeof(NoLista));

    if(n!=NULL) {

        n -> info = v;

        for ( p = *l; p!=NULL && p->info < v; p = p->prox) {

            ant = p;

        }

    }

    if (ant == NULL) {  // significa q o primeiro elemento ï¿½ maior que o v inserido

        n->prox = p;
        *l = n;

    } else {

        ant -> prox = n;
        n -> prox = p;

    }
    
}

int contador (NoLista **l) {
    NoLista *p;
    int cont=0; 
    for ( p = *l; p != NULL; p = p->prox ) {
        cont++;
    }
    return printf("%d", cont);
}

NoLista* ultimo_termo (NoLista **l) {
    NoLista *p;
    if ( !vazia(l)) {
        for ( p = *l; p != NULL; p = p->prox ) {    
            if (p->prox == NULL){
                return p;
            }
        } 
    } else {
        return NULL;
    }

}

int maiores (NoLista **l, int n) {
    NoLista *p;
    int cont=0;
    if ( !vazia(l)) {
        for (p = *l; p != NULL; p = p->prox) {
            if ( n < p->info) {
                cont++;
            }
        }
        return cont;
    } else {
        return NULL;
    }
}

int busca_sequencial ( NoLista **lista, int termo ) {
    if (!vazia(*lista)) {
        NoLista *p;
        for ( p = *lista; p != NULL; p = p->prox ) {
            if ( p->info == termo ) {
                return 1;
            }
        }
        return 0;
    }
}

int busca_binaria( NoLista **lista, int termo ) {

    if ( !vazia(*lista)) {

        NoLista *direita;
        NoLista *esquerda = *lista;
        NoLista *meio;
        int m = posicao2/2;
        for (direita = *lista; direita->prox != NULL; direita = direita->prox);
        for (meio = *lista; meio->p != m; meio = meio->prox);
       
        while ( (esquerda->p) <= (direita->p) ) {
            if ( meio->info == termo ) {
                return 1; 
            } else if ( termo > meio->info ) {
                    esquerda = meio->prox;
                    m = (esquerda->p + direita->p)/2;    
                    for (meio = *lista; meio->p != m; meio = meio->prox);                    
                } else if ( termo < meio->info) {
                    for ( direita = esquerda; direita->prox != meio; direita = direita->prox );
                    m = (esquerda->p + direita->p)/2;    
                    for (meio = *lista; meio->p != m; meio = meio->prox); 
                } else {
                    return 0;
                }
            }
        }
}

int main () {
 setlocale(LC_ALL, "portuguese");
 NoLista *lista, *x;
 lista = criarLista();
  
insereItem(&lista, 5);
insereItem(&lista, 4);
insereItem(&lista, 3);
insereItem(&lista, 2);
insereItem(&lista, 1);

 
    printf("\n----------LISTA----------\n\n");
    imprime(&lista);
    int busca = 100;
    printf("\nBuscando o termo %d\n", busca);
    if ( busca_binaria(&lista, busca) == 1 ) {
        printf("O numero %d esta na lista\n", busca);
    } else {
        printf("O numero %d não esta na lista\n", busca);
    }
    
    // printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    // contador(&lista);
    
    // printf("\n\n----------BUSCA----------\n\n");
    // printf("%p", &x);
    
    // printf("\n\n------ITEM REMOVIDO------\n\n");
    // remover_item(&lista, 2);
    // imprime(&lista);
    
    // printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    // contador(&lista);
    
    // printf("\n\n------LISTA ORDENADA------\n\n");
    // insereOrdenado(&lista, 1);
    // insereOrdenado(&lista, 2);
    // insereOrdenado(&lista, 3);
    // imprime(&lista);
    
    // printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    // contador(&lista);

    // printf("\n\n-----THE LAST OF NOLISTA-----\n\n");
    // printf("%p", ultimo_termo(&lista));

    // printf("\n\n---QUANTIDADE DE Nï¿½MEROS MAIORES---\n\n");
    // int maioreS = maiores(&lista, 4);
    // printf("%d", maioreS);

    // printf("\n\n------LISTA ESVAZIADA------\n\n");
    // libera_lista(&lista);
    // imprime(&lista);
    
    // printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    // contador(&lista);

    

    
    return 0;
}
