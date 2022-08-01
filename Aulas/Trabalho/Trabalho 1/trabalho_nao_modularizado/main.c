#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int identificador = 1; // contador do identificador dos alunos

/*----------------------------------------------------------------------------
 ESTRUTURAS DO PROGRAMA:
----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------
                            FUNÇÕES ADICIONAIS:
----------------------------------------------------------------------------*/

// função que busca um elemento 
Lista *buscar_elemento(Lista **l, int id) {  

    Lista *p;

    for ( p = *l; p != NULL && p->aluno.id != id; p = p->proximo );

    if ( p->aluno.id == id ) {
    
        return p;
    
    } else {
    
        printf("Identificador não encontrado\n");
        return NULL;
    
    }

}

// função que pula linha 
void pl () {

    printf("\n");

}

// cria a lista
void cria_lista (Lista **l) {    

   *l = NULL;

}

// limpa o bufer
void limpa_bufer () {    

    setbuf(stdin, NULL);

}

// cria uma linha separadora 
void linha () {

    printf("\n-----------------------------------------------------------------\n");

}

// função que verifica se ela esta vazia 
int lista_vazia ( Lista **l ) {

    if ( *l == NULL ) {

        return 1;

    } else {

        return 0;

    }

}

// remove um amigo da lista de amigos de um aluno
void remove_amigo ( Amigos **l, int v ) {

    Amigos *p, *ant = NULL;
    
    for ( p = *l; p !=NULL && p->id != v; p = p->proximo) { 

        ant = p;

    } 
    
    if ( ant == NULL ) {  

        *l = p->proximo;

    } else {

        ant->proximo = p->proximo;

    } 

    free(p);

}

// imprime a lista de amigos de um aluno
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

        printf ("Não possui amigos!");

    }

}

// insere uma relação de amizade
void inserir_amigo ( Amigos **l, int v) {

    Amigos *amigo = malloc(sizeof(Amigos));

    if ( amigo != NULL) {

        amigo->id = v;
        amigo->proximo = *l;
        *l = amigo;

    }

    else {

        printf ("Não foi possível alocar espaço!");

    }

}

// puxa dados do arquivo
void puxa(Lista **l) {

}

/*----------------------------------------------------------------------------
                            FUNÇÕES OBRIGATÓRIAS:
----------------------------------------------------------------------------*/

// função que le um novo aluno
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

// imprime aluno
void imprimeAluno (Aluno *a) {     
     
        printf("Nome: %s\t", a->nome);
        printf("Curso: %s\t", a->curso);
        printf("ID: %d\n", a->id);

}

// altera o nome do aluno na lista
void alterarNome (Aluno *a) {

    printf("Digite o nome: ");
    limpa_bufer();
    scanf("%[^\n]", a->nome);
    limpa_bufer();

}

// altera o curso do aluno na lista
void alterarCurso (Aluno *a) {

    printf("Digite o curso: ");
    limpa_bufer();
    scanf("%[^\n]", a->curso);
    limpa_bufer();

}

// retorna o curso do aluno 
char *retornaCurso ( Aluno *a ) {

    if ( a != NULL ) {

        return a->curso;

    } else {    

        return NULL;

    }

}

/*----------------------------------------------------------------------------
                                    MENU:
----------------------------------------------------------------------------*/

int main () {
setlocale(LC_ALL,"portuguese");

// variaveis
Lista *lista;
int opcao,close, w = 0, id_aux=0;
char aux;

FILE *arq = fopen("dados.txt", "r");    
cria_lista(&lista);

// verifica se o arquivo foi aberto
if ( arq != NULL ) {

    pl();
    printf("Arquivo Aberto");
    pl();

}
        
Aluno *a = malloc(sizeof(Aluno));

//while para ler o arquivo inteiro
while (fscanf(arq, "%d", &aux) != EOF) {

    Lista *n = malloc(sizeof(Lista));

    // while que le as informações de cada aluno
    while ( fscanf(arq, "%[^\t]%d%[^\n]", &a->nome, &a->id, &a->curso) == 1 ) {    

        while ( fscanf(arq, "%d ", &a->amigos->id) == 1 ) {
            Amigos *amigo = malloc(sizeof(Amigos));
            
            if ( amigo != NULL) {

                a->amigos->id = amigo->id;
                amigo->proximo = a->amigos;
                a->amigos = amigo;

            }

            else {

                printf ("Não foi possível alocar espaço!");

            }
        }
    }

}

    //Atualizando o identificador 
    if ( a->id >= identificador ) {
        identificador = (a->id + 1);
    }
    
    // passando o conteúdo do que foi lido pelo while para o aluno que ser inserido na lista dup encadeada
    n->aluno = *a;

    // colocando o novo aluno na lista e acertando os ponteiros
    if ( !lista_vazia(&lista)) {

        Lista *p;
        for ( p = lista; p->proximo != NULL; p = p->proximo );
        n->proximo = NULL;
        n->anterior = p;
        p->proximo = n;

    } else {

        n->proximo = NULL;
        n->anterior = NULL;
        lista = n;

    }
} 


    
close = fclose(arq);
// puxa(lista);
arq = fopen("dados.txt", "r");
while ( w == 0 ) {

    printf("\n-------------------------PEDRO E CATTERINA-------------------------\n");
    pl();
    printf("Escolha a opção desejada:\n");
    pl();
    printf("1 - Inserir um novo aluno\n");
    printf("2 - Alterar os dados de um aluno\n");
    printf("3 - Remover um aluno\n");
    printf("4 - Imprimir a lista de alunos\n");
    printf("5 - Inserir relação de amizade\n");
    printf("6 - Remover relação de amizade\n");
    printf("7 - Imprimir amigos de um aluno\n");
    printf("8 - Imprimir a lista de alunos por curso\n");
    printf("9 - Sair\n");
    linha();
    pl();
    printf("OPÇÃO: ");
    scanf("%d", &opcao);
    
    switch (opcao){

        case 1:;    // ADICIONANDO ALUNO À LISTA

            linha();
            printf("INSERINDO ALUNO: \n");
            pl();
            Lista *aluno_novo = malloc(sizeof(Lista));
            aluno_novo->aluno = *leAluno();

            if ( !lista_vazia(&lista) ) {

                if ( lista->proximo == NULL && lista->anterior == NULL ) {                                   // com apenas 1 termo na lista
                                        
                    if ( strcmp (aluno_novo->aluno.nome, lista->aluno.nome) > 0 ) {

                        lista->proximo = aluno_novo;
                        aluno_novo->proximo = NULL;
                        aluno_novo->anterior = lista;

                    } else {

                        lista->anterior = aluno_novo;
                        aluno_novo->anterior = NULL;
                        aluno_novo->proximo = lista;
                        lista = aluno_novo;

                    }

                } else {                                                            // com 2 ou mais termos 

                    if ( strcmp(aluno_novo->aluno.nome, lista->aluno.nome) < 0 ) {

                        lista->anterior = aluno_novo;
                        aluno_novo->proximo = lista;
                        aluno_novo->anterior = NULL;
                        lista = aluno_novo;

                    } else {
                        
                        Lista *p;

                        for ( p = lista; p->proximo != NULL && strcmp (aluno_novo->aluno.nome, p->aluno.nome ) > 0 ; p = p->proximo );
                            
                        if ( strcmp (aluno_novo->aluno.nome, p->aluno.nome ) < 0 ) {

                            aluno_novo->proximo = p;
                            p->anterior->proximo = aluno_novo;
                            aluno_novo->anterior = p->anterior;
                            p->anterior = aluno_novo;

                        } else if ( p->proximo == NULL ){

                            p->proximo = aluno_novo;
                            aluno_novo->proximo = NULL;
                            aluno_novo->anterior = p;

                        }

                    }

                }

            } else {
                
                lista = aluno_novo;
                aluno_novo->proximo = NULL;
                aluno_novo->anterior = NULL;

            }

            break;
            
        case 2:;    // ALTERANDO OS DADOS DE UM ALUNO

            int id_busca;
            Lista *busca_1;

            if ( !lista_vazia(&lista)) {

                // ler o id
                printf("Digite o ID do aluno para alterar os dados:\n");
                printf("ID: ");
                scanf("%d", &id_busca);
                busca_1 = buscar_elemento(&lista, id_busca);
                alterarNome(&busca_1->aluno);
                alterarCurso(&busca_1->aluno);

            } else {

                linha();
                printf("Lista esta vazia!");
                linha();

            }

            break;
        case 3:;   

         // REMOVENDO ALUNO DA LISTA

            int id = 0;
            linha();

            printf("\nRemovendo:\n");
            printf("Digite o identificador do aluno: ");
            scanf("%d", &id);

            Lista *busca_3 = buscar_elemento(&lista, id);
            Lista *busca_3_for;

            for( Amigos *p = busca_3->aluno.amigos; p!=NULL; p=p->proximo) {

                busca_3_for = buscar_elemento(&lista, p->id);
                remove_amigo(&busca_3_for->aluno.amigos, id);
                
            }

            if ( busca_3 != NULL ) {

                if ( busca_3->anterior == NULL  ) {                                     // REMOVENDO NO INICIO DA LISTA
    
                    lista = busca_3->proximo;
                    lista->anterior = NULL;
                    busca_3->proximo = NULL;
                    
                } else if ( busca_3->anterior != NULL && busca_3->proximo != NULL ) {   // REMOVENDO NO MEIO DA LISTA

                    busca_3->anterior->proximo = busca_3->proximo;
                    busca_3->proximo->anterior = busca_3->anterior;

                } else {                                                                // REMOVENDO NO FINAL

                    busca_3->anterior->proximo = NULL;
                    busca_3->anterior = NULL;

                }

                free(busca_3);                  
            
            } else {

                linha();
                printf("Aluno Não encontrado!");
                linha();

            }

            break;

        case 4:;    // IMPRIMINDO A LISTA

            if ( !lista_vazia(&lista) ) {

                for ( Lista *p = lista; p!=NULL; p = p->proximo) {

                    imprimeAluno(&p->aluno);

                }

            } else {

                linha();
                printf("Lista está vazia!");
                linha();

            }

            break;

        case 5:;    //INSERINDO RELAÇÃO DE AMIZADE
            
            int id_amigo_1, id_amigo_2;

            printf("INSERINDO RELAÇÃO DE AMIZADE:\n");
            printf("Digite o primeiro ID: ");
            scanf("%d", &id_amigo_1);
            Lista *busca_amigo_1 = buscar_elemento(&lista, id_amigo_1);
            printf("Digite o segundo ID: ");
            scanf("%d", &id_amigo_2);
            Lista *busca_amigo_2 = buscar_elemento(&lista, id_amigo_2);
            inserir_amigo(&busca_amigo_1->aluno.amigos, id_amigo_2);
            inserir_amigo(&busca_amigo_2->aluno.amigos, id_amigo_1);

            break;
        
        case 6:;    //REMOVENDO RELAÇÃO DE AMIZADE

            printf("REMOVENDO RELAÇÃO DE AMIZADE:\n");
            printf("Digite o primeiro ID: ");
            scanf("%d", &id_amigo_1);
            Lista *busca_amigo_3 = buscar_elemento(&lista, id_amigo_1);
            printf("Digite o segundo ID: ");
            scanf("%d", &id_amigo_2);
            Lista *busca_amigo_4 = buscar_elemento(&lista, id_amigo_2);
            remove_amigo(&busca_amigo_3->aluno.amigos, id_amigo_2);
            remove_amigo(&busca_amigo_4->aluno.amigos, id_amigo_1);
            
            break;

        case 7:;    // IMPRIMINDO A LISTA DE AMIGOS DE UM ALUNO 
        
            int id_amz;
            
            printf("Digite o ID do aluno que queira imprimir a lista de amigos:\n ");
            linha();
            printf("ID: ");
            scanf("%d", &id_amz);
            Lista *p = buscar_elemento(&lista, id_amz);
            printf("\nLISTA DE AMIGOS:\n");
            imprime_amigos(&p, &lista);

            break;

        case 8:;    // IMPRIMINDO LISTA DE ALUNOS DO MESMO CURSO

            char busca_curso[100];
            linha ();
            printf("IMPRIMINDO ALUNOS POR CURSO");
            linha();

            if ( !lista_vazia(&lista) ) {

                printf("Nome do curso: ");
                limpa_bufer();
                scanf("%[^\n]", busca_curso);
                limpa_bufer();

                pl();

                for ( Lista *p = lista; p!= NULL; p = p->proximo) {


                    if ( strcmp (busca_curso, retornaCurso(&p->aluno)) == 0 ) {

                        imprimeAluno(&p->aluno);

                    }

                }

            } else {

                linha();
                printf("\nLista de Alunos Vazia!\n");
                linha();

            }

            break;

        case 9:;    // ENCERRANDO O PROGRAMA 
            
            arq = fopen("dados.txt", "w");
            for ( Lista *p = lista; p != NULL; p = p->proximo ) {
                fprintf(arq,"%s\t%d\t%s\n", p->aluno.nome, p->aluno.id, p->aluno.curso);
                    for ( Amigos *a = p->aluno.amigos; a != NULL; a = a->proximo) {
                        fprintf(arq, "\t");
                        fprintf(arq, "%d", a->id);
                        fprintf(arq, " ");
                    }
                    fprintf(arq,"\n");
            }

            close = fclose(arq);

            if ( close == 0 ) {

                linha();
                printf("Programa Encerrado.");
                linha();
                w = 1;
                
            } else {

                linha();
                printf("Erro de Arquivo.");
                linha();

            }

            break;

        default:;

            linha();
            printf("Opção Inválida! Execute novamente.");
            linha();
            w = 1;
            break;

        }
    }

return 0;

}