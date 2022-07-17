#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 3   // tamanho max da lista

// struct de cada aluno da lista
typedef struct aluno {

    char nome[80];
    int  mat;

} Aluno;

//funções

// função de linha
void linha(){

    printf("\n------------------------------------------------------\n");

}

// função que atribui NULL a todos os espaços da lista de tamanho 3
void inicializa ( int n, Aluno **tab) {

    for (int i=0; i<n; i++) {

        tab[i] = NULL;

    }

}
// função que lê um aluno e coloca ele dentro da lista
void leAluno ( int n, Aluno **tab, int i) { // parametros da função: tamanho do vetor; vetor ; posição que será armazenado

    if ( tab[i] == NULL && i >= 0 && i <= n ) {

        tab[i] = malloc(sizeof(Aluno));

        printf("Digite o nome do aluno: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", tab[i]->nome);
        setbuf(stdin, NULL);
        printf("Digite o número de matrícula: ");
        scanf("%d", &tab[i]->mat);

    }

}

void imprimeAluno ( int n, Aluno** tab, int i) { // tamanho do vetor; vetor; posição que será imprimida

    if ( tab[i] != NULL && i >= 0 && i <= n ) {

        system("cls");
        linha();
        printf("\nAluno:\n");
        printf("Nome: %s\t Matrícula: %d\n", tab[i]->nome, tab[i]->mat);
        linha();
        
    }

}
// função para imprimir todos os alunos da lista
void imprime_tudo (int n, Aluno **tab) {

        for (int i = 0; i < n; i++) {

        linha();
        
            printf("\nAluno:\n");

            if ( tab[i]->nome == NULL && tab[i]->mat == NULL) {

                printf("Nome: ( Vazio ) Matrícula: ( Vazio )");

            } else {

                printf("Nome: %s\t Matrícula: %d\n", tab[i]->nome, tab[i]->mat);

            }

        linha();

        }

}


int main () {

    setlocale(LC_ALL,"portuguese");
    // variaveis
    Aluno *tab[TAM];
    int w=0, opcao, aux=0, aux2=0;
    // função que cria_lista
    inicializa(TAM, tab); 
    //menu do programa
    while ( w == 0 ) {

    printf("\nMENU:\n");
    printf("1 - Ler um aluno novo.\n");
    printf("2 - Imprimir os dados de um aluno.\n");
    printf("3 - Imprimir todos os alunos.\n");
    printf("4 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

        system("cls");
        linha();
        printf("Digite qual posição deseja inserir o novo aluno: ");
        scanf("%d", &aux);

        if ( aux < 0 || aux > 2 ) {

            printf("Posição inválida!");

        } else {

            leAluno(TAM, tab, aux);

        }

        break;

    case 2: 

        system("cls");
        linha();
        printf("Digite qual aluno deseja imprimir: ");
        scanf("%d", &aux2);

        if ( aux < 0 || aux > 2 ) {

            printf("Posição inválida!");

        } else {

            imprimeAluno(TAM, tab, aux2);

        }

        break;

    case 3:

        imprime_tudo(TAM, tab);
        break;

    case 4: 

        w = 1;
        break;

    default:
        break;
    }
    }

return 0;

}