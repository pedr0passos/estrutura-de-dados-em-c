#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int numero_primo (int n) {
    int cont=0;
    for (int i = 1; i<=n; i++) {
        if (n%i == 0) {
            cont++;
        }
    }
    if ( cont == 2 ) {
        printf("O número é primo");
        return 1;
    } else {
        printf("O número não é primo");
        return 0;
    }
}

int main () {
setlocale(LC_ALL, "portuguese");

numero_primo(16);

return 0;
}