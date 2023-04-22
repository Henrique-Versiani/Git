/*4. Crie uma estrutura para armazenar os dados de triângulos. Crie um algoritmo que permita
ler, armazenar e imprimir uma quantidade TAM de triângulos. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct{
    int x;
    int y;
}coordenada;

typedef struct{
    coordenada P1;  //ponto 1
    coordenada P2;  //ponto 2
    coordenada P3;  //ponto 3
}triangulo[TAM];

int main(){
    triangulo T;
    int i;

    for(i = 0; i < TAM; i++){
        printf("\nDigite a coordenada x do ponto 1:");
        scanf("%d", &T[i].P1.x);
        printf("\nDigite a coordenada y do ponto 1:");
        scanf("%d", &T[i].P1.y);
        printf("\nDigite a coordenada x do ponto 2:");
        scanf("%d", &T[i].P2.x);
        printf("\nDigite a coordenada y do ponto 2:");
        scanf("%d", &T[i].P2.y);
        printf("\nDigite a coordenada x do ponto 3:");
        scanf("%d", &T[i].P3.x);
        printf("\nDigite a coordenada y do ponto 3:");
        scanf("%d", &T[i].P3.y);
    }

    for(i = 0; i < TAM; i++){
        printf("\n\t\t-----------Triangulo %d------------", (i+1));
        printf("\nPonto 1: (%d, %d)\nPonto 2: (%d, %d)\nPonto 3: (%d, %d)", T[i].P1.x, T[i].P1.y, T[i].P2.x, T[i].P2.y, T[i].P3.x, T[i].P3.y);
    }
}