#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bloco
{
	int cod;
	char nome[10];

};
struct sala
{
	int	codico;
	char nome[10];
	char tipo;
	struct bloco predio;
};

void menu()
{
	printf("==escolha uma opcao \n");
	printf("1 pesquisa \n");
	printf("2 sair \n");
}
int main()
{
	int n;
	printf("informe a quantidade de sala: \n");
	scanf("%d", &n);

struct sala *v = (struct sala*) malloc(n* sizeof(struct sala);
int i;
for(i = 0; i < n; i++)
{
	scanf("%d %s %d %d %s",&v[i].cod, v[i].predio.nome);
}



	return 0;
}
