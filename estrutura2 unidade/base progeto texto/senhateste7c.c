#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char usuario[10];
	char usuario2[10];
	int senha;
	char nome[50];
	float preco;
} Pizzaria;

int main(int argc, char** argv)
{
	char usuario[10];

		Pizzaria c;
				
	printf("crie seu nome de usario:");
	scanf("%s", c.usuario);
	printf("crie sua senha:");
	scanf("%d", &c.senha);

	printf("digite seu nome de usuario: ");
	scanf("%s", c.usuario);
	printf("digite sua senha: ");
	scanf("%d", &c.senha);
				if(strcmp(usuario, c.usuario) == 0  && c.senha == c.senha)
				{
					printf("bem vindo %s\n", c.usuario);
				}
				else
				{
					printf("flaha\n");
				}
				
	return 0;
}