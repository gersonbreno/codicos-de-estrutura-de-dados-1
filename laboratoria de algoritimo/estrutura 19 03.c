#include <stdio.h>
#include <stdlib.h>
struct aluno
{
   char nome[20];
   float nota;	
};
typedef struct aluno Aluno;

void imprime(int n, Aluno* vet){
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s \ t%\f\n",vet[i].nome, vet[i].nome, vet[i].nota);
		
	}
}
int main()
{
Aluno alunos[3] = {{"ana", 9.0f}};

	
	
	
	
	return 0;
}