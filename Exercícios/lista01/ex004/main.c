#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct num_real {
    int left;
    int right;
}Numero;

void le_real ( Numero *r ) {
    printf("Digite a parte inteira do número: ");
    scanf("%d", &r->left);
    printf("Digite a parte fracionaria do número: ");
    scanf("%d", &r->right);
}

void imprime_real ( Numero *r ) {
    printf("%d,%d\n", r->left, r->right);
}

Numero soma_termos ( Numero *r1, Numero *r2) {
    Numero soma;
    soma.left = r1->left + r2->left;
    soma.right = r1->right + r2->right;
    return soma;
}

int main () {
setlocale(LC_ALL,"portuguese");

Numero real;
Numero real2;
le_real(&real);
le_real(&real2);
imprime_real(&real);
imprime_real(&real2);
Numero real3 = soma_termos(&real, &real2);
printf("Soma dos Termos: %d,%d", real3);
return 0;
}