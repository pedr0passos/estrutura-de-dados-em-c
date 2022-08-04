#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//ARVORE BINARIA

typedef struct arv_binarie {
    char info;
    struct arv_binarie *direita, *esquerda;
}arvore;

arvore *criar_vazia() {
    return NULL;
}

arvore *criar_arvore(char c, arvore*sae, arvore*sad) {
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

int pertence(arvore *arv, char c) {

}

void imprime(arvore *arv) {

}

arvore *liberar(arvore *arv) {

}

int main () {

    arvore *arv;
    arvore *d = criar_arvore('d', criar_vazia(), criar_vazia());
    arvore *b = criar_arvore('b', criar_vazia(), d);
    arvore *e = criar_arvore('e', criar_vazia(), criar_vazia());
    arvore *f = criar_arvore('f', criar_vazia(), criar_vazia());
    arvore *c = criar_arvore('c', e, f);
    arvore *a =  criar_arvore('a', b, c);
    arv = a;
    imprime();


    return 0;
}