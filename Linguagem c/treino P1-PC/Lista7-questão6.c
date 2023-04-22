/*6. Utilizando as estruturas apropriadas definidas nos exercícios anteriores, crie um algoritmo
que leia as coordenadas de um retângulo e um conjunto de pontos (determinados por um
valor sentinela) e informe para cada ponto lido se está dentro ou fora do retângulo. Imprima
a quantidade de pontos dentro e fora do retângulo. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int x;
    int y;
}coordenada;

typedef struct{
    coordenada PIE;  //ponto inferior esquerdo
    coordenada PSD;  //ponto superior direito
}retangulo;

int main(){
    char confirm;
    coordenada coord;
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

        for(;;){
        printf("\n\nDigite uma coordenada x: ");
            scanf("%d", &coord.x);
        printf("\n\nDigite uma coordenada y: ");
            scanf("%d", &coord.y);
                if(coord.x >= ret.PIE.x && coord.x <= ret.PSD.x && coord.y >= ret.PIE.y && coord.y <= ret.PSD.y)
                    printf("\nA coordenada indicada esta DENTRO do retangulo!!");
                else    
                    printf("\nA coordenada indicada esta FORA do retangulo!!");
        printf("\nDeseja testar mais um ponto?");
            scanf("%s", &confirm);
                if(confirm == 'N' || confirm == 'n')
                    exit(0);
        }
    return 0;
}