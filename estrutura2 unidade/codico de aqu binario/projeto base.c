#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int mat;
	char nome[50];
	float media;
} estudante;

void ler(estudante *e);
void salvarTodos(estudante v[], int n);


void menu() {
	printf("=== escolha uma opcao ===\n");
	printf("1 - cadastrar\n");
	printf("2 - listar\n");
	printf("3 - editar media\n");
	printf("4 - excluir\n");
	printf("5 - tamanho\n");
	printf("6 - media da turma\n");
	printf("7 - editar por nome\n");
	printf("10 - sair\n");
	printf("==========================\n");
}

int tamanho() {
	FILE *f = fopen("./estudantes.reudismam", "rb");
	int i = 0;
	estudante e;
	while (fread(&e, sizeof(estudante), 1, f)) {
		i++;
	}
	fclose(f);
	return i;
}

void cadastrar() {
	//abrir um arquivo escrita
	FILE * f = fopen("./estudantes.reudismam", "ab");
	estudante e;
	ler(&e);
	fwrite(&e, sizeof(estudante), 1, f);
	fclose(f);
	//fechar o arquivo
}

void listar() {
	FILE *f = fopen("./estudantes.reudismam", "rb");
	estudante e;
	while (fread(&e, sizeof(estudante), 1, f)) {
		printf("%d %s %.2f\n", e.mat, e.nome, e.media);
	}
	fclose(f);
}

void editarMedia(int mat, float novaMedia) {
	int n = tamanho();
	FILE *f = fopen("./estudantes.reudismam", "rb");
	estudante v[n];
	fread(v, sizeof(estudante), n, f);
	int i;
	for (i = 0; i < n; i++) {
		if (v[i].mat == mat) {
			v[i].media = novaMedia;
		}
	}
	fclose(f);
	salvarTodos(v, n);
}

void editarNome(char nome[50], char novoNome[50]) {
	int n = tamanho();
	FILE *f = fopen("./estudantes.reudismam", "rb");
	estudante v[n];
	fread(v, sizeof(estudante), n, f);
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(v[i].nome, nome) == 0) {
			strcpy(v[i].nome, novoNome);
		}
	}
	fclose(f);
	salvarTodos(v, n);
}

void excluir(int mat) {
	int n = tamanho();
	FILE *f = fopen("./estudantes.reudismam", "rb");
	estudante v[n];
	estudante listaAtualizada[n];
	fread(v, sizeof(estudante), n, f);
	int cont = 0;
	int i;
	int excluiu = 0;
	for (i = 0; i < n; i++) {
		if (v[i].mat != mat) {
			listaAtualizada[cont] = v[i];
			cont++;
		}
		else {
		   	excluiu = 1;
		}
	}
	if (excluiu == 0) {
		printf("A matricula do estudante nao foi encontrada\n");
	}
	fclose(f);
	salvarTodos(listaAtualizada, cont);
}

float mediaTurma() {
	int n = tamanho();
	FILE *f = fopen("./estudantes.reudismam", "rb");
	float soma = 0;
	estudante v[n];
	fread(v, sizeof(estudante), n, f);
	int i;
	for (i = 0; i < n; i++) {
		soma += v[i].media;
	}
	fclose(f);
	return soma/n;
}

void salvarTodos(estudante v[], int n) {
	FILE * f = fopen("./estudantes.reudismam", "wb");
	fwrite(v, sizeof(estudante), n, f);
	fclose(f);
}

void ler(estudante *e) {
	printf("Informe a matricula: ");
	scanf("%d", &e->mat);
	printf("Informe o nome: ");
	scanf("%s", e->nome);
	printf("Informe a media: ");
	scanf("%f", &e->media);
}

int main() {
	menu();
	int op;
	scanf("%d", &op);
	while (op != 10) {
		if (op == 1) {
			cadastrar();
		}
		if (op == 2) {
			listar();
		}
		if (op == 3) {
			int mat;
			float novaMedia;
			printf("Informe a matricula do estudante: ");
			scanf("%d", &mat);
			printf("Informe a nova media: ");
			scanf("%f", &novaMedia);
			editarMedia(mat, novaMedia);
		}
		if (op == 4) {
			int mat;
			printf("Informe a matriculado do estudante: ");
			scanf("%d", &mat);
			excluir(mat);
		}
		if (op == 5) {
			int n = tamanho();
			printf("A lista contem %d estudantes\n", n);
		}
		if (op == 6) {
			float mediaClasse = mediaTurma();
			printf("Media da turma: %.2f\n", mediaClasse);
		}
		if (op == 7) {
			char nome[50];
			char novoNome[50];
			printf("Informe o nome incorreto: ");
			scanf("%s", nome);
			printf("Informe o nome nome: ");
			scanf("%s", novoNome);
			editarNome(nome, novoNome);
		}
		menu();
		scanf("%d", &op);	
	}
	return 0;
}