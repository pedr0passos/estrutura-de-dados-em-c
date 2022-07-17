#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct ponto {
    int x;
    int y;
}Ponto;

int dentro_ret (Ponto *ie, Ponto *sd, Ponto *p) {
    if ( p->x >= ie->x && p->x <= sd->x && p->y >= ie->y && p->y < sd->y ) {
        return 1;
    } else {
        return 0;
    }
}


int main () {

Ponto p, inf_esq, sup_dir;
printf("Pontos do Retangulo\n");
printf("Inferior Esquerdo:\n");
scanf("%d", &inf_esq.x);
scanf("%d", &inf_esq.y);
printf("Superior Direito:\n");
scanf("%d", &sup_dir.x);
scanf("%d", &sup_dir.y);
printf("Ponto:\n");
scanf("%d", &p.x);
scanf("%d", &p.y);

printf("%d", dentro_ret(&inf_esq, &sup_dir, &p));

return 0;
}