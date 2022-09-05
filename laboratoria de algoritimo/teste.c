#include <stdio.h>

int main()
{
	int vet[4];
	int i, aux = 0;
	for(i = 0; i < 4; i++)
	{
	printf("digete os valores na posiçao [%i] = ", i);
	scanf("%i", &vet[i]);
	if(vet[i] % 2 == 0)	{
		
	aux = aux + vet[i];
	}
	
	}

	printf("a sua soma foi %i \n",aux );

	return 0;
}