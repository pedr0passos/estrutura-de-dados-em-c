#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//---------LISTA COM DESCRITOR---------//

//structs

//struct dos n�s da lista
typedef struct no {
    int info;
    struct no *prox;
}NoLista;

//struct do descritor, que cont�m o primeiro e ultimo n� da lista, e a quantidade de termos da lista
typedef struct descritor {
    NoLista *primeiro;
    NoLista *ultimo;
    int n;
}Descritor;

//fun��es 
// separador 
void linha () {
    printf("\n-------------------------------------------\n");
}
// fun��o de criar lista
void cria_lista (Descritor *l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->n = 0;
}

// fun��o que averigua se a lista est� vazia

int lista_vazia (Descritor *l) {
    if ( l->n == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

// fun��o que insere no inicio da lista
void insere_inicio (Descritor *l, int v) { 

    NoLista *novo_item = malloc(sizeof(NoLista));

    if ( novo_item != NULL) {

        novo_item->info = v;
        novo_item->prox = l->primeiro;
        l->primeiro = novo_item;

        if (lista_vazia(l)) {

            l->ultimo = novo_item;

        }

        l->n++;

    } else {

        printf("N�o foi poss�vel alocar espa�o!");

    }
    
}

//fun��o que imprime a lista
void imprime (Descritor *l) {

    NoLista *p;
    printf("Lista:\n");

    if ( l->primeiro == NULL ) {

        printf("Lista Vazia!");

    } else {

        for ( p = l->primeiro; p != NULL; p = p->prox) {

            printf("%d\n", p->info);

        }

    }

}

// fun��o que insere no final da lista 
void insere_final (Descritor *l, int v) {

    NoLista *novo_item = malloc(sizeof(NoLista));

    if ( novo_item != NULL ) {

        novo_item->info = v;
        novo_item->prox = NULL;

            if (lista_vazia(l)) {

                l->primeiro = novo_item;

            } else {

                l->ultimo->prox = novo_item;
                l->ultimo = novo_item;
                
            }

        l->n++;

    } else {

        printf("N�o foi poss�vel alocar espa�o.");

    }

}

// fun��o que remove elemento 

void remove_elemento (Descritor *l, int v) {

    NoLista *p, *ant = NULL;

    for ( p = l->primeiro; p != NULL && p->info != v; p = p->prox )  {

        ant = p;

    }

    if ( ant == NULL ) {    // quando tem apenas 1 elemento 

        l->primeiro = p->prox;
        l->ultimo = NULL;

    } else {                // quando tem mais de 1 elemento 

        if ( p == l->ultimo) {      // quando � o ultimo elemento 

            l->ultimo = ant;

        }

        ant->prox = p->prox;

    }

    free(p);

}

// fun��o que esvazia lista 

void esvazia (Descritor *l) {

    NoLista *p, *aux;

    for ( p = l->primeiro; p!=NULL; p = p->prox ) {

        aux = p->prox;
        free(p);

    }

    l->n = 0;
    l->primeiro = NULL;
    l->ultimo = NULL;

}

int main () {
setlocale(LC_ALL,"portuguese");

//variaveis
Descritor lista;
int w = 0, valor, opcao=0;

cria_lista(&lista);     // criando a lista

//menu
    while ( w == 0 ) {
    printf("1 - Inserir no in�cio da lista\n");
    printf("2 - Inserior no final da lista\n");
    printf("3 - Imprimir a lista\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Esvaziar lista\n");
    printf("6 - Sair\n");
    printf("Op��o: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

        system("cls");
        linha();
        printf("Digite o n�mero que deseja inserir: ");
        scanf("%d", &valor);
        insere_inicio(&lista, valor);
        break;

    case 2:

        system("cls");
        linha();
        printf("Digite o n�mero que deseja insetir: ");
        scanf("%d", &valor);
        insere_final(&lista, valor);
        break;

    case 3:

        system("cls");
        linha();
        imprime(&lista);
        linha();
        break;

    case 4:

        system("cls");
        linha();
        printf("Digite um n�mero que deseja remover: ");
        scanf("%d", &valor);
        remove_elemento (&lista, valor);
        break;

    case 5:

        system ("cls");
        esvazia(&lista);
        linha();
        printf("Lista Esvaziada!");
        linha();
        break;

    case 6:

        system("cls");
        w = 1;
        break;

    default:

        break;
    }

}

return 0;

}