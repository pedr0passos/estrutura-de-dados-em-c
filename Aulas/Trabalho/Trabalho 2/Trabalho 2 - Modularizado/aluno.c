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

void limpa_bufer () {

	setbuf(stdin, NULL);

}

int identificador = 1; 

//Função que le um novo aluno
Aluno *leAluno () {        

    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

    novo->id = identificador;
    identificador++;
    novo->amigos = NULL;

    printf("Nome: ");
    limpa_bufer();
    scanf("%[^\n]", novo->nome);
    limpa_bufer();
    printf("Curso: ");
    limpa_bufer();
    scanf("%[^\n]", novo->curso);
    limpa_bufer();

    return novo;

}

//Imprime aluno
void imprimeAluno ( Aluno *a ) {     
     
        printf("Nome: %s\t", a->nome);
        printf("Curso: %s\t", a->curso);
        printf("ID: %d\n", a->id);

}

//Altera o nome do aluno na lista
void alterarNome ( Aluno *a ) {

    printf("Digite o nome: ");
    limpa_bufer();
    scanf("%[^\n]", a->nome);
    limpa_bufer();

}

//Altera o curso do aluno na lista
void alterarCurso ( Aluno *a ) {

    printf("Digite o curso: ");
    limpa_bufer();
    scanf("%[^\n]", a->curso);
    limpa_bufer();

}

//Retorna o curso do aluno 
char *retornaCurso ( Aluno *a ) {

    if ( a != NULL ) {

        return a->curso;

    } else {    

        return NULL;

    }

}

void puxa(FILE *arquivo, Lista **l) {
        
    Aluno *a = malloc(sizeof(Aluno));

    //while para ler o arquivo inteiro
    while ( fscanf(arquivo, "%[^\t]\t%d\t%[^\n]\n\t", a->nome, &a->id, a->curso) != EOF ) {

        int id_aux;
        a->amigos = NULL;
        Lista *n = malloc(sizeof(Lista));

        while (fscanf(arquivo, "%d ", &id_aux) == 1 ) {

            Amigos *amigo = malloc(sizeof(Amigos)); 
            amigo->id = id_aux;
            amigo->proximo = a->amigos;
            a->amigos = amigo;
            
        }

        //Atualizando o identificador 
        if ( a->id >= identificador ) {
            identificador = (a->id + 1);
        }
        
        // passando o conteúdo do que foi lido pelo while para o aluno que ser inserido na lista dup encadeada
        n->aluno = *a;

        // colocando o novo aluno na lista e acertando os ponteiros
        if ( *l != NULL ) {

            Lista *p;
            for ( p = *l; p->proximo != NULL; p = p->proximo );
            n->proximo = NULL;
            n->anterior = p;
            p->proximo = n;

        } else {

            n->proximo = NULL;
            n->anterior = NULL;
            *l = n;

        } 
    }
}