#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *prox;
};

typedef struct cel celula;

celula *cria_lista();
void insere_no_inicio(int conteudo, celula *p_lista);
void insere_no_fim(int conteudo, celula *p_lista);
void imprime(celula *p_lista);

int main()
{
    celula *lista;
    lista = cria_lista();
    insere_no_fim(100, lista);
    insere_no_fim(50, lista);
    insere_no_fim(70, lista);
    insere_no_fim(99, lista);
    imprime(lista);
    return 0;
}

celula *cria_lista()
{
    celula *inicio;
    inicio = (celula *)malloc(sizeof(celula));
    inicio->prox = NULL;
    return inicio;
}

void insere_no_inicio(int conteudo, celula *p_lista)
{
    celula *nova;
    nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->prox = p_lista->prox;
    p_lista->prox = nova;
}

void insere_no_fim(int conteudo, celula *p_lista)
{
    celula *p;
    for(p = p_lista; p->prox != NULL; p = p->prox);
    insere_no_inicio(conteudo, p);
}

void imprime(celula *p_lista)
{
    celula *p;
    for(p = p_lista->prox; p != NULL; p = p->prox){
        printf("\n%d", p->conteudo);
    }
}