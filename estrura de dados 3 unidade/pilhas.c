#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int mat;
	char nome[50];
} estudante;

struct no
{
	estudante dado;
	struct no* prox;
};
typedef struct no No;

typedef struct
{
	No* topo;
} Pilha;

void ler(estudante *pe)
{
	printf("digite a matricula: ");
	scanf("%d", &pe->mat);
	printf("digite o nome: ");
	scanf("%s", pe->nome);
}

void inseri(Pilha *ppilha, estudante dado)
{
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = ppilha->topo;
	ppilha->topo = novo;
}
void mostra(Pilha pilha)
{
	No * pi;
	for(pi = pilha.topo ; pi != NULL  ; pi = pi->prox   )
	{
		printf("o nome: %s\n", pi->dado.nome);
		printf("matricula: %d\n", pi->dado.mat);
		printf("\n");
	}
}
void remover(Pilha* ppilha)
{
	if(ppilha->topo == NULL)
	{
		printf("a pilha esta vazia\n");
	}
	else
	{
		No * pi = ppilha->topo;
		ppilha->topo = pi->prox;
		free(pi);

	}
}

int vazia(Pilha pilha)
{
	if(pilha.topo == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
No* topo(Pilha pilha)
{
	return pilha.topo;
}

void inverter(Pilha* ppilha)
{
	Pilha aux;
	aux.topo = NULL;
	No* pi;
	for(pi = ppilha->topo; pi != NULL; pi = ppilha->topo)
	{
		inseri(&aux, pi->dado);
		remover(ppilha);
	}
	ppilha->topo = aux.topo;

}

Pilha ler_aquivo()
{
	FILE* fe = fopen("./estudante.b", "rb");
	Pilha pilha;
	pilha.topo = NULL;
	estudante e;
	while(fread(&e, sizeof(estudante), 1, fe))
	{
		inseri(&pilha, e);
	}
	inverter(&pilha);
	fclose(fe);
	return pilha;
}


void salva(Pilha pilha)
{
	FILE* fe = fopen("./estudante.b", "wb");
	No* pi;
	for(pi = pilha.topo;pi != NULL ; pi = pi->prox)
	{
	fwrite(&pi->dado, sizeof(estudante), 1 , fe);	
	}
	
	
fclose(fe);
}



void menu()
{
	printf("===escolha uma opcao======\n");
	printf("1 - para adicionar\n");
	printf("2 - mostrar\n");
	printf("3 - remove um estudante\n");
	printf("4 - vazia\n");
	printf("5 - topo\n");
	printf("6 - inverte pilha\n");
	printf("7 - salva\n");
	printf("8 - ler de um aquivo\n");
	printf("9 - sair\n");
	printf("===========================\n");

}
int main()
{
	Pilha pilha;
	pilha.topo = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 9)
	{
		if(op == 1)
		{
			estudante e;
			printf("informe os dados dos estudantes: \n");
			ler(&e);
			inseri(&pilha, e);
		}
		if(op == 2)
		{
			mostra(pilha);
		}
		if(op == 3)
		{
			remover(&pilha);
		}
		if(op == 4)
		{
			int r =	vazia(pilha);
			if( r != 0)
			{
				printf("Pilha esta vazia \n");
			}
			else
			{
				printf("a Pilha contem elementos \n");
			}
		}
		if(op == 5)
		{
			No* pi = topo(pilha);
			if(pi == NULL)
			{
				printf("pilha vazia \n");
			}
			else
			{
				printf("o nome: %s\n", pi->dado.nome);
				printf("matricula: %d\n", pi->dado.mat);
				printf("\n");
			}
		}

		if(op == 6)
		{
			inverter(&pilha);
		}
		
		if(op == 7)
		{
			salva(pilha);
		}
		
		if(op == 8)
		{
		 pilha =  ler_aquivo();  
		}
		menu();
		scanf("%d", &op);
	}

printf("saindo......\n");
printf("obrigado por testa nosso software\n");



	return 0;
}
