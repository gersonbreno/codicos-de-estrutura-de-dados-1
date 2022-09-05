#include<stdio.h>

typedef struct
{
	int cpf;
	char nome[40];
	int idade;
	char endereco[40];
} funcionario;

void ler( funcionario *a)
{
	printf("Informe o CPF do funcionario: ");
	scanf("%d", &a->cpf);

	printf("Informe o nome do funcionario: ");
	scanf("%s", a->nome);
	printf("Informe a idade do funcionario: ");
	scanf("%d", &a->idade);
	printf("Informe o endereco do funcionario: ");
	scanf("%s", a->endereco);
	printf("\n");
}




void menu()
{
	printf("====Escolha uma das opcoes a seguir=============: \n");
	printf("1 - Lista funcionario \n");
	printf("2 - Buscar funcionario pela busca binaria. \n");
	printf("3 - Sair. \n");
	printf("\n");
}
int buscabinaria(funcionario v[], int n, int cpf){
	int i = 0;
	int f = n - 1;
	while(i<=f)
	{
		int c = (i + f) / 2;
		if(v[c].cpf == cpf)
		{
		return c;	
		}
		else if(v[c].cpf < cpf)
		{
			i = c + 1;
		}
		else
		{
			 f = c - 1;
		}
	}
	
	
	
	
		
		   return -1;	 
	
}

void lista(funcionario v[], int n)
{
	int i;
	printf("====quantidade de funcionarios cadastrados no momento: ============\n");
	for (i = 0; i < n; i++)
	{
		printf("CPF do funcionario: %d \n", v[i].cpf);
		printf("nome do funcionario: %s\n", v[i].nome);
		printf("idade do funcionario: %d anos\n", v[i].idade);
		printf("endereco do funcionario: %s\n", v[i].endereco);
		printf("\n");
	}
}


int main()
{
	int n;
	printf("Informe o numero de funcionario a serem cadratados: ");
	scanf("%d", &n);

	funcionario v[n];
	int i;
	for(i = 0; i < n; i++)
	{
		ler(&v[i]);
	}

	menu();
	int op;
	scanf("%d", &op);
  
   do
   {
	   
        if(op==1){
            lista(v, n);
        }
        
         if (op==2){
        	int cpf;
			printf("Informe o seu CPF que vc deseja pesquisa: \n");
			scanf("%d", &cpf);

			int index = buscabinaria(v, n, cpf);
			if(index == -1)
			{
				printf("\n");
				printf("CPF nao encontrado. \n");
				printf("\n");
			}
			else
			{
				printf("=======aqui esta os dados da sua busca=================\n");
				printf("o CPF: %d\n", v[index].cpf);
				printf("o nome: %s\n", v[index].nome);
			   	printf("a idade: %d anos\n", v[index].idade);
			   	printf("o endereco: %s\n", v[index].endereco); 
			   	printf("\n");
			}	
			}
    menu();
    scanf("%d", &op);
    
      
    if(op==3){
        printf("saindo..... \n \n"); 
	}
 
   } while(op != 3);


return 0;
}