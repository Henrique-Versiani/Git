#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#define NUM_PALAVRAS 14
#define TAM 100

char const tabelaDePalavras[NUM_PALAVRAS][TAM] = {
"BAT ATA$É um tubérculo",
"AIPIM$Usa-se para fazer sagu",
"COMPUTACAO$Melhor curso do mundo",
"CHIMARRAO$Se toma numa cuia",
"LAGARTO$Lacoste de elo baixo",
"MARACUJA$Parece sua cara quando acorda",
"SOCORRO$Pedido de ajuda",
"TATU$Tem na terra e no seu nariz",
"FLORESTA$Amazônia",
"ARARA$Papagaio vip",
"FACULDADE$Local de dor e sofrimento",
"TRAKINAS$Marca de biscoito recheado",
"VOLEI$Esporte com bola",
"GUITARRA$Instrumento musical de cordas"
};

typedef struct{
char palavraEscolhida[TAM];
char palavraImpressa[TAM];
char dica[TAM];
int letrasRestantes;
int chancesRestantes;
} MatchData;

int posicao = 0;
char letras_usadas[TAM];
MatchData desafio;

void inicializarDados(MatchData *dest);
void processarLetra(MatchData *data, char letra);
char menu(void);

int main(void)
{
    system("chcp 65001 > NUL");
    int mainmenu;
    inicializarDados(&desafio);
    for(;;){
        mainmenu = menu();
        switch(mainmenu){
            case '0':
                exit(0);
                break;
            default:
            system("cls");
                processarLetra(&desafio, mainmenu);
                break;
        }
    }
}

void inicializarDados(MatchData *dest) {
    int indiceSorteado;
    srand(time(NULL));
    indiceSorteado = rand() % NUM_PALAVRAS;
    char *palavra, *dica, palavra_sorteada[TAM];
    strcpy(palavra_sorteada, tabelaDePalavras[indiceSorteado]);
    palavra = strtok(palavra_sorteada, "$");
    dica = strtok(NULL, "");

    dest->letrasRestantes = strlen(palavra);
    dest->chancesRestantes = 10;
    strcpy(dest->palavraEscolhida, palavra);
    memset(dest->palavraImpressa, '-', strlen(palavra));
    dest->palavraImpressa[strlen(palavra)] = '\0'; // Adicionar o caractere nulo para terminar a string
    strcpy(dest->dica, dica);
}

char menu(void)
{
    char c;
        printf("\n\nDica: %s", desafio.dica);
        printf("\n\nChances: %d | Letras restantes: %d", desafio.chancesRestantes, desafio.letrasRestantes);
        printf("\n\n%s", desafio.palavraImpressa);
        printf("\n\nSeu palpite: ");
        scanf("%c", &c);
        getchar();
        c = toupper(c);
    return c;
}

void processarLetra(MatchData *data, char letra)
{
    int i, tamanho, t_rep = strlen(letras_usadas), flag = 0, flag2 = 0, flag3 = 0;
    tamanho = strlen(data->palavraEscolhida);
    for (i = 0; i < t_rep; i++){
        if(letras_usadas[i] == letra)
            flag++;
    }
    letras_usadas[posicao] = letra;
    posicao++;
    for(i = 0; i < tamanho; i++){
        if(data->palavraEscolhida[i] == letra){
            if(data->palavraImpressa[i] != '-'){
                flag2++;
                data->letrasRestantes++;
            }
           data->palavraImpressa[i] = data->palavraEscolhida[i];
           data->letrasRestantes--;
           flag3++;
           if(data->letrasRestantes == 0){
                printf("PALAVRA: %s\n\nPARABENS, VOCE VENCEU!!", data->palavraEscolhida);
                exit(0);
           }
        }
    }
    if(flag > 0){
        printf("\nVOCE JA INSERIU ESSA LETRA!!");
        data->chancesRestantes++;
        if(flag2 > 0)
            data->chancesRestantes--;
    }
    if(flag3 == 0){
        data->chancesRestantes--;
        if(data->chancesRestantes == 0){
            printf("PALAVRA: %s\n\nQUE PENA, VOCE PERDEU!!", data->palavraEscolhida);
            exit(0);
        }
    }
}