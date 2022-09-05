#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} aluno;




void ler(aluno *e) {
	printf("Informe o nome do aluno: ");
	scanf("%s", e->nome);
	printf("Informe a idade do aluno: ");
	scanf("%d", &e->idade);
	printf("Informe o numero de telfone: ");
	scanf("%d", &e->telefone);
	printf("\n");
}
void cadastrar() {

	FILE *fd = fopen("./aluno.b", "ab");
	aluno e;
	ler(&e);
	fwrite(&e, sizeof(aluno), 1, fd);
	fclose(fd);
	

}

void listar() {
	FILE *fd = fopen("./aluno.b", "rb");
	aluno e;
	printf("exibindo os dados dos alunos cadrastado \n");
	while (fread(&e, sizeof(aluno), 1, fd)) {
		printf("=========================================\n");
		printf("o nome do aluno: %s \n", e.nome);
		printf("a idade do aluno: %d anos\n", e.idade);
		printf("o telefone do aluno: %d\n", e.telefone);
		printf("\n");
	}
	fclose(fd);
}

void menu(){
	printf("=== escolha uma das seguintes opcao ===\n");
	printf("1 - cadastrar\n");
	printf("2 - listar\n");
	printf("3 - sair \n");
	printf("========================================\n");
}
int main()
{
	int n, op;
	int i;
	do
	{
		
	
	menu();
	scanf("%d", &op);
switch(op)
{
case 1:
	printf("digite o toltal de alunos que voce deseja cadrastar: ");
	scanf("%d", &n);

	for(i = 0; i < n ; i++)
	{
		cadastrar();
	}
	break;
case 2:
	listar();
	break;
case 3:
	printf("saindo....\n");
	break;
default:
	break;
}
} while(op != 3);
	return 0;
}
