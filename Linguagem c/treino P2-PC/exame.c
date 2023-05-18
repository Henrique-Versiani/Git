#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
char conteudo;
struct cel *prox;
} celula;

celula *cria(void);
void le_arquivo(celula * c);
void insere_fim(char x, celula * c);
int lista_vazia(celula * c);
char remove_inicio(celula * c);
char remove_fim(celula * c);

int main()
{
    celula *listaA, *listaB, *listaC;
    char removido;
    listaA = cria();
    listaB = cria();
    listaC = cria();
    le_arquivo(listaA);
    while (!lista_vazia(listaA)) {
        removido = remove_inicio(listaA);
        printf("%c ", removido);
        insere_fim(removido, listaB);
    }
    printf("\n");
    while (!lista_vazia(listaB)) {
    removido = remove_fim(listaB);
        printf("%c ", removido);
        insere_fim(removido, listaC);
    }
    printf("\n");
    while (!lista_vazia(listaC)) {
        removido = remove_fim(listaC);
        printf("%c ", removido);
    }
    printf("\n");
    return 0;
}

celula *cria(void)
{
  celula *head = (celula *)malloc(sizeof(celula));
  head->prox = NULL;
  return head;
}

void le_arquivo(celula *c)
{
   FILE *entrada = fopen("entrada.txt", "r");
   char lido;
    while(!feof(entrada)){
      fscanf(entrada, "%c ", &lido);
      insere_fim(lido, c);
    }
    fclose(entrada);
}

void insere_fim(char x, celula * c)
{
  celula *fim, *nova = (celula *)malloc(sizeof(celula));
  for(fim = c; fim->prox != NULL; fim = fim->prox);
  nova->conteudo = x;
  nova->prox = fim->prox;
  fim->prox = nova;
}

int lista_vazia(celula * c)
{
 if(c->prox == NULL)
   return 1;
  else 
   return 0;
}

char remove_inicio(celula * c)
{
  celula *p;
  char removido;
  removido = c->prox->conteudo;
  p = c->prox;
  c->prox = p->prox;
  free(p);
  return removido;
}

char remove_fim(celula * c)
{
  celula *p, *q;
  char removido;
  p = c;
  for(q = c->prox; q->prox != NULL; q = q->prox, p = p->prox);
  removido = q->conteudo;
  p->prox = q->prox;
  free(q);
  return removido;
}