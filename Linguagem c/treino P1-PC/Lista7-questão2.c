/*2. Crie uma estrutura para armazenar os dados de círculos (ponto central e raio). Crie um
algoritmo que permita ler, armazenar e imprimir uma quantidade TAM de círculos. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef struct {
    int x;
    int y;
}coordenada;

typedef struct {
    coordenada coord;
    float raio;
}circulo[TAM];

int main(){
    circulo C;
    int i;

    for(i = 0; i < TAM; i++){
        printf("\nDigite a coordenada x do ponto central do circulo:");
        scanf("%d", &C[i].coord.x);
        printf("\nDigite a coordenada y do ponto central do circulo:");
        scanf("%d", &C[i].coord.y);
        printf("\nDigite o tamanho do raio:");
        scanf("%f", &C[i].raio);
    }

    for(i = 0; i < TAM; i++){
        printf("\n\t\t-----------Circulo %d------------", (i+1));
        printf("\nPonto central: (%d, %d)\nRaio: %.2f", C[i].coord.x, C[i].coord.y,C[i].raio);
    }
    return 0;
}