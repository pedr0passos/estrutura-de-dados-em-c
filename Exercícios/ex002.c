#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

setlocale(LC_ALL, "portuguese");

int  aux=1, n, i;

    while ( aux > 0 ) {
    printf("Digite um número: ");
    scanf("%d", &n);
    if ( n < 0 ) {
        aux = 0;
    }
    for (i=n; i>=0; i--) {
        printf("%d\n", i);
    }
}

return 0;
}