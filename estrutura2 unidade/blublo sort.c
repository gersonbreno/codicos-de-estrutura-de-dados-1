#include <stdio.h>

void bolha(int n, int *v)
{
	int i, j;
	for(i = n - 1; i > =1 ; i--)
	{
		for(j = 0; j < i; j++){
			if(v[j] > v[j + 1]){
				int temp = v[j];
				v[j] = v[]
			}
		}
		
	}
	
}

int main()
{
	int vet[8] = {25,48,37,12,57,86,33,92};
	bolha(8, vet);
	int i;
	for(i = 0; i < 8; i++)
	{
		printf("%d\t", vet[i]);
		printf("\n");
	}
	
	return 0;
}