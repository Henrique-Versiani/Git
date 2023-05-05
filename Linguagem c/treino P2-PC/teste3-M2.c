#include <stdio.h>
#include <stdlib.h>

struct cel{
    int num;
    struct cel *prox;
};

typedef struct cel celula;

celula *cria_lista();
void insere_na_ordem(int num, celula *p_lista);
void imprime(celula *p_lista);

int main()
{
    celula *lista = cria_lista();
    int num;
    FILE *entrada = fopen("entrada.txt", "r");
    while(!feof(entrada)){
        fscanf(entrada, "%d", &num);
        insere_na_ordem(num, lista);
    }
    imprime(lista);
}

celula *cria_lista()
{
    celula *head = (celula *)malloc(sizeof(celula));
    head->prox = NULL;
    return head;
}

void insere_na_ordem(int num, celula *p_lista)
{
    celula *p, *nova = (celula *)malloc(sizeof(celula));
    for(p = p_lista; p->prox != NULL && p->prox->num < num; p = p->prox);
    nova->num = num;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprime(celula *p_lista)
{
    celula *p;
    FILE *saida = fopen("saida.txt", "w");
    for(p = p_lista->prox; p != NULL; p = p->prox){
        fprintf(saida, "%d\n", p->num);
    }
    fclose(saida);
}