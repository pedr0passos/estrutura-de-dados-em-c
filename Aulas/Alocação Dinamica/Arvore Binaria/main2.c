#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//ARVORE BINARIA

typedef struct arv_binarie {
    int info;
    struct arv_binarie *direita, *esquerda;
}arvore;

void l () {
    printf("\n--------------------------------------\n");
}

arvore *criar_vazia() {
    return NULL;
}

arvore *criar_arvore(int c, arvore*sae, arvore*sad) {
    arvore *novo = malloc(sizeof(arvore));
    if ( novo!= NULL) {
        novo->info = c;
        novo->esquerda = sae;
        novo->direita = sad;
        return novo;
    } else {
        printf("Não foi possível criar a árvore\n");
        exit(1);
    }
}

int vazia(arvore *arv) {
    return (arv == NULL);
}

void imprime(arvore *arv) {
    printf("<");
    if ( !vazia(arv)) {
        printf("%d", arv->info);
        imprime(arv->esquerda);
        imprime(arv->direita);
    }
    printf(">");
}

arvore *liberar(arvore *arv) {
    if(!vazia(arv)) {
        liberar(arv->esquerda);
        liberar(arv->direita);
        free(arv);
    }
    return NULL;
}

int pertence (arvore *arv, int c) {
    if (!vazia(arv)) {
        if(arv->info == c) {
            return 1;
        } else {
            return pertence(arv->esquerda, c) || pertence(arv->direita, c);
        }
    } else {
        return 0;
    }
}

int quantidade_folhas(arvore *arv) {
    if ( vazia(arv)) {
        return 0;
    } else {
        if (arv->direita == NULL && arv->esquerda == NULL ) {
            return 1;
        } else {
            return quantidade_folhas(arv->esquerda) + quantidade_folhas(arv->direita);
        }
    }
}

int quantidade_caracteres(arvore *arv, int c) {
    if (vazia(arv)) {
        return 0;
    } else {
        if (arv->info == c ) {
            return 1 + quantidade_caracteres(arv->esquerda,c) + quantidade_caracteres(arv->direita,c);
        } else {
            return quantidade_caracteres(arv->esquerda, c) + quantidade_caracteres(arv->direita, c);
        }
    }
}


int igual(arvore *a1, arvore *a2) {
    if ( vazia(a1) && vazia(a2)) {
        return 1;
    } else if ( !vazia(a1) && vazia(a2)){
        return 0;
    } else if ( vazia(a1) && !vazia(a2)) {
        return 0;
    } else {
        if ( a1->info == a2->info ) {
            return ( 1 && igual(a1->esquerda, a2->esquerda) && igual(a1->direita, a2->direita));
        } else {
            return 0;
        }
    }
}

arvore *copia (arvore *arv) {
    if (vazia(arv)) {
        return NULL;
    } else {
        arvore* novo = malloc(sizeof(arvore));
        novo->info = arv->info;
        novo->esquerda = arv->esquerda;
        novo->direita = arv->direita;
        copia(arv->esquerda);
        copia(arv->direita);
        return novo;
    }
}

int maior(arvore*arv) {
    if(vazia(arv)) {
        return -1;
    } else {
        int x = arv->info;
        printf("X inicial> %d\n", x);
        if ( arv->esquerda != NULL ) {
            printf("Entrou Esquerda\n");
            x = maior(arv->esquerda);
            if ( arv->esquerda->info > x ) {
                x = arv->esquerda->info;
            }
        }
         if ( arv->direita != NULL ) {
            printf("Entrou Direita\n");
            x = maior(arv->direita);
            if ( arv->direita->info > x ) {
                x = arv->direita->info;
            }
        }
        printf("X final> %d\n", x);
        return x;


    //     int info_atual = arv->info, maior_info, info_esquerda, info_direita;
    //     maior_info = info_atual;
    //     if ( arv->esquerda != NULL ) {
    //         info_esquerda = maior(arv->esquerda);
    //         if (info_esquerda > maior_info) {
    //             maior_info = info_esquerda;
    //         }
    //     }
    //     if ( arv->direita != NULL ) {
    //         info_direita = maior(arv->direita);
    //         if(info_direita > maior_info ) {
    //             maior_info = info_direita;
    //         }
    //     }
    //     return maior_info;
    // }
    }
}
int main () {

    setlocale(LC_ALL, "portuguese");

    arvore *arv, *arv2, *arv3;
    arvore *d = criar_arvore(1, criar_vazia(), criar_vazia());
    arvore *b = criar_arvore(2, criar_vazia(), d);
    arvore *e = criar_arvore(30, criar_vazia(), criar_vazia());
    arvore *f = criar_arvore(4, criar_vazia(), criar_vazia());
    arvore *c = criar_arvore(5, e, f);
    arvore *a =  criar_arvore(6, b, c);
    arv = a;
    arvore *h = criar_arvore(1, criar_vazia(), criar_vazia());
    arvore *k = criar_arvore(2, criar_vazia(), h);
    arvore *q = criar_arvore(3, criar_vazia(), criar_vazia());
    arvore *g = criar_arvore(4, criar_vazia(), criar_vazia());
    arvore *n = criar_arvore(5, q, g);
    arvore *p =  criar_arvore(6, k, n);
    arv2 = p;
    arv3 = copia(arv2);

    l();
    printf("Arvore 1:\n");
    imprime(arv);
    l();
    printf("Arvore 2:\n");
    imprime(arv2);
    l();
    printf("Arvore Copiada:\n");
    imprime(arv3);
    l();
    printf("Quantidade de Folhas:\n");
    printf("%d", quantidade_folhas(arv));
    l();
    int aux = pertence(arv, 'i');
    if ( aux == 1 ) {
        printf("PERTENCE!\n");
    } else {
        printf("NÃO PERTENCE!\n");
    }
    l();
    printf("Quantidade de números 3:\n");
    printf("%d", quantidade_caracteres(arv, 3));
    l();
    printf("Maior:\n");
    printf("%d", maior(arv));
    l();
    printf("As arvores são iguais ?\n");
    if ( igual(arv, arv2) == 1 ) {
        printf("São iguais\n");
    } else {
        printf("Não são iguais\n");
    }

    return 0;
}