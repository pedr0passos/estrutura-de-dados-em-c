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

//fun��es

// fun��o de linha
void linha(){

    printf("\n------------------------------------------------------\n");

}

// fun��o que atribui NULL a todos os espa�os da lista de tamanho 3
void inicializa ( int n, Aluno **tab) {

    for (int i=0; i<n; i++) {

        tab[i] = NULL;

    }

}
// fun��o que l� um aluno e coloca ele dentro da lista
void leAluno ( int n, Aluno **tab, int i) { // parametros da fun��o: tamanho do vetor; vetor ; posi��o que ser� armazenado

    if ( tab[i] == NULL && i >= 0 && i <= n ) {

        tab[i] = malloc(sizeof(Aluno));

        printf("Digite o nome do aluno: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", tab[i]->nome);
        setbuf(stdin, NULL);
        printf("Digite o n�mero de matr�cula: ");
        scanf("%d", &tab[i]->mat);

    }

}

void imprimeAluno ( int n, Aluno** tab, int i) { // tamanho do vetor; vetor; posi��o que ser� imprimida

    if ( tab[i] != NULL && i >= 0 && i <= n ) {

        system("cls");
        linha();
        printf("\nAluno:\n");
        printf("Nome: %s\t Matr�cula: %d\n", tab[i]->nome, tab[i]->mat);
        linha();
        
    }

}
// fun��o para imprimir todos os alunos da lista
void imprime_tudo (int n, Aluno **tab) {

        for (int i = 0; i < n; i++) {

        linha();
        
            printf("\nAluno:\n");

            if ( tab[i]->nome == NULL && tab[i]->mat == NULL) {

                printf("Nome: ( Vazio ) Matr�cula: ( Vazio )");

            } else {

                printf("Nome: %s\t Matr�cula: %d\n", tab[i]->nome, tab[i]->mat);

            }

        linha();

        }

}


int main () {

    setlocale(LC_ALL,"portuguese");
    // variaveis
    Aluno *tab[TAM];
    int w=0, opcao, aux=0, aux2=0;
    // fun��o que cria_lista
    inicializa(TAM, tab); 
    //menu do programa
    while ( w == 0 ) {

    printf("\nMENU:\n");
    printf("1 - Ler um aluno novo.\n");
    printf("2 - Imprimir os dados de um aluno.\n");
    printf("3 - Imprimir todos os alunos.\n");
    printf("4 - Sair\n");
    printf("Op��o: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

        system("cls");
        linha();
        printf("Digite qual posi��o deseja inserir o novo aluno: ");
        scanf("%d", &aux);

        if ( aux < 0 || aux > 2 ) {

            printf("Posi��o inv�lida!");

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

            printf("Posi��o inv�lida!");

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