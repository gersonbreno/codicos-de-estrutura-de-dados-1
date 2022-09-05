#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char nome[40];
	int idade;
	int telefone;
} aluno;
typedef struct
{
   char estado[10];
   char cidade[30];	
   int cep;
} endereco_aluno;
typedef  struct 
{
	float n1;
	float n2;
	float n3;
	 aluno alun;
	 endereco_aluno endereco;
	
}notas_aluno;

void ler_alunos( notas_aluno *ps ){
	printf("digite seu nome: ");
	scanf("%s", ps->alun.nome);
	printf("digite sua idade: ");
	scanf("%d", &ps->alun.idade);
	printf("digite seu telefone: ");
	scanf("%d", &ps->alun.telefone);
	printf("digite seu estado: ");
	scanf("%s", ps->endereco.estado);
	printf("digite sua cidade: ");
	scanf("%s", ps->endereco.cidade);
	printf("digite seu cep: ");
	scanf("%d", &ps->endereco.cep);
	printf("digite sua nota 1: ");
	scanf("%f", &ps->n1);
	printf("digite sua nota 2: ");
	scanf("%f", &ps->n2);
	printf("digite sua nota 3: ");
	scanf("%f", &ps->n3);
}
void imprime_alunos( notas_aluno ps)
{
	printf("\n");
	printf("os dados dos alunos sao: \n");
	printf("============================================================\n");
	printf("nome do aluno: %s \n", ps.alun.nome);
	printf("idade do aluno: %d\n", ps.alun.idade);
	printf("telefone do aluno: %d\n", ps.alun.telefone);
	printf("estado do aluno: %s \n", ps.endereco.estado);
	printf("cidade do aluno: %s\n", ps.endereco.cidade);
	printf("cep do aluno: %d\n", ps.endereco.cep);
	printf("nota 1 do aluno: %f\n", ps.n1);
	printf("nota 2 do aluno: %f\n", ps.n2);
	printf("nota 3 do aluno: %f\n", ps.n3);
}
void imprime_alunosPonteiro( notas_aluno *ps)
{
	printf("\n");
	printf("os dados dos alunos sao: \n");
	printf("============================================================\n");
	printf("nome do aluno: %s \n", ps->alun.nome);
	printf("idade do aluno: %d\n", ps->alun.idade);
	printf("telefone do aluno: %d\n", ps->alun.telefone);
	printf("estado do aluno: %s \n", ps->endereco.estado);
	printf("cidade do aluno: %s\n", ps->endereco.cidade);
	printf("cep do aluno: %d\n", ps->endereco.cep);
	printf("nota 1 do aluno: %f\n", ps->n1);
	printf("nota 2 do aluno: %f\n", ps->n2);
	printf("nota 3 do aluno: %f\n", ps->n3);
}
void menu(){
printf("====escolha uma das opçao seguintes==========\n");
printf("1 - para cadratar os dados do aluno \n");
printf("2 - para imprime os dados do aluno sem ponteiro \n");
printf("3 - para imprimi os dados do aluno com ponteiro \n");
printf("4 - para sair \n");
}
int main()
{
	int op;
	notas_aluno ps;
	do
	{
		

menu();
scanf("%d", &op);
switch(op)
{
case 1:
		ler_alunos(&ps);
	break;
case 2:
	imprime_alunos(ps);
	break;
case 3:
	imprime_alunosPonteiro(&ps);
	break;
case 4:
	printf("saindo......\n");
	break;
default:
	break;
}
	} while(op != 4);
	return 0;
}