#include <stdio.h>
#include <stdlib.h>

struct cel {
	char c;
	struct cel *prox;
};

typedef struct cel cel;

int main(int argc, char const *argv[])
{
	FILE *entrada, *saida;
	cel *listas[10], *nova, *fim, *p;
	int i, l;
	char c;

	entrada = fopen("entrada-m1.txt", "r");

	/* cria as listas */
	for (i = 0; i < 10; i++) {
		listas[i] = (cel *) malloc(sizeof(struct cel));
		listas[i]->prox = NULL;
	}

	fscanf(entrada, "%d %c", &l, &c);
	while (!feof(entrada)) {
		/* acha o fim */
		for (fim = listas[l - 1]; fim->prox != NULL; fim = fim->prox) ;
		/* insere no fim */
		nova = (cel *) malloc(sizeof(struct cel));
		nova->c = c;

		nova->prox = fim->prox;
		fim->prox = nova;

		fscanf(entrada, "%d %c", &l, &c);
	}
	fclose(entrada);

	saida = fopen("saida-m1.txt", "w");

	for (i = 0; i < 10; i++) {
		for (p = listas[i]->prox; p != NULL; p = p->prox)
			fprintf(saida, "%c", p->c);
		fprintf(saida, "\n");
	}

	fclose(saida);

	return 0;
}
