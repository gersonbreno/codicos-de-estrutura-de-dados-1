#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int mat;
	char nome[50];
} estudante;

struct  no
{
	estudante dado;
	struct no* prox;
};
typedef struct no No;

typedef struct
{
	No* inicio;
	No* fim;
} Fila;


void ler(estudante *pe)
{
	printf("digite a matricula: ");
	scanf("%d", &pe->mat);
	printf("digite seu nome: ");
	scanf("%s", pe->nome);
}

void inserir(Fila* pfila, estudante dado)
{
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = NULL;
	if(pfila->inicio == NULL)
	{
		pfila->inicio = novo;
		pfila->fim = novo;
	}
	else
	{
		pfila->fim->prox = novo;
		pfila->fim = novo;
	}
}
void mosttra(Fila fila)
{
	No* pi;
	for(pi = fila.inicio ; pi != NULL ; pi = pi->prox)
	{
		printf("seu nome: %s \n", pi->dado.nome);
		printf("sua matricula: %d\n", pi->dado.mat);
		printf("\n");
	}

}
void remover(Fila* pfila)
{
	if(pfila->inicio == NULL)
	{
		printf("a lista esta vazia\n");
	}
	else if(pfila->inicio->prox == NULL)
	{
		pfila->inicio = NULL;
		pfila->fim = NULL;
	}
	else
	{
		No * pi = pfila->inicio ;
		pfila->inicio = pi->prox;
		free(pi);
	}
}
int vazia(Fila fila)
{
	if(fila.inicio == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

No * inicio(Fila fila)
{
	return fila.inicio;
}
void salva(Fila fila)
{
	FILE* fe = fopen("./estudantes.b", "wb");
	No* pi;
	for( pi = fila.inicio; pi != NULL; pi = pi->prox)
	{
		fwrite(&pi->dado, sizeof(estudante), 1, fe);
	}

	fclose(fe);
}
Fila ler_aquivo()
{
	Fila fila;
	fila.inicio = NULL;
	fila.fim = NULL;
	FILE* fe = fopen("./estudantes.b", "rb");
	estudante e;
	while(fread(&e, sizeof(estudante), 1, fe))
	{
		inserir(&fila, e);
	}
	
	fclose(fe);
	return fila;
}
void menu()
{
	printf("====escolha umas das seguintes opcoes=======\n");
	printf("1 - inserir \n");
	printf("2 - mostrar \n");
	printf("3 - remover estudante \n");
	printf("4 - verifincado se a fila esta vazia \n");
	printf("5 - verifica inicio \n");
	printf("6 - salva para um aquivo \n");
	printf("7 - ler de um aquivo \n");
	printf("9 - sair \n");
	printf("============================================\n");
}

int main() 
{

	Fila fila;
	fila.inicio = NULL;
	fila.fim = NULL;

	int op;
	menu();
	scanf("%d", &op);
	while(op != 9)
	{
		if(op == 1)
		{
			estudante e;
			printf("informe os dados dos estudantes\n");
			ler(&e);
			inserir(&fila, e);
		}
		if(op == 2)
		{
			mosttra(fila);
		}
		if(op == 3)
		{
			remover(&fila);
		}
		if(op == 4)
		{
			int r = vazia(fila);
			if(r != 0)
			{
				printf("A fila esta vazia\n");
			}
			else
			{
				printf("A fila contem elementos\n");
			}
		}

		if(op == 5)
		{
			No* pi = inicio(fila);
			if(pi != NULL)
			{
				printf("seu nome: %s \n", pi->dado.nome);
				printf("sua matricula: %d\n", pi->dado.mat);
				printf("\n");
			}
			else
			{
				printf("Fila vazia \n");
			}
		}
		if(op == 6)
		{
			salva(fila);
		}
		
		if(op == 7)
		{
		fila = ler_aquivo();
		}
		menu();
		scanf("%d", &op);
	}


	return 0;
}
