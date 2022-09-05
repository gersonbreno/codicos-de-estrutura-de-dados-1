#include <stdio.h>
#include <stdlib.h>
struct funcionario
{
	char nome[40];
	int idade;
	int telefone;
};
struct endereco_funcionario
{
	char estado[10];
	char cidade[30];
	int cep;
};
struct salario
{
	float s1;
	float s2;
	float s3;
	struct funcionario func;
	struct endereco_funcionario endereco;

};
int main()
{

	return 0;
}
