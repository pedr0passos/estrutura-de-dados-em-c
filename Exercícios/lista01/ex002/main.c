#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma_impares (int n) {
    int soma = 0;
    for ( int i = 1; i < 2*n; i = i + 2 ) {
        soma += i;
    }
    return soma;
}


int main () {
setlocale(LC_ALL, "portuguese");

printf("Soma: %d", soma_impares(9));

    return 0;
}