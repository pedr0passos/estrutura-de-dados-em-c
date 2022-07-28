#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

void l() {
    printf("\n---------------------------------------------------------------\n");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "portuguese");
    
    FILE *arq = fopen ("entrada.txt", "r");
    FILE *arq2 = fopen ("entrada2.txt", "w");
    
    
    if (arq!=NULL) {
        
        l();
        printf("Arquivo Aberto com sucesso!\n");
        
        char c;
        int n=0;
       
        
        
        while ( fscanf(arq, "%c", &c) == 1 ) {
            fprintf(arq2, "%c", toupper(c));
        }
        
  
        printf("\n%d\n", n);
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

