#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *m = (int*) malloc(3*2*sizeof(int));
	int i, j;
	for( i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
		scanf("%i", (m + i * 2) + j);	
		}
	}
	return 0;
}