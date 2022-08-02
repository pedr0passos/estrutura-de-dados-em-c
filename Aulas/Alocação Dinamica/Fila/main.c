#include <stdio.h>
#include <stdlib.h>

// structs da fila com lista 
typedef struct no {
    float info;
    struct no *proximo;
}NoLista;

typedef struct fila {
    NoLista *inicio;    // ponteiro que aponta para o primeiro termo da lista/fila
    NoLista *fim;       // ponteiro que aponta para o ultimo termo da lista/fila
}Fila;

// FUNÇÕES 


// cria linha

void l(){
    printf("\n-------------------------------------------------------------------\n\n");
}

// cria a fila 
Fila *criar_fila() {
    
    Fila *f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
    
}

// verifica se a fila está vazia
int vazia(Fila *f) {
    
    return ( f->inicio == NULL );
    
}

// inserir um elemento na fila
void inserir (Fila *f, float v) {
    
    NoLista *novo = malloc(sizeof(NoLista));
    novo->info = v;
    novo->proximo = NULL;
    
    if ( !vazia(f)) {   // se a fila não estiver fazia a incersão é diferente pois não existe o "proximo" do fim, pois fim = NULL
     
        f->fim->proximo = novo;
        
    } else {            // se a fila estiver vazia
        
        f->inicio = novo;
    
    }
    
    f->fim = novo;
    
}

void imprime (Fila *f) {
    
    if ( !vazia(f) ) {
        
        for ( NoLista *p = f->inicio; p != NULL; p = p->proximo ) {
            
            printf("%.1f\n", p->info);
            
        }
        
    } else {
        
        l();
        printf("Fila Vazia!\n");
        l();
        
    }
    
}

float remover (Fila *f) {
    
    NoLista *p = f->inicio;
    float n = f->inicio->info;
    
    if (!vazia(f)) {
        
        if ( f->inicio == f->fim ) {
            
            f->inicio = NULL;
            f->fim = NULL;
            
        } else {
            
            f->inicio = f->inicio->proximo;

        }
        
        free(p);
        return n;
        
    } else {
        
        l();
        printf("Fila Vazia!");
        l();
    
    }

}

void liberar (Fila *f) {
    if ( !vazia(f)) {
        
        NoLista *temp;
        
        for ( NoLista *p = f->inicio; p!=NULL; p = temp) {
            
            temp = p->proximo;
            free(p);
            
        }
        
        free(f);
        f = NULL;
        
    } else {
        
        l();
        printf("Fila Vazia");
        l();
      
    }
}

void combinafilas( Fila *f_res, Fila*f1, Fila*f2) {

    // SEM RECURSIVIDADE

    // do {
    //     inserir(f_res, remover(f1));
    //     inserir(f_res, remover(f2));
    //     if ( vazia(f1) ) {
    //         do {
    //             inserir(f_res, remover(f2));
    //         }while( !vazia(f2) );
    //     } else if ( vazia(f2)) {
    //         do {
    //            inserir(f_res, remover(f1));
    //         } while (!vazia(f1));
            
    //     }
    // }while ( !vazia(f1) && !vazia(f2));

    // COM RECURSIVIDADE

    // if ( !vazia(f1) && !vazia(f2) ) {
    //     inserir(f_res, remover(f1));
    //     inserir(f_res, remover(f2));
    //     combinafilas(f_res, f1,f2);
    // } else if (vazia(f1) && !vazia(f2)){
    //     inserir(f_res, remover(f2));
    //     combinafilas(f_res, f1,f2);
    // } else if ( !vazia(f1) && vazia(f2)) {
    //     inserir(f_res, remover(f1));
    //     combinafilas(f_res, f1,f2);
    // } else {
    //     imprime(f_res);
    // }
}

int main() {

    Fila *fila = criar_fila();
    Fila *fila2 = criar_fila();
    Fila *fila_resp = criar_fila();
    
    l();
    inserir(fila, 2.1);
    inserir(fila, 4.5);
    inserir(fila, 1.0);
    inserir(fila, 3.1);
    inserir(fila, 1.8);
    inserir(fila, 12.7);
    inserir(fila, 22.1);
    inserir(fila2, 7.2);
    inserir(fila2, 3.1);
    inserir(fila2, 9.8);
    inserir(fila2, 6.3);
    // inserir(fila2, 652);
    printf("Fila:\n");
    imprime(fila);
    l();
    printf("Fila2:\n");
    imprime(fila2);
    l();
    printf("Fila_Resposta:\n");
    combinafilas(fila_resp, fila, fila2);



    l();

    
    // printf("Item Removido: %.1f\n", remover(fila));
    // l();
    // printf("Fila:\n");
    // imprime(fila);
    // liberar(fila);
   
    return 0;
}
