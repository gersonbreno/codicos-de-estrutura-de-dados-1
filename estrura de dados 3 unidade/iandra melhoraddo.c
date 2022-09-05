#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int cep;
	char login[40];
} cliente;

struct No
{
	cliente dado;
	struct No * prox;
};

typedef struct
{
	struct No* inicio;
} Lista;

void ler (cliente *pe)
{
	printf("digite o seu cep: ");
	scanf("%d", &pe->cep);
	printf("digite seu longin: ");
	scanf("%s",  pe->login);
	printf("\n");
}
void inserir_inicio(Lista *plista, cliente dado)
{
	struct No* novo = (struct No*) malloc(sizeof (struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}

void inserir_fim(Lista *plista, cliente dado)
{
	struct No* novo = (struct No*) malloc(sizeof (struct No));
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
struct No* pesquisar(Lista lista, int cep)
{
	struct No* pi;
	for (pi = lista.inicio; pi != NULL && pi->dado.cep != cep; pi = pi->prox);
	return pi;
}
void deletar_apos(Lista * plista, int cep)
{
	struct No * pa;
	struct No * pi;
	for(pa = plista->inicio; pa != NULL && pa->dado.cep != cep; pa = pa->prox);
	if(pa == NULL)
	{
		printf("O cliente nao pode ser removido. \n");
	}
	else if(pa->prox == NULL)
	{
		printf("O cliente nao pode ser removido. \n");
	}
	else
	{
		pi = pa->prox;
		pa->prox = pi->prox;
		free(pi);
	}
}



void deletar_por_valor(Lista *plista, int cep)
{
	if (plista->inicio == NULL)
	{
		printf("A lista esta vazia. \n");
	}
	else if(plista->inicio->dado.cep == cep)
	{
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	else if (plista->inicio->prox == NULL)
	{
		if(plista->inicio->dado.cep != cep)
		{
			printf("O cliente nao pode esr removido. \n");
		}
	}
	else if(plista->inicio->prox == NULL)
	{
		if (plista->inicio->dado.cep != cep)
		{
			printf("O cliente nao podeser removido. \n");
		}
	}
		else
		{
			struct No * pa;
			struct No * pi;
			for (pi = plista->inicio; pi != NULL && pi->dado.cep != cep; pi = pi->prox)
			{
				pa = pi;
			}
			if(pi == NULL)
			{
				printf("O estudante nao pode ser removido. \n");
			}
			else
			{
				pa->prox = pi->prox;
				free(pi);
			}
		}
	}



	void mostrar(Lista lista)
	{
		struct No * pi;
		for(pi = lista.inicio; pi != NULL; pi = pi->prox)
		{
			printf("o seu cep e: %d \n", pi->dado.cep);
			printf("o seu nome de usario e: %s \n", pi->dado.login);
			printf("\n");
		}
	}

	void menu()
	{
		printf("Escolha uma das opcoes a seguir: \n");
		printf("1 - Inserir no inicio da lista. \n");
		printf("2 - Inserir no fim da lista. \n");
		printf("3 - Mostar lista. \n");
		printf("4 - Pesquisar por cep. \n");
		printf("5 - Deletar por cep. \n");
		printf("6 - Deletar apos. \n");
		printf("7 - Sair. \n");
	}




	int main()
	{
		Lista lista;
		lista.inicio = NULL;
		int op;
		menu();
		scanf ("%d", &op);
		while(op != 7)
		{
			if(op == 1)
			{
				cliente e;
				ler (&e);
				inserir_inicio(&lista, e);
			}
			if (op == 2)
			{
				cliente e;
				ler (&e);
				inserir_fim(&lista, e);
			}
			if(op == 3)
			{
				mostrar(lista);
			}
			if(op == 4)
			{
				int cep;
				printf("Informe o cep \n");
				scanf("%d", &cep);
				struct No * pi = pesquisar(lista, cep);
				if (pi != NULL)
				{
					printf("\n");
					printf("seu cep e: %d \n", pi->dado.cep);
					printf("seu login e: %s  \n", pi->dado.login);
					printf("\n");
				}
				else
				{
					printf("Cliente nao encontrado. \n");
				}
			}
				if (op == 5)
			{
				int cep;
				printf("Informe o cep: \n");
				scanf("%d", &cep);
				deletar_por_valor(&lista, cep);
			}
				if (op == 6)
			{
				int cep;
				printf("Informe o cep: \n");
				scanf("%d", &cep);
				deletar_apos(&lista, cep);
			}
	   	menu();
		scanf("%d", &op);
	}
		return 0;
	}
