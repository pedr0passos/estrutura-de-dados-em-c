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

int identificador = 1;

void limpa_bufer () {

	setbuf(stdin, NULL);

}

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
