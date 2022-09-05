#include <stdio.h>

int main()
{
	int n;
	printf("digite a quantidade de valores: ");
	scanf("%d", &n);
	int i;
	int pares = 0;
	int impares = 0;
	int valor;
	for(i = 0; i < n; i++)
	{
		printf("informe os numeros: %d: ", i);
		scanf("%d", &valor);
		if(valor % 2 == 0)
		{
		pares++;	
		}
		if(valor % 2 != 0)
		{
			impares++;
		}
	}
printf("pares %d\n", pares);
printf("impares %d\n", impares);
	return 0;
}