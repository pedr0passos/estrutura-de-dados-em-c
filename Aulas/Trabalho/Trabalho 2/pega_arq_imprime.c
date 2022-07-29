#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void l(){
    printf("\n-----------------------------------------------------\n");
}

int main () {
setlocale(LC_ALL,"portuguese");

    FILE *arq = fopen("exemplo.txt", "r");              // abre o arquivo, com 'r' de read
    char nome[100], caractere;

    if ( arq != NULL ) {

        l();
        printf("Arquivo Aberto com Sucesso!");
        l();

        while ( fscanf(arq, "%c", &caractere) == 1) {   // pega do arquivo e imprime
            printf("%c", caractere);
        }


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