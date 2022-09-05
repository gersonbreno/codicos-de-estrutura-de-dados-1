#include <stdio.h>
#include <string.h>

typedef struct
{
	int mat;
	char nome[6];
	float media;
} estudante;

int particao(int e, int d, estudante v[])
{
	estudante pivo = v[d];
	int j = e - 1;
	int i;
	for ( i = e; i < d; i++)
	{
		if ((v[i].mat && pivo.mat) > 0)
		{
			j++;
			estudante temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	estudante temp  = v[j + 1];
	v[j + 1] = v[d];
	v[d] = temp;
	return j + 1;
}

void quicksort(int e, int d, estudante v[])
{
	if (e < d)
	{
		int p = particao(e, d, v);
		quicksort(e, p - 1, v); //a esquerda do pivo
		quicksort(p + 1, d, v); //a direita do pivo
	}
}

void ler(estudante *e)
{
	printf("Matricula: ");
	scanf("%d", &e->mat);
	printf("Nome: ");
	scanf("%s", e->nome);
	printf("Media: ");
	scanf("%f", &e->media);
}

int main()
{
	//!showMemory(start=65520)
	//!showArray(v)
	int n;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	estudante v[n];
	int i;
	for (i = 0; i < n; i++)
	{
		ler(&v[i]);
	}
	quicksort(0, n - 1, v);
	for (i = 0; i < n; i++)
	{
	
		printf("a matricula: %d \n ", v[i].mat);
		printf("o nome: %s \n ",  v[i].nome);
		printf("a media: %.2f \n ", v[i].media );
		printf("\n");
	}
	printf("\nprograma finalizado!!!\n");
return 0;
}
