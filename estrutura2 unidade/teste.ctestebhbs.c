#include<stdio.h>
#include<stdlib.h>

struct cliente
{
	char login[20];
	char email[20];
	int senha;
};

struct endereco_cliente
{
	char cidade[25];
	char estado[25];
	int cep;
};

struct produto
{
	float p1;
	float p2;
	float p3;
	struct cliente clit;
	struct endereco_cliente endereco;
};
int main()
{

	return 0;
}
