// VINICIUS HALLMANN M1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cel{
    char c;
    struct cel *prox;
};
typedef struct cel celula;

celula *cria_lista();
void insere(char c, celula *p_lista);
void gravacao(celula *p_lista1, celula *p_lista2,celula *p_lista3,celula *p_lista4,celula *p_lista5,celula *p_lista6,celula *p_lista7,celula *p_lista8,celula *p_lista9,celula *p_lista10);
void imprime(celula *p_lista);
//void leitura();
void leitura(celula *p_lista1, celula *p_lista2,celula *p_lista3,celula *p_lista4,celula *p_lista5,celula *p_lista6,celula *p_lista7,celula *p_lista8,celula *p_lista9,celula *p_lista10);
int main(){
    celula *lista1, *lista2,*lista3, *lista4,*lista5, *lista6,*lista7, *lista8,*lista9, *lista10;
    lista1 = cria_lista();
    lista2 = cria_lista();
    lista3 = cria_lista();
    lista4 = cria_lista();
    lista5 = cria_lista();
    lista6 = cria_lista();
    lista7 = cria_lista();
    lista8 = cria_lista();
    lista9 = cria_lista();
    lista10 = cria_lista();
    leitura(lista1, lista2,lista3, lista4,lista5, lista6,lista7, lista8,lista9, lista10);
    gravacao(lista1, lista2,lista3, lista4,lista5, lista6,lista7, lista8,lista9, lista10);


}

celula *cria_lista(){
    celula *inicio;
    inicio =(celula *)malloc(sizeof(celula));
    inicio -> prox = NULL;
    return inicio;
}

void leitura(celula *p_lista1, celula *p_lista2,celula *p_lista3,celula *p_lista4,celula *p_lista5,celula *p_lista6,celula *p_lista7,celula *p_lista8,celula *p_lista9,celula *p_lista10){
    FILE *arq;
    int x;
    char c;
    arq = fopen("entrada.txt", "r");
    
    while(!feof(arq)){
        fscanf(arq, "%d %c", &x, &c);
        if (x == 1){
            insere(c, p_lista1);
        }
        else if (x == 2) {
            insere(c, p_lista2);
        }
        else if (x == 3){
            insere(c, p_lista3);
        }
        else if (x == 4){
            insere(c, p_lista4);
        }
        else if (x == 5){
            insere(c, p_lista5);
        }
        else if (x == 6){
            insere(c, p_lista6);
        }
        else if (x == 7){
            insere(c, p_lista7);
        }
        else if (x == 8){
            insere(c, p_lista8);
        }
        else if (x == 9){
            insere(c, p_lista9);
        }
        else if (x == 10){
            insere(c, p_lista10);
        }
    }
}

void insere(char c, celula *p_lista){
    celula *nova;
    nova = (celula *)malloc(sizeof(celula));
    nova -> c = c;
    nova -> prox = p_lista -> prox;
    p_lista -> prox = nova;
}

void gravacao(celula *p_lista1, celula *p_lista2,celula *p_lista3,celula *p_lista4,celula *p_lista5,celula *p_lista6,celula *p_lista7,celula *p_lista8,celula *p_lista9,celula *p_lista10){
    FILE *arq;
    celula *p;
    arq = fopen("arquivo-texto.txt", "w");
    for(p = p_lista1 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista2 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista3 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista4 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista5 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista6 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista7 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista8 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista9 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    for(p = p_lista10 -> prox; p != NULL; p = p -> prox){
        fprintf(arq, "%c", p -> c);
    }
    fclose(arq);
}
void imprime(celula *p_lista){
    celula *p;
    for(p = p_lista -> prox; p != NULL; p = p -> prox){
        printf("%c", p -> c);
    }
}
