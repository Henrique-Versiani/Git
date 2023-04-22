#include <stdio.h>
#include <stdlib.h>

struct cel {
	int conteudo;
	struct cel *prox;
};

typedef struct cel cel;

int main(int argc, char const *argv[])
{
	FILE *entrada, *saida;
	cel *lista, *nova, *posicao, *p, *q;
	int aux, v;

	entrada = fopen("entrada-m2.txt", "r");

	lista = (cel *) malloc(sizeof(struct cel));
	lista->prox = NULL;

	fscanf(entrada, "%d", &v);
	while (!feof(entrada)) {
		/* acha a posicao */
		for (posicao = lista;
		     posicao->prox != NULL && posicao->prox->conteudo < v;
		     posicao = posicao->prox) ;
		/* insere na posicao */
		nova = (cel *) malloc(sizeof(struct cel));
		nova->conteudo = v;

		nova->prox = posicao->prox;
		posicao->prox = nova;

		fscanf(entrada, "%d", &v);
	}
	fclose(entrada);

	saida = fopen("saida-m2.txt", "w");

	for (p = lista->prox; p != NULL; p = p->prox)
		fprintf(saida, "%d ", p->conteudo);

	fclose(saida);

	return 0;
}
