#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void l(){
    printf("\n-----------------------------------------------------\n");
}

int main () {
setlocale(LC_ALL,"portuguese");

    FILE *arq = fopen("exemplo.txt", "a");              // abre o arquivo, com 'a' pois é igual o 'w', ele lê porem mantém os dados dentro, ou seja, não exclui a cada nova leitura
    char nome[100], caractere;

    if ( arq != NULL ) {

        l();
        printf("Arquivo Aberto com Sucesso!");
        l();

        printf("Digite para colocar no arquivo: ");
        scanf("%[^\n]", nome);
        fprintf(arq, "%s\n", nome);                       // coloca dentro do arquivo


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