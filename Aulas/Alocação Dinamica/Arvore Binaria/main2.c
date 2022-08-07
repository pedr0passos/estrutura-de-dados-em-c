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


// int igual(arvore *raiz, arvore *raiz2){

//     if ( (raiz == NULL) != (raiz2 == NULL)){
//        return 0;
//     }
//     if ((raiz) == (raiz2)) {
//        return 1;
//     }
//     if ((raiz->info) != (raiz2->info)) {
//        return 0;
//     }
//     if ( !igual(((raiz)->esquerda), (raiz2->esquerda))){ 
//         return 0;
//     }
//     if ( !igual(((raiz)->direita), ((raiz2)->direita))){
//         return 0;
//     }    
//     return 1;
// }

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
        int info_atual = arv->info, maior_info, info_esquerda, info_direita;
        maior_info = info_atual;
        if ( arv->esquerda != NULL ) {
            info_esquerda = maior(arv->esquerda);
            if (info_esquerda > maior_info) {
                maior_info = info_esquerda;
            }
        }
        if ( arv->direita != NULL ) {
            info_direita = maior(arv->direita);
            if(info_direita > maior_info ) {
                maior_info = info_direita;
            }
        }
        return maior_info;
    }
}

int main () {

    setlocale(LC_ALL, "portuguese");

    arvore *arv, *arv2, *arv3;
    arvore *d = criar_arvore(4, criar_vazia(), criar_vazia());
    arvore *b = criar_arvore(3, criar_vazia(), d);
    arvore *e = criar_arvore(93456, criar_vazia(), criar_vazia());
    arvore *f = criar_arvore(98, criar_vazia(), criar_vazia());
    arvore *c = criar_arvore(11, e, f);
    arvore *a =  criar_arvore(23456, b, c);
    arv = a;
    arvore *h = criar_arvore(2, criar_vazia(), criar_vazia());
    arvore *k = criar_arvore(7, criar_vazia(), h);
    arvore *q = criar_arvore(3, criar_vazia(), criar_vazia());
    arvore *g = criar_arvore(1, criar_vazia(), criar_vazia());
    arvore *n = criar_arvore(4, q, g);
    arvore *p =  criar_arvore(27, k, n);
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
    // printf("As arvores são iguais ?\n");
    // if ( igual(arv, arv2) == 1 ) {
    //     printf("São iguais\n");
    // } else {
    //     printf("Não são iguais\n");
    // }

    return 0;
}