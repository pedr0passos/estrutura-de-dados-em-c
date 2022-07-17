
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef struct lista {
    int itens[MAX];
    int n;
} Lista;

void criarLista (Lista *l) {
    l->n = 0;
}

int estaVazia (Lista *l) {
    if (l->n == 0) {
        return 1;
    } else {
        return 0;
    }
}

int estaCheia ( Lista *l) {
    if (l->n == MAX) {
        printf("Lista está cheia!");        
        return 1;
    } else {
        return 0;
    }
}

void insereItem (Lista *l, int n ) {
    if ( !estaCheia(l)) {
        l->itens[l->n] = n;
        printf("Digite o item da lista: ");
        scanf("%d", l->itens);
        l->n++;
    }
}

void imprimeLista (Lista *l) {
    for (int i=0; i<l->n; i++) {
        printf("%d\n", l->itens[i]);
    }
}

void removerItem ( Lista *l, int i) {
    if ( i>=0 && i < l->n) {
        for ( int x = i; x < l->n; x++) {
            l->itens[x-1] = l->itens[x];
            l-> n--;
        }
    } else{
        printf("Posição Inválida!");
    }
}

int main () {
    
Lista lista;

criarLista (&lista);

insereItem(&lista, 0);
insereItem(&lista, 1);
insereItem(&lista, 2);
insereItem(&lista, 3);

imprimeLista (&lista);

    return 0;
}  
