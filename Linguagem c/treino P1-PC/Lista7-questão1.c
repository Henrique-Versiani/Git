/*1. Construa uma estrutura para armazenar pontos (coordenadas x e y) no plano cartesiano. Crie
um algoritmo que permita ler, armazenar e imprimir uma quantidade TAM de pontos. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct{
    int x;
    int y;
}coordenada[TAM];


int main(){
    int i=0;
    coordenada coord;
    for(i = 0; i < TAM; i++){
        printf("\nDigite a coodernada x: ");
        scanf("%d", &coord[i].x);

        printf("\nDigite a coodernada y: ");
        scanf("%d", &coord[i].y);
    }

    printf("\nCoordenadas indicadas:");

    for(i = 0; i < TAM; i++){
        printf("\nPonto %d: (%d, %d)", (i+1), coord[i].x, coord[i].y);
    }

    return 0;
}