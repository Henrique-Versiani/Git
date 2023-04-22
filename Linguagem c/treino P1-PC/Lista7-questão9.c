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
#define TAM 100

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

struct informacoes{
    char artista[100];
    char album[100];
    data lancamento;
    float preco;
    char nome_grav[100];
}info[TAM];

int menu();
void listar();
void preencher();
void adiciona();
void apagar(int i);
int livre();

int main(){
    int mainmenu, num;
    adiciona();
    for(;;){
        mainmenu = menu();
        switch (mainmenu){
            case 1:
                preencher();
                break;
            case 2:
                listar();
                break;
            case 3:
                printf("\nDigite o numero do artista a ser apagado: ");
                scanf("%d", &num);
                apagar(num);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}

int menu(){
    int c;
    c = 0;
    do{
        printf("\n\t\t-----------------MENU-----------------");
        printf("\n\t\t   -------Escolha uma opcao-------");
        printf("\n\t\t1: Adiciona informacoes de um artista.");
        printf("\n\t\t2: Lista informacoes de um artista.");
        printf("\n\t\t3: Apaga informacoes de um artista.");
        printf("\n\t\t4: Fecha o programa.\n");
        scanf(" %d", &c);
    }while(c < 1 || c > 4);
    getchar();
    return c;
}

void adiciona(){
    int i;
    for(i = 0; i < TAM; i++)
        info[i].artista[0] = '\0';
}

int livre(){
    int i;
    for(i = 0; info[i].artista[0] && i < TAM; i++);
    if(i == TAM)
        return -1;
    return i;
}

void preencher(){
    int posicao;
    posicao = livre();
    if(posicao == -1)
        printf("\nFora da representacao");
    printf("\n\n\t\t--------------Artista %d---------------", posicao);
    printf("\nDigite o nome do Artista/Grupo/Banda: ");
    fgets (info[posicao].artista, 100, stdin);
    printf("\nDigite o nome do Album: ");
    fgets (info[posicao].album, 100, stdin);
    printf("\nDigite o nome da gravadora: ");
    fgets (info[posicao].nome_grav, 100, stdin);
    printf("\nDigite o dia de lancamento: ");
    scanf("%d", &info[posicao].lancamento.dia);
    printf("\nDigite o mes de lancamento: ");
    scanf("%d", &info[posicao].lancamento.mes);
    printf("\nDigite o ano de lancamento: ");
    scanf("%d", &info[posicao].lancamento.ano);
    printf("\nDigite o Valor do CD: ");
    scanf("%f", &info[posicao].preco);
}

void listar(){
    int i;
    for(i = 0; i < TAM; i++){
        if(info[i].artista[0] != '\0'){
            printf("\n\n\t\t--------------Artista %d---------------", i);
            printf("\nArtista/Grupo/Banda: %s", info[i].artista);
            printf("\nAlbum: %s", info[i].album);
            printf("\nGravadora: %s", info[i].nome_grav);
            printf("\nLancamento: %d/%d/%d", info[i].lancamento.dia, info[i].lancamento.mes, info[i].lancamento.ano);
            printf("\nValor do CD: %.2f", info[i].preco);
        }    
    }
}

void apagar(int i){
    if (i >= 0 && i < TAM)
        info[i].artista[0] = '\0';
}