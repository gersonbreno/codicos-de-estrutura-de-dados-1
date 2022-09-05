#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} funcionario;

int main()
{
	int n;
	printf("digite o numeros de funcionarios: ");
	scanf("%d", &n);
	funcionario	v[n];
	int i;
	for(i = 0; i < n; i++)
	{
		printf("digite o nome do funcionario: ");
		scanf("%s", v[i].nome);
		printf("digite a idade do funcionario: ");
		scanf("%d", &v[i].idade);
		printf("digite o telofone do funcionario: ");
		scanf("%d", &v[i].telefone);

	}

	FILE *fd = fopen("./funcionario.txt", "a");
	for(i = 0; i < n; i++)
	{
		fprintf(fd, "%s \n", v[i].nome);
		fprintf(fd, "%d \n", v[i].idade);
		fprintf(fd, "%d \n", v[i].telefone);
		printf("\n");
	}
	fclose(fd);
	FILE *fa = fopen("./funcionario.txt", "r");
	funcionario e;
	while (fscanf(fd, "%s %d %d",  e.nome, &e.idade, &e.telefone) != EOF)
	{
		printf("o nome do funcionario: %s \n", e.nome);
		printf("a idade do funcionario: %d anos\n", e.idade);
		printf("o telefone do funcionario: %d\n", e.telefone);
		printf("\n");
	}
	fclose(fa);

	return 0;
}
