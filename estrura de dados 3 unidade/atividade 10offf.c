#include <stdio.h>
#include <stdlib.h>
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


int main()
{
int n;
printf("digite a quantidade de funcionario que voce deseja cadrastar: ");
scanf("%d", &n);
 funcionario v[n];
 int i, j;
 for(i = 0; i < n; i++)
 {
	 ler(&v[i]);
 }
 for(i = 0; i < n; i++)
 {
int imenor = i;
for(j = i + 1; j < n ; j++)
{
	if(v[j].cpf < v[imenor].cpf)
	{
		imenor = j;
	}
}	
 funcionario temp = v[i];
 v[i] = v[imenor];
 v[imenor] = temp;
 }

for(i = 0; i < n; i++)
{
	printf("os dados do funcionrio sao: \n");
	printf("seu cpf e: %d \n", v[i].cpf);
	printf("seu nome e: %s \n", v[i].nome);
	printf("seu idade e: %d \n", v[i].idade);
	printf("seu endereco e: %s \n", v[i].endereco);
	printf("\n");
}





	
	return 0;
}