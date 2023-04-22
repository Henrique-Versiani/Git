/*  Joao Vitor Laimer 
    Turma M1*/

#include <stdio.h>
#include <math.h>

#define MAXESCOLAS 5
#define MAXESTUDANTES 10

typedef struct
{
    int x;
    int y;
}coord;

typedef struct
{
    coord local;
    float raio;
    int capac;
}escola;

typedef struct
{
    coord local;
}estudante;

escola listaescolas[MAXESCOLAS];
estudante listaestudantes[MAXESTUDANTES];

void questao01( int *qesc, int *qest);
escola questao02(int qesc);
void questao03(escola x);
void questao04(int qesc, int qest);

int main()
{
    int qtde_esc, qtde_est;

    questao01(&qtde_esc,&qtde_est);
    questao03(questao02(qtde_esc));
    questao04(qtde_esc,qtde_est);

    return 0;
}

void questao01( int *qesc, int *qest)
{
    do
    {
        printf("quantidade de escolas: ");
        scanf("%d",qesc);

    }while(*qesc < 0 || *qesc > 5);

    for(int i = 0; i < *qesc; i++)
    {
        printf("coord x, coord y, raio, capacidade (da escola %d)",i);
        scanf("%d %d %f %d",&listaescolas[i].local.x,&listaescolas[i].local.y,&listaescolas[i].raio,&listaescolas[i].capac);
        
    }
    
    do
    {
    printf("quantidade de estudantes:");
    scanf("%d",qest);
    }while(*qest < 0 || *qest > 10);
    for(int i = 0; i < *qest; i++)
    {
        printf("coord x, coord y (do estudante %d)",i);
        scanf("%d %d",&listaestudantes[i].local.x,&listaestudantes[i].local.y);
    }
}
escola questao02(int qesc)
{
    int temp = 0,escolaMaior,i;
    for (i = 0 ; i < qesc; i++)
    {
        if(listaescolas[i].raio > temp)
        {
            temp = listaescolas[i].raio;
            escolaMaior = i;
        }
    }

    return listaescolas[escolaMaior];

}

void questao03(escola x)
{
    printf("%d %d %f %d",x.local.x,x.local.y,x.raio,x.capac);
}

void questao04(int qesc, int qest)
{
    int i,j,distanciaescolaDoAluno,escolaLocalizada;
    
    for (i = 0; i < qest ; i++ )
    {
        printf("\n%d: ",i);
        escolaLocalizada = 0;
        for(j = 0; j < qesc ; j++)
        {
            distanciaescolaDoAluno = sqrt(((listaescolas[j].local.x - listaestudantes[i].local.x)*(listaescolas[j].local.x - listaestudantes[i].local.x)) + ((listaescolas[j].local.y - listaestudantes[i].local.y)*(listaescolas[j].local.y - listaestudantes[i].local.y))); //a2 = b2 + c2 -> a = raiz(b2 + c2)

            if(distanciaescolaDoAluno < listaescolas[j].raio)
            {
                printf("%d ",j);
                escolaLocalizada++;
            }
            

        }
        
        if(escolaLocalizada == 0)
            printf("%d ",-1);
    }
}





