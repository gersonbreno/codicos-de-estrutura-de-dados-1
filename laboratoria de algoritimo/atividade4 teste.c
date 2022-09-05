#include <stdio.h>
#include <stdlib.h>
struct funcionario
{
	char nome[40];
	int idade;
	int telefone;
};
struct endereco_aluno
{
   char estado[10];
   char cidade[30];	
   int cep;
};
struct notas_aluno
{
	float n1;
	float n2;
	float n3;
	struct aluno alun;
	struct endereco_aluno endereco;
	
};

void ler_alunos(struct notas_aluno *ps ){
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
void imprime_alunos(struct notas_aluno ps)
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
int main()
{
	struct notas_aluno ps;
	char op;

do
{
	

	ler_alunos(&ps);
imprime_alunos(ps);
printf("voce deseja continiua tecle <S> ou <N> \n");
scanf("%s", &op);
} while(op == 's');	
	return 0;
}