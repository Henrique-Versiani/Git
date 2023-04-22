//JOAO VITOR LAIMER TURMA M1

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct cel
{
    char c;
    int x;
    struct cel *prox;
};

typedef struct cel celula;
celula *cabeca(void);
void insereNoFim(celula *num, char c,int x);
void imprime(celula *num);
celula *encadeiaLista(celula *primeira,celula *segunda);
void imprimeArquivo(celula *num,FILE *arquivo);

int main(void)
{
    int qntd = 0,num;
    celula *um,*dois,*tres,*quatro,*cinco,*seis,*sete,*oito,*nove,*dez,*listona;
    char c;
    listona = cabeca();
        insereNoFim(listona,0,0);
    um = cabeca();
    dois = cabeca();
    tres = cabeca();
    quatro = cabeca();
    cinco = cabeca();
    seis = cabeca();
    sete = cabeca();
    oito = cabeca();
    nove = cabeca();
    dez = cabeca();

    FILE *arquivo = fopen("entrada.txt","r");
    
        while(!feof(arquivo))
        {
            fscanf(arquivo,"%d %c",&num,&c);
            if(num == 1)
                insereNoFim(um,c,num);
            else if(num == 2)
                insereNoFim(dois,c,num);
            else if(num == 3)
                insereNoFim(tres,c,num);
            else if(num == 4)
                insereNoFim(quatro,c,num);
            else if(num == 5)
                insereNoFim(cinco,c,num);
            else if(num == 6)
                insereNoFim(seis,c,num);
            else if(num == 7)
                insereNoFim(sete,c,num);
            else if(num == 8)
                insereNoFim(oito,c,num);
            else if(num == 9)
                insereNoFim(nove,c,num);
            else if(num == 10)
                insereNoFim(dez,c,num);
        }
                
    
    encadeiaLista(listona,um);
    encadeiaLista(listona,dois);
    encadeiaLista(listona,tres);
    encadeiaLista(listona,quatro);
    encadeiaLista(listona,cinco);
    encadeiaLista(listona,seis);
    encadeiaLista(listona,sete);
    encadeiaLista(listona,oito);
    encadeiaLista(listona,nove);
    encadeiaLista(listona,dez);
    FILE *saida = fopen("saida.txt","w");
    
    imprimeArquivo(listona,saida);
    
    //imprime(listona);

    fclose(saida);

    return 0;
}

celula *cabeca(void)
{
    celula *nova = (celula*)malloc(sizeof(celula));

    nova->prox = NULL;

    return nova;
}

void insereNoFim(celula *num, char c,int x)
{
    celula *nova = (celula*)malloc(sizeof(celula));
    celula *p;
    p = num;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    if (p != NULL)
    {
        nova->c = c;
        nova->x = x;
        nova->prox = p->prox;
        p->prox = nova;
    }
}

void imprime(celula *num)
{
    celula *p;
    p = num->prox;
    while(p->prox != NULL)
    {
        printf("%d %c\n",p->x,p->c);
        p=p->prox;
    }
}
void imprimeArquivo(celula *num,FILE *arquivo)
{
    celula *p;
    
    p = num->prox;
    p = p->prox;
    while(p != NULL)
    {
        fprintf(arquivo,"%c",p->c);
        p=p->prox;
    }
}
celula *encadeiaLista(celula *primeira,celula *segunda)
{
    celula *p;

    p = primeira->prox;
    while(p->prox != NULL)
    {
        p = p->prox;
    }

    p->prox = segunda->prox;

    return p;
}
// codigo ta feio n deu tempo de arrumar fiquei nervoso no inicio achei q ia ser mt dificil e ate que foi mas pelo jeito deu tudo certo