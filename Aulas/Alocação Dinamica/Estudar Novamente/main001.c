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
        printf("Digite %d n�meros inteiros: \n", n);
        for (int i=0; i < n; i++) {
            scanf("%d", &vet[i]);
        }

        float m = media(vet,n);

        printf("M�dia: %.2f", m);
    } else {
        printf("N�o foi poss�vel fazer aloca��o de mem�ria!");
    }

}