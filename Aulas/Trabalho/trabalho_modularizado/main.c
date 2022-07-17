#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "amigos.h"
#include "aluno.h"
#include "lista.h"

//Cria uma linha separadora 
void linha () {

    printf("\n-----------------------------------------------------------------\n");

}

//Função que pula linha 
void pl () {

    printf("\n");

}

int main () {
setlocale(LC_ALL,"portuguese");

Lista *lista ;
int opcao, w = 0; 

cria_lista(&lista);

while ( w == 0 ) {

    printf("\n------------------------PEDRO E CATTERINA------------------------\n");
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

        case 1:;    //INSERE UM ALUNO NA LISTA

            linha();
            printf("INSERINDO ALUNO:");
            linha();
            Lista *aluno_novo = malloc(sizeof(Lista));
            aluno_novo->aluno = *leAluno();

            //ORDENAÇÃO DA LISTA ( ORDEM ALFABÉTICA)

            if ( !lista_vazia(&lista)) {   
                
                if ( lista->proximo == NULL && lista->anterior == NULL ) {      //INSERE QUANDO HÁ APENAS 1 ELEMENTO NA LISTA                           
                                        
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

                } else {    //COM DOIS OU MAIS ELEMENTOS NA LISTA

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

            } else {    //INSERE O PRIMEIRO ALUNO
                
                lista = aluno_novo;
                aluno_novo->proximo = NULL;
                aluno_novo->anterior = NULL;

            }

            break;
            
        case 2:;    //ALTERA OS DADOS DE UM ALUNO

            int id_busca;
            Lista *busca_1;

            if ( !lista_vazia(&lista)) {

                // ler o id
                linha();
                printf("ALTERANDO DADOS:");
                linha();
                printf("ID: ");
                scanf("%d", &id_busca);
                busca_1 = buscar_elemento(&lista, id_busca);

                if ( busca_1 != NULL ) {
                    
                    alterarNome(&busca_1->aluno);
                    alterarCurso(&busca_1->aluno);

                } else {

                    linha();
                    printf("O ID não existe.");
                    linha();

                }

            } else {

                linha();
                printf("Lista esta vazia!");
                linha();
                
            }

            break;

        case 3:;   //   REMOVE UM ALUNO

            int id = 0;

            linha();
            printf("REMOVENDO UM ALUNO:");
            linha();
            printf("ID: ");
            scanf("%d", &id);

            Lista *busca_3 = buscar_elemento(&lista, id);
            Lista *busca_3_for;

            if ( busca_3 != NULL ) {

            for( Amigos *p = busca_3->aluno.amigos; p!=NULL; p=p->proximo) {

                busca_3_for = buscar_elemento(&lista, p->id);
                remove_amigo(&busca_3_for->aluno.amigos, id);
                
            }

                if ( busca_3->anterior == NULL  ) {     // REMOVE NO INICIO DA LISTA
    
                    lista = busca_3->proximo;
                    lista->anterior = NULL;
                    busca_3->proximo = NULL;
                    
                } else if ( busca_3->anterior != NULL && busca_3->proximo != NULL ) {       // REMOVE NO MEIO DA LISTA
                    busca_3->anterior->proximo = busca_3->proximo;
                    busca_3->proximo->anterior = busca_3->anterior;

                } else {        //REMOVE NO FIM DA LISTA

                    busca_3->anterior->proximo = NULL;
                    busca_3->anterior = NULL;

                }

                free(busca_3);                  
            
            } else {    // CASE O ALUNO NÃO SEJA ENCONTRADO 

                linha();
                printf("Aluno não encontrado!");
                linha();

            }

            break;

        case 4:;    // IMPRIME A LISTA DE ALUNOS

            printf("\n-----------------------------ALUNOS-----------------------------\n\n");    

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

        case 5:;    // INSERE RELAÇÃO DE AMIZADE
            
            int id_amigo_1, id_amigo_2;
            
            linha();
            printf("INSERINDO RELAÇÃO DE AMIZADE:");
            linha();

            printf("1°ID: ");
            scanf("%d", &id_amigo_1);
            Lista *busca_amigo_1 = buscar_elemento(&lista, id_amigo_1);
            printf("2°ID: ");
            scanf("%d", &id_amigo_2);
            Lista *busca_amigo_2 = buscar_elemento(&lista, id_amigo_2);
            inserir_amigo(&busca_amigo_1->aluno.amigos, id_amigo_2);
            inserir_amigo(&busca_amigo_2->aluno.amigos, id_amigo_1);

            break;
        
        case 6:;    // REMOVE RELAÇÃO DE AMIZADE
            
            linha();
            printf("REMOVENDO RELAÇÃO DE AMIZADE:");
            linha();

            printf("1°ID: ");
            scanf("%d", &id_amigo_1);
            Lista *busca_amigo_3 = buscar_elemento(&lista, id_amigo_1);
            printf("2°ID: ");
            scanf("%d", &id_amigo_2);
            Lista *busca_amigo_4 = buscar_elemento(&lista, id_amigo_2);
            remove_amigo(&busca_amigo_3->aluno.amigos, id_amigo_2);
            remove_amigo(&busca_amigo_4->aluno.amigos, id_amigo_1);
            
            break;

        case 7:;    //IMPRIME A LISTA DE AMIGOS 
        
            int id_amz;

            linha();            
            printf("IMPRIMINDO AMIGOS DE UM ALUNO:");
            linha();

            printf("ID: ");
            scanf("%d", &id_amz);
            Lista *p = buscar_elemento(&lista, id_amz);
            printf("\nLista de amigos de %s:\n", p->aluno.nome);
            pl();
            imprime_amigos(&p, &lista);

            break;

        case 8:;    // IMPRIME OS ALUNOS DE UM CURSO ESPECIFICO 

            char busca_curso[100];
            linha();
            printf("IMPRIMINDO ALUNOS POR CURSO:");
            linha();

            if ( !lista_vazia(&lista) ) {

                printf("Nome do curso: ");
                limpa_bufer();
                scanf("%[^\n]", busca_curso);
                limpa_bufer();
                int contador = 0;

                pl();

                for ( Lista *p = lista; p!= NULL; p = p->proximo) {


                    if ( strcmp (busca_curso, retornaCurso(&p->aluno)) == 0 ) {

                        contador++;
                        imprimeAluno(&p->aluno);

                    }

                }

                if ( contador == 0 ) {

                    linha();
                    printf("Não existe alunos desse curso na lista.");
                    linha();

                }

            } else {

                linha();
                printf("Lista de Alunos Vazia!");
                linha();

            }

            break;

        case 9:;    // ENCERRA O PROGRAMA

            linha();
            printf("Programa Encerrado.");
            linha();
            w = 1;
            break;

        default:;   // DEFAULT  

            linha();
            printf("Opção Inválida! Execute novamente.");
            linha();
            w = 1;
            break;

        }
    }

return 0;

}
