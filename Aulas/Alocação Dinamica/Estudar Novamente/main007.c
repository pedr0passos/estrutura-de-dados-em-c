#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int info;
    struct no *prox;
}NoLista;

NoLista *criarLista () {
    return NULL;
}

int estaVazia (NoLista **l) {
    return(*l == NULL);
}

void insereItem (NoLista **l, int v) {
  NoLista *n =  malloc(sizeof(NoLista));
  if ( n != NULL ) {
      n->info = v;
      n->prox = *l;
      *l = n;
  } else {
      printf("Não foi possível alocar espaço.");                
  }
}

void imprime(NoLista** l) {
    if (!estaVazia(l)){
        NoLista *p;
        for (p = *l; p!=NULL; p = p->prox) {
            printf("%d\n", p->info);
        }
    } else {
        printf("Está Vazia!");
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
    if (!estaVazia(l)) {
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

    if (ant == NULL) {  // significa q o primeiro elemento � maior que o v inserido

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
    if ( !estaVazia(l)) {
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
    if ( !estaVazia(l)) {
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

int main () {
 setlocale(LC_ALL, "portuguese");
 NoLista *lista, *x;
 lista = criarLista();
  
 //insereItem(&lista, 1);
 //insereItem(&lista, 7);
 //insereItem(&lista, 2);
 //insereItem(&lista, 5);
 //insereItem(&lista, 10);
 
 x = busca(&lista, 7);
 
    printf("\n----------LISTA----------\n\n");
    imprime(&lista);
    
    printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    contador(&lista);
    
    printf("\n\n----------BUSCA----------\n\n");
    printf("%p", &x);
    
    printf("\n\n------ITEM REMOVIDO------\n\n");
    remover_item(&lista, 2);
    imprime(&lista);
    
    printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    contador(&lista);
    
    printf("\n\n------LISTA ORDENADA------\n\n");
    insereOrdenado(&lista, 1);
    insereOrdenado(&lista, 2);
    insereOrdenado(&lista, 3);
    imprime(&lista);
    
    printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    contador(&lista);

    printf("\n\n-----THE LAST OF NOLISTA-----\n\n");
    printf("%p", ultimo_termo(&lista));

    printf("\n\n---QUANTIDADE DE N�MEROS MAIORES---\n\n");
    int maioreS = maiores(&lista, 4);
    printf("%d", maioreS);

    printf("\n\n------LISTA ESVAZIADA------\n\n");
    libera_lista(&lista);
    imprime(&lista);
    
    printf("\n\n---QUANTIDADE DE TERMOS----\n\n");
    contador(&lista);

    

    
    return 0;
}
