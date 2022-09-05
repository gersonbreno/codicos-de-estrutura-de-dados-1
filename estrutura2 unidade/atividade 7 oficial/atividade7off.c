#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} funcionario;




void ler(funcionario *e) {
	printf("Informe o nome do funcionario: ");
	scanf("%s", e->nome);
	printf("Informe a idade do funcionario: ");
	scanf("%d", &e->idade);
	printf("Informe o numero do telfone: ");
	scanf("%d", &e->telefone);
	printf("\n");
}
void cadastrar() {

	FILE *fd = fopen("./funcionario.b", "ab");
	funcionario e;
	ler(&e);
	fwrite(&e, sizeof(funcionario), 1, fd);
	fclose(fd);
	

}

void listar() {
	FILE *fd = fopen("./funcionario.b", "rb");
	funcionario e;
	printf("---------------------------------------------------\n");
	printf("exibindo os dados dos funcionarios cadrastados \n");
	while (fread(&e, sizeof(funcionario), 1, fd)) {
		printf("=========================================\n");
		printf("o nome do funcionario: %s \n", e.nome);
		printf("a idade do funcionario: %d anos\n", e.idade);
		printf("o telefone do funcionario: %d\n", e.telefone);
		printf("\n");
	}
	fclose(fd);
}

void menu(){
	printf("=== escolha uma das seguintes opcao ===\n");
	printf("1 - cadastrar\n");
	printf("2 - listar\n");
	printf("3 - sair \n");
	printf("\n");
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
	printf("digite o toltal de funcionarios que voce deseja cadrastar: ");
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
	printf("obrigado por testa nosso programa \n");
	printf("saindo....\n");
	break;
default:
	printf("opcao invalida por favor tente novamente! \n");
	break;
}
} while(op != 3);
	return 0;
}
