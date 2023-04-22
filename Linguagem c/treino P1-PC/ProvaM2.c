#include <stdio.h>
#include <math.h>
#define MAXDELEGACIAS 5
#define MAXVITIMAS 10

typedef struct {
int x;
int y;
} coord;

typedef struct {
coord local;
float raio;
int capac;
} delegacia;

typedef struct {
coord local;
} vitima;

delegacia listadelegacias[MAXDELEGACIAS];
vitima listavitimas[MAXVITIMAS];

void questao01(int *qdel, int *qvit);
vitima questao02(int del, int vit);
void questao03(vitima x);
void questao04(int qdel, int qvit);
float dist(int x1, int y1, int x2, int y2);

int main()
{
    int qtde_del, qtde_vit;
    questao01(&qtde_del, &qtde_vit);
    questao03(questao02(qtde_del, qtde_vit));
    questao04(qtde_del, qtde_vit);
    return 0;
}

void questao01(int *qdel, int *qvit)
{
    int i;
    printf("\nDigite a quantidade de delegacias: ");
    scanf("%d", qdel);
    for(i = 0; i < *qdel; i++){
        printf("\nDigite as coordenadas x e y, o raio e a capaciade da delegacia, respectivamente: ");
        scanf("%d %d %f %d", &listadelegacias[i].local.x, &listadelegacias[i].local.y, &listadelegacias[i].raio, &listadelegacias[i].capac);
    }
    printf("\nDigite a quantidade de vitimas: ");
    scanf("%d", qvit);
    for(i = 0; i < *qvit; i++){
        printf("\nDigite as coordenadas x e y, respectivamente: ");
        scanf("%d %d", &listavitimas[i].local.x, &listavitimas[i].local.y);
    }
}

vitima questao02(int del, int vit)
{
    int i, j, M_prox;
    float dist, dist_prox=10000000;
    for(i = 0; i < vit; i++){
        for(j = 0; j < del; j++){
            dist = sqrt(pow(listadelegacias[j].local.x - listavitimas[i].local.x, 2) + pow(listadelegacias[j].local.y - listavitimas[i].local.y, 2));
            if(dist < dist_prox){
                dist_prox = dist;
                M_prox = i;
            }
        }
    }
    return listavitimas[M_prox];
}

void questao03(vitima x)
{
    printf("\n\nCoordenada: (%d, %d)\n\n", x.local.x, x.local.y);
}

void questao04(int qdel, int qvit)
{
    int i, j, M_maior, num[MAXDELEGACIAS] = {0};
    float dist, dist_prox;

    for (i = 0; i < qvit; i++){
        dist_prox=10000000;
        M_maior = -1;
        for (j = 0; j < qdel; j++){
            dist = sqrt(pow(listadelegacias[j].local.x - listavitimas[i].local.x, 2) + pow(listadelegacias[j].local.y - listavitimas[i].local.y,2));
            if (dist <= listadelegacias[j].raio){
                if (dist < dist_prox){
                    M_maior = j;
                    dist_prox = dist;
                }
            }
        }
        num[M_maior]++;
    }
    for (j = 0; j < qdel; j++){
        printf("\n%d: %d", j, num[j]);
        if (num[j] < listadelegacias[j].capac)
            printf("-");
        else if (num[j] == listadelegacias[j].capac)
            printf("=");
        else if (num[j] > listadelegacias[j].capac)
            printf("+");
    }
}