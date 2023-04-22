/*5. Utilizando as estruturas apropriadas definidas nos exercícios anteriores, crie um algoritmo
que leia um conjunto de pontos (determinados por um valor sentinela) e calcule o envelope
(retângulo que contém todos os pontos lidos). Imprima as coordenadas do envelope. */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
}coordenada;

typedef struct{
    coordenada PIE;  //ponto inferior esquerdo
    coordenada PSD;  //ponto superior direito
}retangulo;

int main(){
    retangulo ret;
    ret.PSD.x = 1000000;
    ret.PIE.x = 0;
    ret.PSD.y = 1000000;
    ret.PIE.y = 0;

    printf("\nDigite a coordenada x do ponto inferior esquerdo:");
        scanf("%d", &ret.PIE.x);
    printf("\nDigite a coordenada y do ponto inferior esquerdo:");
        scanf("%d", &ret.PIE.y);
        do{
            if(ret.PSD.x <= ret.PIE.x)
                printf("\nValor invalido!! A coordenada x do ponto superior direito deve ser maior que a do ponto inferior esquerdo");
        printf("\nDigite a coordenada x do ponto superior direito:");
        scanf("%d", &ret.PSD.x);
        }while(ret.PSD.x <= ret.PIE.x);
        do{
            if(ret.PSD.y <= ret.PIE.y)
                printf("\nValor invalido!! A coordenada y do ponto superior direito deve ser maior que a do ponto inferior esquerdo");
        printf("\nDigite a coordenada y do ponto superior direito:");
        scanf("%d", &ret.PSD.y);
        }while(ret.PSD.y <= ret.PIE.y);

        printf("\nAs coordenadas do envelope sao: "
       " \nPonto inferior esquerdo:(%d, %d)"
       " \nPonto inferior direito:(%d, %d)"
       " \nPonto superior esquerdo: (%d, %d)"
        "\nPonto superior direito: (%d, %d)", ret.PIE.x, ret.PIE.y, ret.PSD.x, ret.PIE.y, ret.PIE.x, ret.PSD.y, ret.PSD.x, ret.PSD.y);
    return 0;
}