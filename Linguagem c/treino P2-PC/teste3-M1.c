#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct cel{
  char c;
  struct cel *prox;
}celula;

celula *cria_lista()
{
  celula *head = ( celula * )malloc( sizeof( celula ) );
  head->prox = NULL;
  return head;
}

void insere_no_fim( char c, celula *lista )
{
  celula *fim, *nova = ( celula * )malloc( sizeof( celula ) );
  for( fim = lista; fim->prox != NULL; fim = fim = fim->prox );
  nova->c = c;
  nova->prox =  fim->prox;
  fim->prox = nova;
}

void imprime( celula *lista, FILE *arquivo )
{
  celula *p;
  for( p = lista->prox; p != NULL; p = p->prox )
    fprintf( arquivo, "%c", p->c );
  fprintf( arquivo, "\n" );
}

int main()
{
  celula *lista[TAM];
  int i, num;
  char c;

  for( i = 0; i < TAM; i++)
    lista[i] = cria_lista();
  
  FILE *entrada = fopen( "entrada.txt", "r" );
  fscanf( entrada, "%d %c", &num, &c );
  while( !feof( entrada )){
    insere_no_fim(c, lista[num - 1]);
    fscanf( entrada, "%d %c", &num, &c );
  }fclose( entrada );

  FILE *saida = fopen( "saida.txt", "w" );

  for( i = 0; i < TAM; i++)
    imprime( lista[i] , saida);
  fclose( saida );
  return 0;
}