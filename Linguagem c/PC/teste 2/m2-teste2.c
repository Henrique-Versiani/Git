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

	scanf("%d", qdel);
	for (i = 0; i < *qdel; i++) {
		scanf("%d %d %f %d", &listadelegacias[i].local.x,
		      &listadelegacias[i].local.y, &listadelegacias[i].raio,
		      &listadelegacias[i].capac);
	}
	scanf("%d", qvit);
	for (i = 0; i < *qvit; i++) {
		scanf("%d %d", &listavitimas[i].local.x,
		      &listavitimas[i].local.y);
	}
}

vitima questao02(int esc, int est)
{
	int i, j;
	int m;
	float d, t;

	m = -1;
	d = 10000.0;

	for (i = 0; i < est; i++) {
		for (j = 0; j < esc; j++) {
			t = dist(listavitimas[i].local.x,
				 listadelegacias[j].local.x,
				 listavitimas[i].local.y,
				 listadelegacias[j].local.y);
			if (t < d) {
				d = t;
				m = i;
			}
		}
	}
	return listavitimas[m];
}

void questao03(vitima x)
{
	printf("%d %d\n", x.local.x, x.local.y);
}

void questao04(int qdel, int qvit)
{
	int i, j, m;
	float t, d;
	int cont[MAXDELEGACIAS] = { 0 };

	for (i = 0; i < qvit; i++) {
		m = -1;
		d = 10000.0;
		for (j = 0; j < qdel; j++) {
			t = dist(listavitimas[i].local.x,
				 listadelegacias[j].local.x,
				 listavitimas[i].local.y,
				 listadelegacias[j].local.y);
			if (t <= listadelegacias[j].raio) {
				if (t < d) {
					d = t;
					m = j;
				}
			}
		}
		cont[m]++;
	}
	for (i = 0; i < qdel; i++) {
		printf("%d: %d", i, cont[i]);
		if (cont[i] < listadelegacias[i].capac) {
			printf("-\n");
		} else if (cont[i] == listadelegacias[i].capac) {
			printf("=\n");
		} else {
			printf("+\n");
		}
	}
}

float dist(int x1, int x2, int y1, int y2)
{
	return (sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2)));
}
