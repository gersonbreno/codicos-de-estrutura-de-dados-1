#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *v = (int*) malloc(sizeof(int));
	int i, x;
	int maior = 0, igual = 0;	

	printf("digite o numro de vetores: ");
	scanf("%d", &n );

	for(i = 0; i < n; i++)
	{
		printf("digites os valores do vetor [%d] =  ", i);
		scanf("%d", &v[i]);
	}	

printf("informe o valor a ser procurado: ");
 scanf("%d", &x);
 	 maior = 0;
 	 igual = 0;
 	 for(i = 0; i < n; i++)
	  {
		  if(v[i] > x)
		  	maior++;
		  else igual++;
		  {
			 if(x > 0)
			 {
				printf("os valores maiores ou igual %d no vetor sao: \n", x); 
				for(i = 0; i < n; i++)
				{
					if(v[i] > x || v[i] == x)
						printf("%d \n", v[i]);
				}
			 } 
		  }
		  
	  }
	 
	
	return 0;
}