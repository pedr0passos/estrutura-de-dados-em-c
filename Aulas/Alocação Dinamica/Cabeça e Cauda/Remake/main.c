#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// structs do programa
typedef struct no {

    int info;
    struct no *prox;

}No;

typedef struct cab_caud {

    No *cabeca;
    No *cauda;

}Lista;

// funções do programa

// função que cria uma linha separadora
void linha () {

    printf("\n----------------------------------------------------------\n");

}

// função que cria a lista
void cria_lista (Lista *l) {

    l->cabeca = (No*)malloc(sizeof(No));
    l->cauda = (No*)malloc(sizeof(No));
    l->cabeca->prox = l->cauda;
    l->cauda->prox = NULL;

}

// função que averigua se a lista está vazia 
int lista_vazia ( Lista *l) {

    if ( l->cabeca->prox == l->cauda ) {

        return 1;

    } else {

        return 0;

    }

}

// função que insere elemento no inicio da lista
void insere_cab ( Lista *l, int v ) {

    No *novo_item = malloc(sizeof(No));             
        novo_item->info = v;
        novo_item->prox = l->cabeca->prox;
        l->cabeca->prox = novo_item;

}

// função que insere elemento no final da lista
void insere_caud (Lista *l, int v) {

    No *novo_item = malloc(sizeof(No));
    novo_item->info = v;
    novo_item->prox = l->cauda;

    for ( No *p = l->cabeca->prox; p != l->cauda; p = p->prox ) {

        if ( p->prox == l->cauda ) {

            p->prox = novo_item;
            break;

        }

    }

}

// função que imprime a lista
void imprime (Lista *l) {

    No *p;
    for ( p = l->cabeca->prox; p != l->cauda; p= p->prox ) {

        printf("%d\n", p->info);

    }

}

// função que remove um elemento da lista
void remove_element (Lista *l, int v) {
    if (!lista_vazia(l)) {

        No *p, *ant = l->cabeca;
        for ( p = l->cabeca->prox; p->info != v; p=p->prox) {

            ant = p;

        }

        if ( ant->info == v) {

            l->cabeca->prox = p->prox;

        } else {

            ant->prox = p->prox;

        }

        free(p);

    }

}

// função que esvazia a lista

void esvazia (Lista *l) {
    No *p, *aux;
    for ( p = l->cabeca->prox; p != NULL; p = p->prox) {
        aux = p->prox;
        free(p);
    }
    l->cabeca->prox = l->cauda;
    printf("Lista Vazia!");
    linha();
}

int main () {
setlocale(LC_ALL,"portuguese");
// variaveis do programa
Lista lista;
int opcao=0, w = 0, valor;
// criando a lista 
cria_lista(&lista);
//menu
    while ( w == 0 ) {
        printf("1 - Inserir um elemento no inicio\n");
        printf("2 - Inserir um elemento no final\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Remover um elemento\n");
        printf("5 - Esvaziar lista\n");
        printf("6 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
            switch (opcao) {
            case 1:
                system("cls");
                linha();
                printf("Digite um número para inserir no inicio: ");
                scanf("%d", &valor);
                linha();
                insere_cab(&lista, valor);
                break;
            case 2:
                system("cls");
                linha();
                printf("Digite um número para inserir no final: ");
                scanf("%d", &valor);
                linha();
                insere_caud(&lista, valor);     
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
                printf("Digite um elemento para remover da lista: ");
                scanf("%d", &valor);
                remove_element(&lista, valor);
                linha();
                printf("Lista com elemento %d removido:\n", valor);
                imprime(&lista);
                linha();
                break;
            case 5: 
                system("cls");
                linha();
                esvazia(&lista);
                break;
            case 6:
                w = 1;
                break;
            default:
                break;
            }
    }
return 0;
}