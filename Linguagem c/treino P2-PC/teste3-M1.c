#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct cel{
  int num;
  char c;
  struct cel *prox;
};

typedef struct cel celula;

celula *cria_lista();
void insere_no_fim(char c, int num, celula *p_lista);
void imprime(celula *p_lista, FILE *arquivo);

int main()
{
  celula *lista[TAM];
  int i, num;
  char c;
  
  for(i = 0; i < TAM; i++)
    lista[i] = cria_lista();

  FILE *entrada = fopen("entrada.txt", "r");
  while(!feof(entrada)){
    fscanf(entrada, "%d %c", &num, &c);
    insere_no_fim(c, num, lista[num - 1]);
  }
  fclose(entrada);
  FILE *saida = fopen("saida.txt", "w");
  for(i = 0; i < TAM; i++)
    imprime(lista[i], saida);
  fclose(saida);
  return 0;
}

celula *cria_lista()
{
  celula *head = (celula *)malloc(sizeof(celula));
  head->prox = NULL;
  return head;
}

void insere_no_fim(char c, int num, celula *p_lista)
{
  celula *fim, *nova = (celula *)malloc(sizeof(celula));
  for(fim = p_lista; fim->prox != NULL; fim = fim->prox);
  nova->c = c;
  nova->num = num;
  nova->prox = fim->prox;
  fim->prox = nova;
}

void imprime(celula *p_lista, FILE *arquivo)
{
  celula *p;
  for(p = p_lista->prox; p != NULL; p = p->prox){
    fprintf(arquivo, "%c", p->c);
  }
  fprintf(arquivo, "\n");
}