#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
	int* pn;
	int n = 10;
	pn = &n;
	int aux = 0;

	int v[n];
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("digite os valores [%i] = " ,i);
		scanf("%d", v + i );
	
	if(*(v + i) % 2 == 0){
		aux = aux  + *(v + i);
		}	
	}

printf("a soma dos vetores pares sao  %i", aux);

	return 0;
}