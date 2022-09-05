#include <stdio.h>

int main()
{
		int mat[3][3], i, j;

	for(i = 0; i < 3; i++) 
	{
		for(j = 0; j < 3; j++)
		{
			printf("digite os valor %d , %d: ", i , j);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("imprimindo matrix original");
		for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
		
			printf("posicao %d, %d = %d\n ",i , j ,mat[i][j]);
		
			
		}
	}

	return 0;
}