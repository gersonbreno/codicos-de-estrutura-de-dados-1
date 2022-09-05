#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char usuario[10];
	int senha;
	char nome[50];
	float preco;
} Pizzaria;

int main(int argc, char** argv)
{
	Pizzaria c;
  int senha;
  char usuario[50];
	printf("crie seu nome de usario:");
	scanf("%s", c.usuario);
	printf("crie sua senha:");
	scanf("%d", &c.senha);
	printf("digite seu nome de usuario: ");
	scanf("%s", usuario);
	printf("digite sua senha: ");
	scanf("%d", &senha);
		if(strcmp(c.usuario, usuario) == 0  && c.senha == senha)
				{
					printf("bem vindo ao sistema\n");
				}
				else
				{
					printf("erro tente novamente \n");
				}
	
	
	return 0;
}