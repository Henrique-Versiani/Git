#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
   char       conteudo;
   struct cel *prox;
} celula;

celula *cria(void);
void le_arquivo(celula *c);
void insere_fim(char x, celula *c);
int lista_vazia(celula *c);
char remove_inicio(celula *c);
char remove_fim(celula *c);

int
main()
{
   celula *listaA, *listaB, *listaC;
   char   removido;

   listaA = cria();
   listaB = cria();
   listaC = cria();

   le_arquivo(listaA);

   while (!lista_vazia(listaA))
   {
      removido = remove_inicio(listaA);
      printf("%c ", removido);
      insere_fim(removido, listaB);
   }
   printf("\n");

   while (!lista_vazia(listaB))
   {
      removido = remove_fim(listaB);
      printf("%c ", removido);
      insere_fim(removido, listaC);
   }
   printf("\n");

   while (!lista_vazia(listaC))
   {
      removido = remove_fim(listaC);
      printf("%c ", removido);
   }
   printf("\n");

   return 0;
}


celula *
cria(void)
{
   celula *nova;

   nova       = (celula *)malloc(sizeof(celula));
   nova->prox = NULL;
   return nova;
}


void
le_arquivo(celula *c)
{
   FILE *entrada;
   char lido;

   entrada = fopen("exame.in", "r");

   while (!feof(entrada))
   {
      fscanf(entrada, "%c", &lido);
      if (lido != ' ')
      {
         insere_fim(lido, c);
      }
   }
   fclose(entrada);
}


void
insere_fim(char x, celula *c)
{
   celula *nova, *p;

   nova = (celula *)malloc(sizeof(celula));
   for (p = c; p->prox != NULL; p = p->prox)
   {
   }
   nova->conteudo = x;
   nova->prox     = p->prox;
   p->prox        = nova;
}


int
lista_vazia(celula *c)
{
   if (c->prox == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}


char
remove_inicio(celula *c)
{
   char   caractere;
   celula *p;

   caractere = c->prox->conteudo;
   p         = c->prox;
   c->prox   = p->prox;
   free(p);
   return caractere;
}


char
remove_fim(celula *c)
{
   char   caractere;
   celula *p, *q;

   p = c;
   q = c->prox;
   while (q->prox != NULL)
   {
      p = q;
      q = q->prox;
   }
   caractere = q->conteudo;
   p->prox   = q->prox;
   free(q);
   return caractere;
}
