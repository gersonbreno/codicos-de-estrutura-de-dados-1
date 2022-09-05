#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int mat;
	char nome[20];
	float media;
} estudante;

void menu()
{
	printf("==escolha uma opcao ==\n");
	printf("1 - adicionar estudante\n");
	printf("2 - listar estudantes\n");
	printf("3 - atualizar media\n");
	printf("4 - deletar todos\n");
	printf("5 - tamanho\n");
	printf("6 - deletar estudante\n");
	printf("10 - sair\n");
	printf("========================\n");
}

void lerEstudante(estudante *pe)
{
	printf("Informe os dados do estudante\n");
	printf("Matricula: ");
	scanf("%d", &pe->mat);
	printf("Nome: ");
	scanf("%s", pe->nome);
	printf("Media: ");
	scanf("%f", &pe->media);
}

void adicionarEstudante(estudante e)
{
	FILE *f = fopen("./estudantes.txt", "a");
	fprintf(f, "%d %s %.2f\n", e.mat, e.nome, e.media);
	fclose(f);
}

void salvarTodos(estudante v[], int n)
{
	FILE *f = fopen("./estudantes.txt", "w");
	int i;
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%d %s %.2f\n",
				v[i].mat, v[i].nome, v[i].media);
	}
	fclose(f);
}

int size()
{
	FILE * f = fopen("./estudantes.txt", "r");
	estudante e;
	int i = 0;
	while (fscanf(f, "%d %s %f",
				  &e.mat, e.nome, &e.media) != EOF)
	{
		i++;
	}
	fclose(f);
	return i;
}

void atualizarMedia(int mat, float novamedia)
{
	FILE * f = fopen("./estudantes.txt", "r");
	int tamanho = size();
	estudante v[tamanho];
	int i = 0;
	while (fscanf(f, "%d %s %f",
				  &v[i].mat, v[i].nome, &v[i].media) != EOF)
	{
		if (v[i].mat == mat)
		{
			v[i].media = novamedia;
		}
		i++;
	}
	fclose(f);
	printf("Salvando dados dos estudantes\n");
	salvarTodos(v, i);
}

void deletarEstudante(int mat)
{
	FILE * f = fopen("./estudantes.txt", "r");
	int tamanho = size();
	estudante v[tamanho];
	int i = 0;
	estudante e;
	while (fscanf(f, "%d %s %f",
				  &e.mat, e.nome, &e.media) != EOF)
	{
		if (e.mat != mat)
		{
			v[i] = e;
			i++;
		}
	}
	fclose(f);
	printf("Salvando dados dos estudantes\n");
	salvarTodos(v, i);
}

void listar()
{
	FILE *f = fopen("./estudantes.txt", "r");
	estudante e;
	while (fscanf(f, "%d %s %f",  &e.mat, e.nome, &e.media) != EOF)
	{
		printf("%d %s %.2f\n", e.mat, e.nome, e.media);
	}
	fclose(f);
}

void deletar()
{
	FILE * f = fopen("./estudantes.txt", "w");
	fclose(f);
}

int main()
{
	menu();
	int op;
	scanf("%d", &op);
	while (op != 10)
	{
		if (op == 1)
		{
			estudante e;
			lerEstudante(&e);
			adicionarEstudante(e);
		}
		if (op == 2)
		{
			listar();
		}
		if (op == 3)
		{
			int mat;
			float novamedia;
			printf("Informe a matricula do estudante:\n");
			scanf("%d", &mat);
			printf("Nova media:\n");
			scanf("%f", &novamedia);
			atualizarMedia(mat, novamedia);
		}
		if (op == 4)
		{
			deletar();
		}
		if (op == 5)
		{
			int tamanho = size();
			printf("Tamanho da lista de estudantes: %d\n",
				   tamanho);
		}
		if (op == 6)
		{
			int mat;
			printf("Informe a matricular do estudante\n");
			scanf("%d", &mat);
			deletarEstudante(mat);
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}
