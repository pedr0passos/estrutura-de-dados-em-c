#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// PILHA COM LISTA ENCADEADA (ALOCAÇÃO DINAMICA)

//estrutura que representa a pilha e dos nós da pilha
typedef struct no {
    int info;
    struct no *proximo;
}nopilha;

typedef struct p {
    nopilha *primeiro;
}pilha;

//FUNÇÕES:

void l() {
    printf("\n-------------------------------------\n");
}

//cria uma pilha vazia
pilha *criar() {
    pilha *p = malloc(sizeof(pilha));
    p->primeiro = NULL;
    return p;
}

//verifica se a pilha está vazia
int vazia(pilha *p) {
    return (p->primeiro == NULL);
}

//insere um elemento no topo da pilha ( p->primeiro )
void push(pilha *p, float v) {
    nopilha *novo = malloc(sizeof(nopilha));
    if ( novo != NULL ) {
        novo->info = v;
        novo->proximo = p->primeiro;
        p->primeiro = novo;
    } else {
        l();
        printf("Não foi possível alocar espaço.");
        l();
    }
}

//remove no topo da pilha (p->primeiro);
int pop(pilha *p) {
    if (!vazia(p)) {
        nopilha *temp = p->primeiro;
        int v = temp->info;
        p->primeiro = temp->proximo;
        free(temp);
        return v;
    } else {
        l();
        printf("Pilha Vazia!");
        l();
        exit(1);
    }
}

//libera a pilha 
void liberar(pilha *p) {
    nopilha *q, *temp;
    for (q = p->primeiro; q!=NULL; q = temp) {
        temp = q->proximo;
        free(q);
    }
    free(p);
    p = criar();
}

int tamanho ( pilha*p) {
    if (vazia(p)) {
        return 0;
    } else {
        int cont=0;
        for ( nopilha *q = p->primeiro; q!= NULL; q = q->proximo) {
            if ( q != NULL ) {
                cont++;
            }
        }
        return cont;
    }
}

//imprime a pilha
void imprime(pilha*p) {
    if (!vazia(p)) {
        for ( nopilha *q = p->primeiro; q!=NULL; q = q->proximo) {
            printf("%d\n", q->info);
        }
    } else {
        l();
        printf("Pilha Vazia!");
        l();
    }
}

//imprime o topo da pilha
float ver_topo (pilha *p) {
    return (p->primeiro->info);
}

void concatena_v1(pilha *p1, pilha *p2) {
    pilha *p3 = criar();
    if (!vazia(p1) && !vazia(p2)) {
        while (p2->primeiro != NULL) {
            push(p3, pop(p2));
        }
        while (p3->primeiro != NULL ) {
            push(p1, pop(p3));
        }
    }
}

void concatena_v2(pilha *p1, pilha*p2) {
    if ( !vazia(p1) && !vazia(p2)) {
        float v = pop(p2);
        concatena_v2(p1, p2);
        push(p1, v);
    }
}

//concatena usando apenas ponteiros 
void concatena_v3(pilha*p1, pilha *p2) {
    nopilha *q;
    for (q = p2->primeiro; q->proximo != NULL; q = q->proximo);
    q->proximo = p1->primeiro;
    p1->primeiro = p2->primeiro;
    free(p2);
}

// void crescente (pilha *p) {
//     if ( vazia(p)) {
//         printf("Pilha Vazia");
//     } else {
//         int x=0, vet[tamanho(p)];
//         for (nopilha *q = p->primeiro; q != NULL; q = q->proximo) {
//             printf("for vetor\n");
//             vet[x] = q->info;
//             x++;
//             printf("adicionou no vetor\n");
//         }
//         pilha *aux = criar();
//         int menor = p->primeiro->info;
//         for ( int i=0; i < tamanho(p); i++ ) {
//             if (vet[i] < menor ) {
//                 printf("if menor\n");
//                 menor = vet[i];
//                 printf("mudou menor\n");
//             }
//         }
//         push(aux, menor);
//         p = aux;
//     }
// }

void maior_menor_media(pilha *p) {
    if ( vazia(p)) {
        printf("Pilha Vazia");
    } else {
        int maior=0, menor = p->primeiro->info;
        for (nopilha *q = p->primeiro; q!= NULL; q = q->proximo) {
            if (q->info > maior) {
                maior = q->info;
            }
            if (q->info < menor) {
                menor = q->info;
            }
        }

        int media = (maior + menor)/2;
        printf("maior: %d\n", maior);
        printf("menor: %d\n", menor);
        printf("media: %d\n", media);
    
    }
}

int topo(pilha *p) {
    if(!vazia(p)) {
        return pop(p);
    } else {
        return -1;
    }
}

int n_pares(pilha *p) {
    if(vazia(p)) {
        return 0;
    } else {
        int cont=0;
        for (nopilha *q = p->primeiro; q!=NULL; q = q->proximo) {
            if ( (q->info)%2 == 0 ) {
                cont++;
            }
        }
        return cont;
    }
}

pilha* copia(pilha *p) {
    int cont=0;
    for(nopilha *q = p->primeiro; q!=NULL; q = q->proximo) {
        if ( q!=NULL) {
            cont++;
        }
    }
    int vet[cont], i=0;
    for(nopilha *q = p->primeiro; q!=NULL; q = q->proximo) {
        if ( q!=NULL) {
            vet[i] = q->info;
            i++;
        }
    }
    pilha*p2= criar();
    i--;
    while(i>=0) {
        push(p2, vet[i]);
        i--;
    }
    return p2;
}

int iguais (pilha*p1, pilha*p2) {
    if(vazia(p1) || vazia(p2)) {
        return 0;
    } else {
        int cont1=0, cont2=0;
        for(nopilha *q = p1->primeiro; q!=NULL; q = q->proximo) {
            cont1++;
            for (nopilha *j = p2->primeiro; j!=NULL; j = j->proximo) {
                if ( j!=NULL) {
                    if (q->info == j->info) {
                        cont2++;
                    }
                }

            }
        }
        if (cont1==cont2) {
            return 1;
        } else {
            return 0;
        }
    }
}

void inverte (pilha *p) {
    if (vazia(p)) {
        printf("vazia");
    } else {
        pilha *aux = criar();
        while(p->primeiro!=NULL) {
            push(aux,pop(p));
        }
        *p = *aux;
    }
}

int maior_pilha (pilha *p1, pilha*p2) {
    if (vazia(p1) || vazia(p2)) {
        return 0;
    } else {
        int maior1=0, maior2=0;
        for (nopilha *q = p1->primeiro; q!=NULL; q = q->proximo) {
            if (q!=NULL) {
                maior1++;
            }
        }
        for (nopilha *q = p2->primeiro; q!=NULL; q = q->proximo) {
            if (q!=NULL) {
                maior2++;
            }
        }
        if(maior1 > maior2) {
            return 1;
        } else if (maior1 == maior2 ){
            return -1;
        } else {
            return 0;
        }
    }
}

int main () {
setlocale(LC_ALL,"portuguese");

    // criando a pilha
    pilha *p1 = criar();
    // pilha *p2 = criar();
    //inserindo na pilha
    push(p1, 1);
    push(p1, 72);
    push(p1, 2);
    push(p1, 5); 
    push(p1, 5); 

    // push(p2, 1); 
    // push(p2, 72);
    // push(p2, 2);
    // push(p2, 5);

    l();
    printf("Pilha 1:\n");
    imprime(p1);
    // l();
    // printf("Tamanho da Pilha: %d\n", tamanho(p1));
    // l();
    // maior_menor_media(p1);
    // l();
    // printf("Topo da Pilha: %d\n", topo(p1));
    // printf("Ordenando a Pilha 1\n");
    // crescente(p1);
    // l();
    // printf("Pilha 1:\n");
    // imprime(p1);
    // l();
    // printf("Quantidade de Pares: %d", n_pares(p1));
    // l();
    printf("Pilha Copiada:\n");
    pilha *p2 = copia(p1);
    imprime(p2);
    l();
    l();
    printf("Pilha 2:\n");
    imprime(p2);
    l();
    printf("São Iguais ?\n");
    if ( iguais(p1,p2) == 1 ) {
        printf("SIM.");
    } else {
        printf("NÃO");
    }
    l();
    printf("Pilha 1 é maior que Pilha 2 ?\n");
    if ( maior_pilha(p1,p2) == 1 ) {
        printf("SIM.");
    } else if ( maior_pilha(p1,p2) == -1 ){
        printf("MESMO TAMANHO.");
    } else {
        printf("NÃO.");
    }
    l();
    printf("Invertendo:\n");
    inverte(p1);
    imprime(p1);
    // printf("Topo Atual da Pilha 1:\n");
    // printf("%.1f", ver_topo(p1));
    // l();
    // printf("Topo Atual da Pilha 2:\n");
    // printf("%.1f", ver_topo(p2));
    // l();
    // pop(p1);
    // printf("Removendo Pilha 1:\n");
    // remove(p1);
    // imprime(p1);
    // l();
    // pop(p2);
    // printf("Removendo Pilha 2:\n");
    // remove(p2);
    // imprime(p2);
    // l();
    // printf("Concatenando com a Versão 3 da Função:\n");
    // concatena_v2(p1,p2);
    // imprime(p1);


    return 0;
}