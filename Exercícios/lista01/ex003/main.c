#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double somatorio (int n) {
    double soma=0, i;
    for (i=0; i<=n; i++) {
         soma += pow(-1, i)/((2*i) + 1);
    }
    return 4*soma;
}


int main () {
setlocale(LC_ALL,"portuguese");

printf("Somátorio: %lf", somatorio(500000));

return 0;
}