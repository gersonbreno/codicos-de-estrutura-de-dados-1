#include <stdio.h>
#include <stdlib.h>



int main()
{
	int* v = (int* ) malloc(4*sizeof(int));
	int i;
	int* n = (int*) malloc(sizeof(int));
	for(i = 0; i < 4; i++)
	{
		printf("informe os valores ");
	scanf("%i", &v[i]);	
	}
	printf("informe o valor::");
	scanf("%i", &n);
	for(i = 0; i < 4 ; i++)
	{
		if(v[i] == *n)
		{
		printf("%i", i);	
		}
	}
	free(v);
	return 0;
}