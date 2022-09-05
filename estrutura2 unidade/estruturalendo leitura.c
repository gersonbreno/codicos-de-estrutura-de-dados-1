#include <stdio.h>
#include <ctype.h>
int main()
{
	char entrada[131];
	char saida[131];
	int c;
	FILE* fp = fopen(entrada, "rt");
	printf("Nome do aquivo de entrada: ");
	scanf("%130s", entrada);
		printf("Nome do aquivo de saida: ");
	scanf("%130s", saida);
	FILE* fp_e = fopen(entrada, "rt");
	
	if(fp_e == NULL)
	{
		printf("erro na abertura de entrada \n");
		return 1;
	}
		FILE* fp_s = fopen(saida, "wt");
			if(fp_s == NULL){
		printf("erro na abertura de saida \n");
	fclose(fp_e);
	return 1;
	}
	while((c = fgetc(fp_e)) != EOF)
	{
	fputc(toupper(c), fp_s);	
	}
	fclose(fp_e);
	fclose(fp_s);
	
	return 0;
}