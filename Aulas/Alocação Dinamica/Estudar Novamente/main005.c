#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno {
    char nome[80];
    int matricula;
}Aluno;

 void inicializa (int n, Aluno** tab) {
     for (int i=0; i<n; i++) {
         tab[i] = NULL;
     }
}

void leALuno ( int n, Aluno** tab, int i) {
    if ( i >= 0 && i < n && tab[i]==NULL) {
        tab[i] = (Aluno*)malloc(sizeof(Aluno));
        printf("Digite o nome do aluno: \n");
        scanf("%[^\n]", tab[i]->nome);
        printf("Digite a matrícula: ");
        scanf("%d", &tab[i]->matricula);
    } else {
        printf("Posição Inválida!");
    }
}
void imprimeAluno ( int n, Aluno** tab, int i) {
    
}
void retiraAluno ( int n, Aluno** tab, int i) {
    
}
void imprime_tudo(int n, Aluno** tab) {
    
} 
int main () {

    
    Aluno* tab[3] = (Aluno*)malloc(sizeof(Aluno));
    printf("Digite nome do aluno: ");
    setbuf(stdin, NULL);
    scanf("Nome: %s Matrí­cula: %d", &aluno.nome[80], &aluno.matricula);
    
return 0;
} 