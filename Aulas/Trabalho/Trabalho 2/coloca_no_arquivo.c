#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void l(){
    printf("\n-----------------------------------------------------\n");
}
void lb(){
    setbuf(stdin, NULL);
}


int main () {
setlocale(LC_ALL,"portuguese");

    FILE *arq = fopen("exemplo.txt", "w");              // abre o arquivo, com 'a' pois é igual o 'w', ele lê porem mantém os dados dentro, ou seja, não exclui a cada nova leitura
    char nome[100], caractere, curso[100];
    int id, amigos;

    if ( arq != NULL ) {

        l();
        printf("Arquivo Aberto com Sucesso!");
        l();

        printf("Digite para colocar no arquivo: ");
        scanf("%[^\n]", nome);
        lb();
        printf("ID: ");
        scanf("%d", &id);
        lb();
        printf("Curso: ");
        scanf("%[^\n]", curso);
        printf ("Lista de Amigos: ");
        scanf("%d", &amigos);
        fprintf(arq, "%s\t%d\t%s\n\t%d\n", nome, id, curso, amigos);                       // coloca dentro do arquivo


        int close = fclose(arq);                        // fecha o arquivo
        if ( close == 0 ) {
            l();
            printf("Arquivo Fechado com Sucesso!");
            l();
        } else {
            l();
            printf("Erro na hora de Fechar o Arquivo!");
            l();
        }

    } else {
        l();
        printf("Arquivo não pode ser aberto");
        l();
    }



return 0;
}