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

void imprime_in(arvore *a) {
    if (!vazia(a)) {
        imprime_in(a->esquerda);
        printf("%d\n", a->info);
        imprime_in(a->direita);
    } else {

    }
}

void imprime_pos(arvore *a) {
    if(!vazia(a)) {
        imprime_pos(a->esquerda);
        imprime_pos(a->direita);
        printf("%d\n",a->info);
    }
}

int presente(arvore *a, int v) {
    if (vazia(a)) {
        return 0;
    } else {
        if (a->info == v) {
            return 1;
        } else {
            return (presente(a->esquerda,v) || presente(a->direita,v)); 
        }
    }
}

int quantidade_de_nos(arvore *a) {
    if (vazia(a)) {
        return 0;
    } else {
        return 1 + (quantidade_de_nos(a->esquerda) + quantidade_de_nos(a->direita));
    }
}

int media(arvore *a) {
    if (vazia(a)) {
        return 0;
    } else {
       return ( (a->info + media(a->esquerda) + media(a->direita))/(quantidade_de_nos(a))); 
    }
}

int quant_nulls(arvore *a) {
    if (vazia(a)) {
        return 1;
    } else {
        return 0 + quant_nulls(a->esquerda) + quant_nulls(a->direita);
    }
}

int soma(arvore *a) {
    if (vazia(a)) {
        return 0;
    } else {
        return (a->info + soma(a->esquerda) + soma(a->direita));
    }
}

int altura (arvore *a) {
    if (vazia(a)) {
        return -1;
    } else {
        int altura_e = altura(a->esquerda);
        int altura_d = altura(a->direita);
        if (altura_e < altura_d) {
            return altura_e + 1;
        } else {
            return altura_d + 1;
        }
    }
}

int verifica(arvore *a) {
    if (vazia(a)) {
        return 1;
    } else {
        if ( (a->esquerda !=NULL && a->direita!=NULL) || (a->esquerda == NULL && a->direita == NULL)) {
            return 1 && verifica(a->esquerda) && verifica(a->direita);
        } else {
            return 0;
        }
    }

}

void espelha (arvore *a) {
    if (vazia(a)) {
        return NULL;
    } else {
        espelha(a->esquerda);
        espelha(a->direita);
        arvore *aux = a->esquerda;
        a->esquerda = a->direita;
        a->direita= aux;
        }
        
    }


int main () {

    setlocale(LC_ALL, "portuguese");

    arvore *arv, *arv2, *arv3;
    arvore *oito = criar_arvore(8, criar_vazia(),criar_vazia());
    arvore *um = criar_arvore(1, criar_vazia(), criar_vazia());
    arvore *tres = criar_arvore(3, criar_vazia(), criar_vazia());
    arvore *dois = criar_arvore(2, um, tres);
    arvore *cinco = criar_arvore(5, criar_vazia(), criar_vazia());
    arvore *dez = criar_arvore(10, oito, criar_vazia());
    arvore *seis = criar_arvore(6, cinco, dez);
    arvore *quatro =  criar_arvore(4, dois, seis);
    arv = quatro;
    arvore *h = criar_arvore(1, criar_vazia(), criar_vazia());
    arvore *k = criar_arvore(2, criar_vazia(), h);
    arvore *q = criar_arvore(3, criar_vazia(), criar_vazia());
    arvore *g = criar_arvore(4, criar_vazia(), criar_vazia());
    arvore *n = criar_arvore(5, q, g);
    arvore *p =  criar_arvore(6, k, n);
    arv2 = p;
    arv3 = copia(arv2);

    l();
    printf("Arvore (Pré Ordem):\n");
    imprime(arv);
    l();
    printf("Arvore (In Ordem):\n");
    imprime_in(arv);
    l();
    printf("Arvore (Pós Ordem):\n");
    imprime_pos(arv);
    l();
    // printf("Media dos Valores:\n");
    // printf("%d", media(arv));
    // l();
    printf("Quantidade de Nulls:\n");
    printf("%d", quant_nulls(arv));
    l();
    printf("Soma das Informações:\n");
    printf("%d", soma(arv));
    l();
    printf("Altura da Arvore:\n");
    printf("%d", altura(arv));
    l();
    printf("É Cheia?\n");
    if ( verifica(arv) == 1) {
        printf("SIM.");
    } else {
        printf("NÃO");
    }
    l();
    printf("Espelhando\n");
    espelha(arv);
    imprime(arv);
    // printf("Arvore 2:\n");
    // imprime(arv2);
    // l();
    // printf("Arvore Copiada:\n");
    // imprime(arv3);
    // l();
    // printf("Quantidade de Folhas:\n");
    // printf("%d", quantidade_folhas(arv));
    // l();
    // int aux = pertence(arv, 'i');
    // if ( aux == 1 ) {
    //     printf("PERTENCE!\n");
    // } else {
    //     printf("NÃO PERTENCE!\n");
    // }
    // l();
    // printf("Quantidade de números 3:\n");
    // printf("%d", quantidade_caracteres(arv, 3));
    // l();
    // printf("Maior:\n");
    // printf("%d", maior(arv));
    // l();
    // printf("As arvores são iguais ?\n");
    // if ( igual(arv, arv2) == 1 ) {
    //     printf("São iguais\n");
    // } else {
    //     printf("Não são iguais\n");
    // }

    return 0;
}