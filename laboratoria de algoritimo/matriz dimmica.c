#include <stdio.h>
#include <stdlib.h>

float* transporta_Simples(float* mat, int m, int n){
	float* trp = (float*) malloc(n*m* sizeof(float));
	int i, j;
	for(i = 0; i < m; i++)
	{
	for(j = 0; j < n; j++)
	{
	trp[j*m+i]	= mat[i*n+j];
	


}
	}
	return trp;
}
float** transporta_vetor(float** mat, int m, int n){
	float** trp = (float**) malloc(n*sizeof(float*));
	int i , j;
	for(i = 0; i < n ; i++)
	{
		trp[i] = (float*) malloc(m*sizeof(float));
		for(i = 0; i < m ; i++)
			for (j = 0; j < n; j++)
				trp[j][i] = mat[i][j];
	}
	return trp;
}

int main()
{
	float* mat_simples = (float*) malloc(3*2* sizeof(float));
	int i , j;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2 ; j++)
		{
			printf("digite mat [%i] [%i]: ", i , j);
			scanf("%f", &mat_simples[i*2+j]);
		}
		float* trp_simples = transporta_Simples(mat_simples, 3 , 2);
		printf("matriz original \n");
		for (i = 0; i < 3; i++){
			for(j = 0; j < 2; j++)
			 	printf("%f\t", mat_simples[i*2+j]);
		}
		printf("\n");
	}
		printf("matriz transporta \n");
		for (i = 0; i < 2; i++){
			for(j = 0; j < 3; j++)
				printf("%f\t", trp_simples[i*3+j]);
		}
		printf("\n");
	}
	
	
	
return 0;
}