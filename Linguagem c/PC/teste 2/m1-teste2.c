#include <stdio.h>
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

float dist(int x1, int y1, int x2, int y2);

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
	int i;

	scanf("%d", qesc);
	for (i = 0; i < *qesc; i++) {
		scanf("%d %d %f %d", &listaescolas[i].local.x,
		      &listaescolas[i].local.y, &listaescolas[i].raio,
		      &listaescolas[i].capac);
	}
	scanf("%d", qest);
	for (i = 0; i < *qest; i++) {
		scanf("%d %d", &listaestudantes[i].local.x,
		      &listaestudantes[i].local.y);
	}
}

escola questao02(int esc)
{
	int i, j;

	j = 0;
	for (i = 0; i < esc; i++) {
		if (listaescolas[i].raio > listaescolas[j].raio)
			j = i;
	}
	return listaescolas[j];
}

void questao03(escola x)
{
	printf("%d %d %f %d\n", x.local.x, x.local.y, x.raio, x.capac);
}

void questao04(int qesc, int qest)
{
	int i, j;
	int esc;
	float t;

	for (i = 0; i < qest; i++) {
		esc = -1;
		printf("%d: ", i);
		for (j = 0; j < qesc; j++) {
			t = dist(listaestudantes[i].local.x,
				 listaescolas[j].local.x,
				 listaestudantes[i].local.y,
				 listaescolas[j].local.y);
			if (t <= listaescolas[j].raio) {
				printf("%d ", j);
				esc = 0;
			}
		}
		if (esc)
			printf("-1\n");
		else
			printf("\n");
	}
}

float dist(int x1, int x2, int y1, int y2)
{
	return (sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2)));
}
