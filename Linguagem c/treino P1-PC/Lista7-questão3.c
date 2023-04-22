/*3. Crie uma estrutura para armazenar os dados de retângulos (pontos diagonais inferioresquerda e superior-direita). Crie um algoritmo que permita ler, armazenar e imprimir uma
quantidade TAM de retângulos. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct{
    int x;
    int y;
}coordenada;

typedef struct{
    coordenada PIE;  //ponto inferior esquerdo
    coordenada PSD;  //ponto superior direito
}retangulo[TAM];

int main(){
    retangulo ret;
    int i;

    for(i = 0; i < TAM; i++){
        printf("\nDigite a coordenada x do ponto inferior esquerdo:");
        scanf("%d", &ret[i].PIE.x);
        printf("\nDigite a coordenada y do ponto inferior esquerdo:");
        scanf("%d", &ret[i].PIE.y);
        printf("\nDigite a coordenada x do ponto superior direito:");
        scanf("%d", &ret[i].PSD.x);
        printf("\nDigite a coordenada y do ponto superior direito:");
        scanf("%d", &ret[i].PSD.y);
    }

    for(i = 0; i < TAM; i++){
        printf("\n\t\t-----------Retangulo %d------------", (i+1));
        printf("\nPonto inferior esquerdo: (%d, %d)\nPonto superior direito: (%d, %d)", ret[i].PIE.x, ret[i].PIE.y,ret[i].PSD.x, ret[i].PSD.y);
    }
}