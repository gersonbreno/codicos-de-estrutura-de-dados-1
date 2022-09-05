#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} funcionario;
typedef struct
{
   char estado[10];
   char cidade[30];	
   int cep;
} endereco_funcionario;
typedef  struct 
{
	float s1;
	float s2;
	float s3;
	 funcionario func;
	 endereco_funcionario endereco;
	
}salario;

void ler_funcionario( salario *ps ){
	printf("digite seu nome: ");
	scanf("%s", ps->func.nome);
	printf("digite sua idade: ");
	scanf("%d", &ps->func.idade);
	printf("digite seu telefone: ");
	scanf("%d", &ps->func.telefone);
	printf("digite seu estado: ");
	scanf("%s", ps->endereco.estado);
	printf("digite sua cidade: ");
	scanf("%s", ps->endereco.cidade);
	printf("digite seu cep: ");
	scanf("%d", &ps->endereco.cep);
	printf("digite seu priemiro salario: ");
	scanf("%f", &ps->s1);
	printf("digite seu segundo salario: ");
	scanf("%f", &ps->s2);
	printf("digite seu terceiro salario: ");
	scanf("%f", &ps->s3);
}
void imprime_funcionario( salario ps)
{
	printf("\n");
	printf("os dados do funcionario \n");
	printf("============================================================\n");
	printf("nome do funcionario: %s \n", ps.func.nome);
	printf("idade do funcionario: %d\n", ps.func.idade);
	printf("telefone do funcionario: %d\n", ps.func.telefone);
	printf("estado do funcionario: %s \n", ps.endereco.estado);
	printf("cidade do funcionario: %s\n", ps.endereco.cidade);
	printf("cep do funcionario: %d\n", ps.endereco.cep);
	printf("primeiro salario do funcionario: %.2f\n", ps.s1);
	printf("segundo salario do funcionario: %.2f\n", ps.s2);
	printf("terceiro salario do funcionario: %.2f\n", ps.s3);
	printf("\n");
}
void imprime_funcionarioPonteiro( salario *ps)
{
	printf("\n");
	printf("os dados do funcionario usando ponteiro \n");
	printf("============================================================\n");
	printf("nome do funcionario: %s \n", ps->func.nome);
	printf("idade do funcionario: %d\n", ps->func.idade);
	printf("telefone do funcionario: %d\n", ps->func.telefone);
	printf("estado do funcionario: %s \n", ps->endereco.estado);
	printf("cidade do funcionario: %s\n", ps->endereco.cidade);
	printf("cep do funcionario: %d\n", ps->endereco.cep);
	printf("primeiro salario do funcionario: %.2f\n", ps->s1);
	printf("segundo salario do funcionario: %.2f\n", ps->s2);
	printf("terceiro salario do funcionario: %.2f\n", ps->s3);
	printf("\n");
}
void menu(){
printf("====escolha uma das opcao seguintes==========\n");
printf("1 - para cadratar os dados do funcionario \n");
printf("2 - para imprime os dados do funcionario sem ponteiro \n");
printf("3 - para imprimi os dados do funcionario com ponteiro \n");
printf("4 - para sair \n");

}
int main()
{
	int op;
	salario ps;
	do
	{
		

menu();
scanf("%d", &op);
switch(op)
{
case 1:
		ler_funcionario(&ps);
	break;
case 2:
	imprime_funcionario(ps);
	break;
case 3:
	imprime_funcionarioPonteiro(&ps);
	break;
case 4:
	printf("saindo......\n");
	break;
default:
	printf("erro comando invalido!!\n");
	break;
}
	} while(op != 4);
	return 0;
}