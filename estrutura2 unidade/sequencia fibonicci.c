#include <stdio.h>


int main(int argc, char** argv)
{
	int a, b, i, aux, tamanho;
	printf("digite ate que numero vc deseja pra sequencia de fibonicci: ");
	scanf("%d", &tamanho);
	a = 0;
	b = 1;
	for(i = 0; i < tamanho; i++)
	{
		aux = a + b;
		a= b;
		b = aux;
		
		printf("%d \n", aux);
	}
	
	return 0;
}