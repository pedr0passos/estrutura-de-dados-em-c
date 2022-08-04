#include <stdlib.h>
#include <stdio.h>

typedef struct lista_amigos {

    int id;
    struct lista_amigos *proximo;

}Amigos;

typedef struct aluno {

    int id;
    char nome[100];
    char curso[100];
    Amigos *amigos;

}Aluno;

typedef struct encadeada_principal {

    Aluno aluno;
    struct encadeada_principal *proximo;
    struct encadeada_principal *anterior;

}Lista;

//Busca um aluno pelo id e reotna um ponteiro para o mesmo
Lista *buscar_elemento(Lista **l, int id) {  

    Lista *p;

    for ( p = *l; p != NULL && p->aluno.id != id; p = p->proximo );

    if ( p != NULL ) {

        return p;
    
    } else {
    
        printf("\nNão foi encontrado");
        exit(1);
    
    }
    

}

//Inicializa a lista duplamente encadeada
void cria_lista (Lista **l) {    

   *l = NULL;

}

//Verifica se a lista está vazia
int lista_vazia ( Lista **l ) {

    if ( *l == NULL ) {

        return 1;

    } else {

        return 0;

    }

}

//Imprime a lista de amigos de um aluno
void imprime_amigos ( Lista **a, Lista **l ) {  
    
    if(  (*a)->aluno.amigos != NULL ) {

        Lista *i;

        for ( Amigos *p = (*a)->aluno.amigos; p != NULL; p = p->proximo ) {

        i = buscar_elemento( l, p->id );
        
            if ( i != NULL ) {
                
                printf ("%s\n", i->aluno.nome);
            
            } else {

                continue;

            }
                

        }

    } else {

        printf ("Não possui amigos, tadinho dele.");

    }

}

