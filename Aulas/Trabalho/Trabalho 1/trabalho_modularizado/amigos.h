typedef struct lista_amigos {

    int id;
    struct lista_amigos *proximo;

}Amigos;

void remove_amigo ( Amigos **l, int v );

void inserir_amigo ( Amigos **l, int v);