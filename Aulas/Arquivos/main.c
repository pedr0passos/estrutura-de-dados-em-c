#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void l() {
    printf("\n---------------------------------------------------------------\n");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "portuguese");
    
    FILE *arq = fopen ("entrada.txt", "w");
    
    if (arq!=NULL) {
        l();
        printf("Arquivo Aberto com sucesso!\n");
        char nome[100];
        
        printf("Digite seu nome: ");
        scanf("%[^\n]", nome);
        fprintf(arq, "%s", nome);
        
        
//        while ( fscanf(arq, "%c", &c) == 1 ) {
//            printf("%c\n", c);
//        }
        
//        while ( (c = fgetc (arq)) != EOF ) {
//            printf("%c\n", c);
//        }
        
        int x = fclose(arq);
        
        if ( x == 0 ) {
            
            printf("Arquivo Fechado com Sucesso!");
            l();
        }
        
    } else {
        
        printf("Não foi possível abrir o arquivo!\n");
        
    }

    return (EXIT_SUCCESS);
    
}

