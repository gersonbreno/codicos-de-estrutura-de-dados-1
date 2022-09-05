#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} aluno;


int main()
{
	FILE *fd = fopen("./aluno.b", "ab");
	int n;
	printf("digite o numeros de alunos: ");
	scanf("%d", &n);
	aluno	v[n];
	int i;
	
		
	for(i = 0; i < n; i++)
	{
	printf("digite o nome do aluno: ");
	scanf("%s", v[i].nome);	
	printf("digite a idade do aluno: ");
	scanf("%d", &v[i].idade);
	printf("digite o telofone do aluno: ");
	scanf("%d", &v[i].telefone);
	printf("\n");

	}
	fwrite(v, sizeof(aluno), n, fd);
	fclose(fd);
 	
	FILE *fa = fopen("./aluno.b", "rb");
	fread(v, sizeof(aluno), n, fa);
	for(i = 0; i < n; i++)
	{		
		printf("o nome do aluno: %s \n", v[i].nome);
		printf("a idade do aluno: %d anos\n", v[i].idade);
		printf("o telefone do aluno: %d\n", v[i].telefone);
		printf("\n");
	}



	fclose(fa);

	return 0;
}
