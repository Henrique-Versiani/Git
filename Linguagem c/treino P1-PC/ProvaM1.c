#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXESCOLAS 5
#define MAXESTUDANTES 10
typedef struct {
int x;
int y;
} coord;

typedef struct {
coord local;
float raio;
int capac;
} escola;

typedef struct {
coord local;
} estudante;

escola listaescolas[MAXESCOLAS];
estudante listaestudantes[MAXESTUDANTES];

void questao01(int *qesc, int *qest);
escola questao02(int qesc);
void questao03(escola x);
void questao04(int qesc, int qest);

int main()
{
int qtde_esc, qtde_est;
questao01(&qtde_esc, &qtde_est);
questao03(questao02(qtde_esc));
questao04(qtde_esc, qtde_est);
return 0;
}

void questao01(int *qesc, int *qest)
{
    int i, j=0;
    do{
    if(j > 0)
        printf("\nValor invalido!!");
    printf("\nDigite a quantidade de escolas: ");
    scanf("%d", qesc);
    j++;
    }while(*qesc < 0 || *qesc > 5);
    for (i = 0; i < *qesc; i++){
        printf("\nDigite a coordenada x e y, o raio e a capacidade da escola respectivamente: ");
        scanf("%d %d %f %d", &listaescolas[i].local.x, &listaescolas[i].local.y, &listaescolas[i].raio, &listaescolas[i].capac);
    }
    j=0;
    do{
    if(j > 0)
        printf("\nValor invalido!!");
    printf("\nDigite a quantidade de estudantes: ");
    scanf("%d", qest);
    j++;
    }while (*qest < 0 || *qest > 10);
    for (i = 0; i < *qest; i++){
        printf("\nDigite a coordenada x e y do estudante: ");
        scanf("%d %d", &listaestudantes[i].local.x, &listaestudantes[i].local.y);
    }
}

escola questao02(int qesc)
{
    int i, maior = 0;
    float maior_raio;
    maior_raio = listaescolas[0].raio;
    for(i = 0; i < qesc; i++){
        if(listaescolas[i].raio > maior_raio){
            maior_raio = listaescolas[i].raio;
            maior = i;
        }
    }
    return listaescolas[maior];
}

void questao03(escola x){
    printf("\nCoordenada: (%d, %d)\nRaio: %.2f\nCapaciade: %d\n\n", x.local.x, x.local.y, x.raio, x.capac);
}

void questao04(int qesc, int qest){
    int i, j, q;
    float dist;

    for(i = 0; i < qest; i++){
        j=0;
        printf("\n%d: ", i);
        
        for(q = 0; q < qesc; q++){
            dist = sqrt((pow(listaescolas[q].local.x - listaestudantes[i].local.x, 2)) + (pow(listaescolas[q].local.y - listaestudantes[i].local.y, 2)));
                if(dist <= listaescolas[q].raio){
                    j++;
                    printf(" %d", q);
                }
        }
        if (j==0)
            printf("-1");     
    }
}