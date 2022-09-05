#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
	int aux, i , j, igual;
	char palava[10], inversa[10];
	char op;
	do
	{
		

	printf("digite uma palvra: ");
	scanf("%s", palava);
	
	aux = strlen(palava);
	for(i = aux - 1, j = 0; i >= 0 ; i--, j++)
	{
		inversa[j] = palava[i];
	}
	igual = strcmpi(palava, inversa);
	if(igual == 0)
	{
		printf("a palavra e um palindromo\n");
	}
	else
	{
			printf("a palavra nao e um palindromo\n");
	}
	printf("se quise continua tecle S ou N para sair");
	scanf("%s", &op);
	} while(op != 'n');
	return 0;
}