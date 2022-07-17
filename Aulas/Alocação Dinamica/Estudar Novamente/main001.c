#include <stdio.h>
#include <stdlib.h>

float media ( int *v, int n) {
    int soma = 0, i; 
    for ( i=0; i<n; i++) {
        soma += v[i];
    }
}

int main () {

int n = 5;
int *vet = (int*)malloc(n*sizeof(int)); // <=> int vet[n]

    if ( vet != NULL) {
        printf("Digite %d números inteiros: \n", n);
        for (int i=0; i < n; i++) {
            scanf("%d", &vet[i]);
        }

        float m = media(vet,n);

        printf("Média: %.2f", m);
    } else {
        printf("Não foi possível fazer alocação de memória!");
    }

}