#include <stdio.h>
#include <stdlib.h>
float media(int n, float* v)
{

	float s = 0.0f;

	int i;

	for(i = 0; i < n; i++)
	{

		s += v[i];

	}

	return s / n;

}



float variancia(int n, float* v, float m)
{

	float s = 0.0f;

	int i;

	for(i = 0; i < n; i++)

		s += (v[i] - m) * (v[i] - m);

	return s / n;

}

int main()
{

	float* vet;
	int i;

	vet = (float*)
	malloc(5*sizeof(float));
	if(vet == NULL)
	{
		printf("memoria insuficiente \n");
		exit(1);
	}
	for(i = 0; i < 5; i++) 
	{
 
		printf("Digite um numero real: ");

		scanf("%f", &vet[i]);

	}

	float med = media(5, vet);

	float var = variancia(5, vet, med);

	printf("Media = %.2f\tVariancia = %.2f\n", med, var);


free(vet);



	return 0;
}
