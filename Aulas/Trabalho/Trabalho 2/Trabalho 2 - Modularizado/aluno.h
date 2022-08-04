typedef struct lista_amigos Amigos;

typedef struct encadeada_principal Lista;

typedef struct aluno {

    int id;
    char nome[100];
    char curso[100];
    Amigos *amigos;

}Aluno;

void limpa_bufer ();

Aluno *leAluno ();

void imprimeAluno (Aluno *a);

void alterarNome (Aluno *a);

void alterarCurso (Aluno *a);

char *retornaCurso ( Aluno *a );

void puxa(FILE *arquivo, Lista **l);