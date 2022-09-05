#include <stdio.h>
#include <stdlib.h>
struct aluno
{
	int mat;
	char nome[20];
	float nota[3];
};
	void menu()
	{
		printf("escolha uma opçao: \n");
		printf("1 - pequisa alunos: \n");
		printf("2 sair \n");
	}
	void pequisa(struct aluno v[], int n, int mat){
		int i;
		for(i = 0; i < n; i++){
			if(v[i].mat == mat){
			float media = (v[i].nota[0] + v[i].nota[1] + v[i].nota[2]) \3;
			printf("%s: %.2f\n", v[i].nome, media);
			}
		}
	}



int main()
{
int n;
printf("informe a quantidade de estudantes: ");
  scanf("%i", &n);
  struct aluno alunos[n];
 int i;
 for(i = 0; i < n; i++)
 {
	 scanf("%i %s %f %f, %f", &v[i].mat, v[i].nome, v[i].nota[0], v[i].nota[1], v[i].nota[2]);
 }
 int op;
 menu()


	return 0;
}
