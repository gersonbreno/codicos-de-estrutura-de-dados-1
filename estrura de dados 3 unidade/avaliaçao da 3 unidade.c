#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int cpf;
	char nome[40];
	int idade;

} funcionario;
struct No
{
	funcionario dado;
	struct No* prox;
};
typedef struct
{
	struct No* inicio;

} Lista;


void ler( funcionario *a)
{
	printf("Informe o CPF do funcionario: ");
	scanf("%d", &a->cpf);
	printf("Informe o nome do funcionario: ");
	scanf("%s", a->nome);
	printf("Informe a idade do funcionario: ");
	scanf("%d", &a->idade);

}
void inserir_inicio(Lista* plista, funcionario dado)
{
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;

}

void Inseri_fim(Lista *plista, funcionario dado)
{
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = NULL;
	if(plista->inicio == NULL)
	{
		plista->inicio = novo;
	}
	else
	{
		struct No* pi;

		for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
		pi->prox = novo;
	}

}

struct No* inseri_apos(Lista *plista, funcionario dado, int cpf )
{
	struct No * pi;
	for(pi = plista->inicio; pi != NULL && pi->dado.cpf != cpf; pi = pi->prox);
	if(pi == NULL)
	{
		return pi;
	}
	else
	{
		struct No* novo = (struct No*) malloc(sizeof(struct No));
		novo->dado = dado;
		novo->prox = pi->prox;
		pi->prox = novo;
		return pi;
	}
}
void deletar_inicio(Lista *plista)
{
	if(plista->inicio == NULL)
	{
			printf("\n");
		printf("A lista esta vazia \n");
			printf("\n");
	}
	else
	{
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}


}
void deletar_por_valor(Lista *plista, int cpf)
{
	if(plista->inicio == NULL)
	{
		printf("\n");
		printf("A lista esta vazia. \n");
		printf("\n");
	}
	else if(plista->inicio->dado.cpf == cpf)
	{
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	else if(plista->inicio->prox == NULL)
	{
		if(plista->inicio->dado.cpf != cpf)
		{
			printf("\n");
			printf("o funcionario nao pode ser removido. \n");
			printf("\n");
		}
	}
	else
	{
		struct No* pa;
		struct No* pi;
		for(pi = plista->inicio; pi != NULL && pi->dado.cpf != cpf ; pi = pi->prox)
		{
			pa = pi;
		}
		if(pi == NULL)
		{
			printf("\n");
			printf("O funcinario nao pode ser removido \n");
			printf("\n");
		}
		else
		{
			pa->prox = pi->prox;
			free(pi);
		}
	}

}


void mostra(Lista lista)
{
	struct No * pi;
	for(pi = lista.inicio; pi != NULL  ; pi = pi->prox)
	{
		printf("seu cpf e: %d \n", pi->dado.cpf);
		printf("seu nome e: %s \n", pi->dado.nome);
		printf("sua idade e : %d anos \n", pi->dado.idade);
		printf("\n");
	}
}

void menu()
{
	printf("==escolha uma opcao=======\n");
	printf("1 - inseri inicio \n");
	printf("2 - inseri fim\n");
	printf("3 - inseri apos \n");
	printf("4 - mostra lista \n");
	printf("5 - pesquisa por cpf \n");
	printf("6 - deleta inicio \n");
	printf("7 - deletar por cpf \n");
	printf("8- sair \n");
	printf("============================\n");
}
struct No * pesquisa(Lista lista, int cpf)
{
	struct No* pi;
	for(pi = lista.inicio ; pi != NULL && pi->dado.cpf != cpf; pi = pi->prox );
	return pi;
}
int main()
{
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 8 )
	{
		if(op == 1)
		{
			funcionario e;
			ler(&e);
			inserir_inicio(&lista, e);
		}
		if(op == 2)
		{
			funcionario e;
			ler(&e);
			Inseri_fim(&lista, e);
		}
		if(op == 3)
		{
			funcionario e;
			ler(&e);void deletar_por_valor(Lista *plista, int cpf)
{
	if(plista->inicio == NULL)
	{
		printf("\n");
		printf("A lista esta vazia. \n");
		printf("\n");
	}
	else if(plista->inicio->dado.cpf == cpf)
	{
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	else if(plista->inicio->prox == NULL)
	{
		if(plista->inicio->dado.cpf != cpf)
		{
			printf("\n");
			printf("o funcionario nao pode ser removido. \n");
			printf("\n");
		}
	}
	else
	{
		struct No* pa;
		struct No* pi;
		for(pi = plista->inicio; pi != NULL && pi->dado.cpf != cpf ; pi = pi->prox)
		{
			pa = pi;
		}
		if(pi == NULL)
		{
			printf("\n");
			printf("O funcinario nao pode ser removido \n");
			printf("\n");
		}
		else
		{
			pa->prox = pi->prox;
			free(pi);
		}
	}

}


			int cpf;
			printf("informe o cpf do funcionario para inseri apos: ");
			scanf("%d", &cpf);
			struct No* pi =	inseri_apos(&lista, e, cpf);
			if(pi == NULL)
			{
				printf("nao foi possivel inserir o funcionario \n");
			}

		}
		if(op == 4)
		{
			mostra(lista);
		}
		if(op == 5)
		{
			int cpf;
			printf("informe o cpf que deseja pesquisa: ");
			scanf("%d", &cpf);
			struct No* pi = pesquisa(lista, cpf);
			if(pi != NULL)
			{
				printf("===exibindo os dados da pesquisa=========\n");
				printf("o seu cpf e: %d \n", pi->dado.cpf);
				printf("o seu nome e: %s \n", pi->dado.nome);
				printf("a sua idade e: %d \n", pi->dado.idade);
				printf("=========================================\n");
			}
			else
			{
				printf("o funcionario nao foi encontrado tente novamente\n");
			}
		}
		if(op == 6)
		{
			deletar_inicio(&lista);
		}
		if(op == 7)
		{
		int cpf;
		printf("digite o cpf que voce deseja deletar: ");	
		scanf("%d", &cpf);
		deletar_por_valor(&lista, cpf);
		}
		
		menu();
		scanf("%d", &op);
	}
	printf("saindo.. \n");
	return 0;
}
