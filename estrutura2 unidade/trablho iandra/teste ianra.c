#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char login[40];
	char email[40];
	char endereco[40];
} cliente;

void ler(cliente *a)
{
	printf("Informe o login do usuario: ");
	scanf("%s", a->login);
	printf("Informe o e-mail do usuario: ");
	scanf("%s", a->email);
	printf("Informe o endereco do usuario: ");
	scanf("%s", a->endereco);
	printf("\n");
}

void cadastro()
{
	FILE *tb = fopen("./cliente.b", "ab");
	cliente a;
	ler(&a);
	fwrite(&a, sizeof(cliente), 1, tb);
	fclose(tb);
}

void lista()
{
	FILE *tb = fopen("./cliente.b", "rb");
	cliente a;

	printf("Lista de cliente ja cadastrados: \n");

	while (fread(&a, sizeof(cliente), 1, tb))
	{

		printf("O login do cliente: %s \n", a.login);
		printf("O e-mail do cliente: %s \n", a.email);
		printf("O endereco do cliente: %s \n", a.endereco);
		printf("\n");
	}
	fclose(tb);
}

void menu()
{
	printf("Escolha uma das opcoes a seguir: \n");
	printf("1-Fazer login: \n");
	printf("2-Lista de Clientes já cadastrados.. \n");
	printf("3-Sair. \n");
	printf("\n");
}

int main()
{
		int n;
	int tn;
	int i;
	do
	{
		
		menu();
		scanf("%d", &tn);


			if (tn == 1)
			{
				printf("Digite o numero de clientes a serem cadastrados: ");
				scanf("%d", &n);
				for(i = 0; i < n ; i++)
				{

					cadastro();
				}
				}

				  if(tn == 2)
				{
					
					lista();
				}

				 if(tn == 3)
				{
					printf("saindo.... \n");
					printf("Obrigada por usarem o nosso sistema, ate a proxima. \n");
				}

		
	
	} while(tn != 3);
	
	return 0;
}
