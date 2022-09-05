#include <stdio.h>

typedef struct 
{
	char nome[100];
	int matricula;
	int idade;
	int telefone;
	
}aluno;
void pesquisar(aluno *v, int n, int codSala) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i].matricula == codSala) {
            if (v[i].matricula == 0) {
                printf("%s", v[i].nome);
            }
            else {
                printf("%s: LAB\n", v[i].nome);
            }
        }
    }
}
void menu(){
	printf("escolha as seguuintes opcao \n");
	printf("1 - para informa os dados do aluno\n");
	printf("2 - para pesquisa e mostra os dados do aluno\n");
	printf("3 - para sair");
}
int main()
{
	int codSala;
	int n;
	int i;
	printf("digite a quantidade de aluno na sua sala: ");
	scanf("%d", &n);
	aluno v[n];
	int op;


	menu();
	scanf("%d", &op);
	do
	{
		

	switch(op)
	{
	case 1:
			for(i = 0; i < n; i++)
	{
		printf("digite a matricula do aluno: ");
		scanf("%d", &v[i].matricula);
		printf("digite o nome do aluno: ");
		scanf("%s", v[i].nome);
		printf("digite a idade do aluno: ");
		scanf("%d", &v[i].idade);
		printf("digite o telefone do aluno: ");
		scanf("%d", &v[i].telefone);
	} 
		break;
	case 2:
	pesquisar(v, n, codSala);
	break;
case 3:
	printf("saindo \n");
	default:
		break;
	}
	} while(op != 3);
	return 0;
}