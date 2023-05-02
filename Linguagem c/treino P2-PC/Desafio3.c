#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

struct cel{
    double preco;
    int ID;
    char nome[TAM];
    struct cel *prox;
};

typedef struct cel celula;

celula *cria_lista();
void insere(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista);
void insere_na_ordem(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista);
void insere_no_fim(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista);
void remova(int ID, celula *p_lista);
void carrega_arquivo(celula *p_lista);
void imprime(celula *p_lista);
int compara(double preco_pro, celula *p_lista);
int menu();

int main()
{
    char nome[TAM];
    double preco;
    int mainmenu, ID;
    celula *lista;
    lista = cria_lista();
    for(;;){
        mainmenu = menu();
        switch(mainmenu){
            case 1:
                printf("\nInforme o nome do produto: ");
                scanf("%[^\n]s", nome);
                getchar();
                printf("\nInforme o preco do produto: ");
                scanf("%lf", &preco);
                printf("\nInforme o ID do produto: ");
                scanf("%d", &ID);
                if(lista->prox == NULL){
                    insere(preco, ID, nome, lista);
                }else if(compara(preco, lista) == 1){
                    insere_no_fim(preco, ID, nome, lista);
                }else
                    insere_na_ordem(preco, ID, nome, lista);
                break;
            case 2:
                printf("\nInforme o ID do produto: ");
                scanf("%d", &ID);
                remova(ID, lista);
                break;
            case 3:
                imprime(lista);
                break;
            case 4:
                carrega_arquivo(lista);
                break;
            case 5:

                break;
            case 0:
                exit(0);
        }
    }
}

celula *cria_lista()
{
    celula *head;
    head = (celula *)malloc(sizeof(celula));
    head->prox = NULL;
    return head;
}

int menu(){
    int escolha;
    do{
    printf("\n\t\t--------------MENU-------------");
    printf("\n\t\t1- Adicionar produto.");
    printf("\n\t\t2- Remover produto.");
    printf("\n\t\t3- Imprimir lista.");
    printf("\n\t\t4- Carregar lista do arquivo 'produtos.bin'.");
    printf("\n\t\t5- Salvar lista atual no arquivo 'produtos.bin'.");
    printf("\n\t\t0- Sair.\n\t\t");
    scanf("%d", &escolha);
    getchar();
    }while(escolha < 0 || escolha > 5);
    return escolha;
}

void insere(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista)
{
    celula *nova;
    nova = (celula *)malloc(sizeof(celula));
    strcpy(nova->nome, nome_pro);
    nova->preco = preco_pro;
    nova->ID = ID_pro;
    nova->prox = p_lista->prox;
    p_lista->prox = nova;
}

void insere_na_ordem(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista)
{
    celula *p;
    for(p = p_lista; p->prox->preco < preco_pro; p = p->prox);
    insere(preco_pro, ID_pro, nome_pro, p);
}

void insere_no_fim(double preco_pro, int ID_pro, char nome_pro[TAM], celula *p_lista)
{
    celula *p;
    for(p = p_lista; p->prox != NULL; p = p->prox);
    insere(preco_pro, ID_pro, nome_pro, p);
}

int compara(double preco_pro, celula *p_lista)
{
    celula *p;
    for(p = p_lista; p->prox != NULL; p = p->prox);
    if(preco_pro > p->preco)
        return 1;
    else
        return 0;
}

void imprime(celula *p_lista)
{
    celula *p;
    int cont = 0;
    for(p = p_lista->prox; p != NULL; p = p->prox, cont++){
        printf("\n\t\t---------PRODUTO %d----------", cont);
        printf("\n\t\tNOME: %s\n\t\tPRECO: %lf\n\t\tID: %d\n", p->nome, p->preco, p->ID);
    }
}

void carrega_arquivo(celula *p_lista)
{
    double preco;
    char nome[TAM];
    int ID;
    FILE *produto = fopen ("produtos.bin", "rb");

    fread(&nome, sizeof(char), TAM, produto);
    fread(&preco, sizeof(double), 1, produto);
    fread(&ID, sizeof(int), 1, produto);

    fclose(produto);
    if(p_lista->prox == NULL){
      insere(preco, ID, nome, p_lista);
    }else if(compara(preco, p_lista) == 1){
      insere_no_fim(preco, ID, nome, p_lista);
    }else
      insere_na_ordem(preco, ID, nome, p_lista);
}

void remova(int ID_pro, celula *p_lista)
{
    celula *p, *q;
    p = p_lista;
    for( q = p_lista->prox; q->ID != ID_pro && q != NULL; q = q->prox, p = p->prox);
    if(q != NULL){
        p->prox = q->prox;
        free(q);
    }
}