/*9. Crie as estruturas necessárias para o armazenamento das informações de CD's de músicas de
um acervo, como as seguintes:
• Nome do Artista/Grupo/Banda
• Nome do Álbum
• Data de Lançamento do CD
• Valor do CD
• Nome da Produtora/Gravadora
• Código e Nome do Gênero Musical
• Total de Faixas de um disco e Número, Título e Duração de cada Faixa do CD
• Algo que identifique se o CD é single (um CD), duplo (2 CDs) ou Box (+ de 2CDs).
Crie um algoritmo que permita preencher as informações deste acervo de CDs e faça
algumas operações sobre o acervo, como as seguintes:
• Buscar por Artista/Grupo/Banda
• Buscar por Álbum
• Buscar por Gênero
• Buscar por Título de Faixa
• Listar (imprimir) todo o acervo (Artista, Álbum e Faixas) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 10

typedef struct D_M_A{
    int dia;
    int mes;
    int ano;
}Data;

struct CD{
    char artista[100];
    char album[100];
    char gravadora[100];
    char genero[100];
    Data lancamento;
    float preco;
}Disco[MAX];

int menu();
void cria_lista();
int livre();
void insere();
void listar();
void apagar();
void busca_pelo_nome();
void busca_pelo_album();

int main()
{
    int mainmenu;
    cria_lista();
    for (;;){
        mainmenu = menu();
        switch (mainmenu){
            case 1:
                insere();
                break;
            case 2:
                listar();
                break;
            case 3:
                apagar();
                break;
            case 4:
                busca_pelo_nome();
                break;
            case 5:
                busca_pelo_album();
                break;
            case 6:
                exit(0);
                break;
        }
    }
    return 0;
}

void cria_lista()
{
    int i;
    for (i = 0; i < MAX; i++)
        Disco[i].artista[0] = '\0';
}

int livre()
{
    int i;
    for (i = 0; Disco[i].artista[0] && i < MAX; i++);
    if (i == MAX)
        return -1;
    return i;
}

int menu()
{
    int i = 0;
    do{
        printf("\n\t\t---------------- MENU ----------------");
        printf("\n\t\t1: Insere informacoes de um artista/banda.");
        printf("\n\t\t2: Lista informacoes de cada artista/banda.");
        printf("\n\t\t3: Apaga as informacoes de um determinado artista/banda.");
        printf("\n\t\t4: Busca pelo nome.");
        printf("\n\t\t5: Busca pelo album.");
        printf("\n\t\t6: Sair.\n");
        scanf("%d", &i);
    }while (i < 0 || i > 6);
    getchar();
    return i;
}

void insere()
{
    int posicao;
    posicao = livre();
    printf("\n---------------Artista %d---------------", posicao);
    printf("\nInforme o nome do artista/banda: ");
    fgets(Disco[posicao].artista, 100, stdin);
    printf("\nInforme o nome do album: ");
    fgets(Disco[posicao].album, 100, stdin);
    printf("\nInforme o nome da gravadora: ");
    fgets(Disco[posicao].gravadora, 100, stdin);
    printf("\nInforme o genero: ");
    fgets(Disco[posicao].genero, 100, stdin);
    printf("\nDigite o dia de lancamento: ");
    scanf("%d", &Disco[posicao].lancamento.dia);
    printf("\nDigite o mes de lancamento: ");
    scanf("%d", &Disco[posicao].lancamento.mes);
    printf("\nDigite o ano de lancamento: ");
    scanf("%d", &Disco[posicao].lancamento.ano);
    printf("\nDigite o preco: ");
    scanf("%f", &Disco[posicao].preco);
}

void listar()
{
    int i;
    for (i = 0; i < MAX; i++){
        if (Disco[i].artista[0] != '\0'){
            printf("\n\n--------------Artista %d---------------", i);
            printf ("\nArtista/banda: %s", Disco[i].artista);
            printf ("\nAlbum: %s", Disco[i].album);
            printf ("\nGravadora: %s", Disco[i].gravadora);
            printf ("\nGenero: %s", Disco[i].genero);
            printf ("\nData de lancamento: %d/%d/%d", Disco[i].lancamento.dia, Disco[i].lancamento.mes, Disco[i].lancamento.ano);
            printf ("\nPreco: %.2f", Disco[i].preco);
        }
    }
}

void apagar()
{
    int i;
    printf("\nInforme o artista que deseja apagar: ");
    scanf("%d", &i);
    if (i >= 0 && i < MAX)
        Disco[i].artista[0] = '\0';
}

void busca_pelo_nome()
{
    int i, j=0;
    char palavra[100];
    printf("\nDigite o nome do artista/banda: ");
    fgets (palavra, 100, stdin);
    for (i = 0; i < MAX; i++){
        if (Disco[i].artista[0] != '\0' && strcmp(Disco[i].artista, palavra) == 0){
            printf("\n\n--------------Artista %d---------------", i);
            printf ("\nArtista/banda: %s", Disco[i].artista);
            printf ("\nAlbum: %s", Disco[i].album);
            printf ("\nGravadora: %s", Disco[i].gravadora);
            printf ("\nGenero: %s", Disco[i].genero);
            printf ("\nData de lancamento: %d/%d/%d", Disco[i].lancamento.dia, Disco[i].lancamento.mes, Disco[i].lancamento.ano);
            printf ("\nPreco: %.2f", Disco[i].preco);
            j++;
        }
    }
    if (j == 0)
        printf ("\nO artista nao existe!!\n");
}

void busca_pelo_album()
{
    int i, j=0;
    char palavra[100];
    printf("\nDigite o nome do album: ");
    fgets (palavra, 100, stdin);
    for (i = 0; i < MAX; i++){
        if (Disco[i].artista[0] != '\0' && strcmp(Disco[i].album, palavra) == 0){
            printf("\n\n--------------Artista %d---------------", i);
            printf ("\nArtista/banda: %s", Disco[i].artista);
            printf ("\nAlbum: %s", Disco[i].album);
            printf ("\nGravadora: %s", Disco[i].gravadora);
            printf ("\nGenero: %s", Disco[i].genero);
            printf ("\nData de lancamento: %d/%d/%d", Disco[i].lancamento.dia, Disco[i].lancamento.mes, Disco[i].lancamento.ano);
            printf ("\nPreco: %.2f", Disco[i].preco);
            j++;
        }
    }
    if (j == 0)
        printf ("\nO album nao existe!!\n");
}