#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* void inverte (int n, int*v) {
    int vet[n];
    for (int i=0; i<n; i++) {
        vet[i] = v[(n-1) - i];
    }
    for (int i=0; i<10; i++) {
        v[i] = vet[i];
        printf("%d\n", v[i]);
    }
    
} */

void inverte (int n, int*v) {
    int v2[n];
    for ( int i = 0; i<n; i++) {
        v2[i] = v[(n-1)-i];
    }
    for (int i = 0; i<n; i++) {
        v[i] = v2[i]; 
        printf("\n");
        printf("%d\n", v[i]);
    }
}
int main () {

int vet[5] = {1,2,3,4,5};

inverte(5, vet);

return 0;
}