#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct antena{
  int x;
  int y;
  float raio;
  struct antena *prox;
};

struct usuario{
  int x;
  int y;
  struct usuario *prox;
};

typedef struct antena ant;
typedef struct usuario usu;

ant *cria_lista_antena();
usu *cria_lista_usuario();
void insere_no_fim_antena(int x, int y, float raio, ant *lista);
void insere_no_fim_usuario(int x, int y, usu *lista);
void imprime_antena(ant *lista);
void imprime_usuario(usu *lista);
float distancia(ant *lista1, usu *lista2);

int main()
{
  ant *lista_antena = cria_lista_antena();
  usu *lista_usuario = cria_lista_usuario(), *p;
  int quant_ant, quant_usu, x, y, i;
  float raio, qualidade;
  
  FILE *entrada = fopen("entrada.txt", "r");
  fscanf(entrada, "%d", &quant_ant);
  for(i = 0; i < quant_ant; i++){
    fscanf(entrada, "%d %d %f", &x, &y, &raio);
    insere_no_fim_antena(x, y, raio, lista_antena);
  }
  fscanf(entrada, "%d", &quant_usu);
  for(i = 0; i < quant_usu; i++){
    fscanf(entrada, "%d %d", &x, &y);
    insere_no_fim_usuario(x, y, lista_usuario);
  }
  fclose(entrada);
  FILE *saida = fopen("saida.txt", "w");
  for(p = lista_usuario->prox; p != NULL; p = p->prox){
    qualidade = distancia(lista_antena, p);
    fprintf(saida,"%f\n", qualidade);
  }
  fclose(saida);
}

ant *cria_lista_antena()
{
  ant *head = (ant *)malloc(sizeof(ant));
  head->prox = NULL;
  return head;
}

usu *cria_lista_usuario()
{
  usu *head = (usu *)malloc(sizeof(usu));
  head->prox = NULL;
  return head;
}

void insere_no_fim_antena(int x, int y, float raio, ant *lista)
{
  ant *p, *nova = (ant *)malloc(sizeof(ant));
  for(p = lista; p->prox != NULL; p = p->prox);
  nova->x = x;
  nova->y = y;
  nova->raio = raio;
  nova->prox = p->prox;
  p->prox = nova;
}

void insere_no_fim_usuario(int x, int y, usu *lista)
{
  usu *p, *nova = (usu *)malloc(sizeof(usu));
  for(p = lista; p->prox != NULL; p = p->prox);
  nova->x = x;
  nova->y = y;
  nova->prox = p->prox;
  p->prox = nova;
}

void imprime_antena(ant *lista)
{
  ant *p;
  for(p = lista->prox; p != NULL; p = p->prox){
    printf("%d %d %f\n", p->x, p->y, p->raio);
  }
  printf("\n");
}

void imprime_usuario(usu *lista)
{
  usu *p;
  for(p = lista->prox; p != NULL; p = p->prox){
    printf("%d %d\n", p->x, p->y);
  }
}

float distancia(ant *lista1, usu *lista2)
{
  ant *p;
  float distancia, menor_dist;
  int cont = -1;
    menor_dist = 9999999;
    for(p = lista1->prox; p != NULL; p = p->prox){
      distancia = sqrt(pow(lista2->x - p->x,2) + pow(lista2->y - p->y,2));
      if(distancia <= p->raio){
        if(distancia < menor_dist)
          menor_dist = distancia;
          cont++;
      }
    }
  if(cont == -1){
    return -1;
  }else
    return 1/(1 + sqrt(menor_dist));
}