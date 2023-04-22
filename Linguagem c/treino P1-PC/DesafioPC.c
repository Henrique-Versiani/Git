#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double somar(double num1, double num2);
double subtrair(double num1, double num2);
double dividir(double num1, double num2);
double multiplicar(double num1, double num2);
long fatorial(double num);
int menu();

int main(){
    int mainmenu;
    double a, b;
    for(;;){
        mainmenu = menu();
        switch(mainmenu){
            case 1:
                printf("\nDigite o valor 1: ");
                scanf("%lf", &a);
                printf("\nDigite o valor 2: ");
                scanf("%lf", &b);
                printf("\nO resultado da soma eh: %lf", somar(a, b)); 
               break;
            case 2:
                printf("\nDigite o valor 1: ");
                scanf("%lf", &a);
                printf("\nDigite o valor 2: ");
                scanf("%lf", &b);
                printf("\nO resultado da subtracao eh: %lf", subtrair(a, b));
                break;
            case 3:
                printf("\nDigite o valor 1: ");
                scanf("%lf", &a);
                printf("\nDigite o valor 2: ");
                scanf("%lf", &b);
                printf("\nO resultado da multiplicacao eh: %lf", multiplicar(a, b));
                break;
            case 4:
                printf("\nDigite o valor 1: ");
                scanf("%lf", &a);
                b = 1;
                do{
                    if(b == 0)
                    printf("\nValor invalido!! Insira novamente");
                    printf("\nDigite o valor 2: ");
                    scanf("%lf", &b);
                }while(b == 0);
                printf("\nO resultado da divisao eh: %lf", dividir(a, b));
                break;
            case 5:
                printf("Insira um valor para o qual deseja calcular seu fatorial: ");
                scanf("%lf", &a);
                printf("\nFatorial calculado: %ld", fatorial(a));
                break;
            case 6:
                exit(0);
                break;
        }
    }
}

int menu(){
    int c;
    do{
        printf("\n\n\t--------------MENU-------------");
        printf("\nPara soma, digite 1");
        printf("\nPara subtracao, digite 2");
        printf("\nPara multiplicacao, digite 3");
        printf("\nPara divisao, digite 4");
        printf("\nPara fatorial, digite 5");
        printf("\nPara finalizar o programa, digite 6\n");
        scanf("%d", &c);
    }while(c <  1 || c > 6);
    getchar();
    return c;
}

double somar(double num1, double num2)
{
    double resultado;
    resultado = num1 + num2;
    return resultado;
}

double subtrair(double num1, double num2)
{
    double resultado;
    resultado = num1 - num2;
    return resultado;
}

double multiplicar(double num1, double num2)
{
    double resultado;
    resultado = (num1 * num2);
    return resultado;
}

double dividir(double num1, double num2)
{
    double resultado;
    resultado = (num1/num2);
    return resultado;
}

long fatorial(double num)
{
    long fat;
    num = round(num);
    for(fat = 1; num > 1; num = num - 1)
        fat = fat * num;
    return fat;
}