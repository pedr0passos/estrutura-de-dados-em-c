typedef struct aluno Aluno;

typedef struct encadeada_principal {

    Aluno aluno;
    struct encadeada_principal *proximo;
    struct encadeada_principal *anterior;

}Lista;


Lista *buscar_elemento(Lista **l, int id);

void cria_lista (Lista **l);

int lista_vazia ( Lista **l );

void imprime_amigos ( Lista **a, Lista **l );