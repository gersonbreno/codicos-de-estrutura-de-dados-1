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

	}
	// para copia para o aquivo texto
  FILE *fd = fopen("./alunos.txt", "a");
	for(i = 0; i < n; i++)
	{
		fprintf(fd, "%s \n", v[i].nome);
		fprintf(fd,"%d \n", v[i].idade);
		fprintf(fd,"%d \n", v[i].telefone);
		printf("\n");
	} 
		fclose(fd);
	// para pega aonde ficou salvo o aquivo de texto
	FILE *fa = fopen("./alunos.txt", "r");
	aluno e;
	while (fscanf(fd, "%s %d %d",  e.nome, &e.idade, &e.telefone) != EOF)
	{
		printf("o nome do aluno: %s \n", e.nome);
		printf("a idade do aluno: %d anos\n", e.idade);
		printf("o telefone do aluno: %d\n", e.telefone);
		printf("\n");
	}
	fclose(fa);
	//usei esse /fa/ pq nao podia usar o fd 
	return 0;
}
