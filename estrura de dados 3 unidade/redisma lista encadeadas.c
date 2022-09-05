#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int mat;
  char nome[50];
  float nota;
} estudante;

struct NO {
  estudante data;
  struct NO* prox;
};

typedef struct NO No;

typedef struct {
  No *inicio;
} Lista;

void menu() {
  printf("== Escolha uma opcao ==\n");
  printf("1 - adicionar fim\n");
  printf("2 - mostrar\n");
  printf("3 - remover fim\n");
  printf("4 - pesquisar\n");
  printf("10 - sair\n");
  printf("========================\n");
}

void ler(estudante *e) {
  printf("Matricula: ");
  scanf("%d", &e->mat);
  printf("Nome: ");
  scanf("%s", e->nome);
  printf("Media: ");
  scanf("%f", &e->nota);
}

No* criaNo(estudante e) {
  No* novo = (No*) malloc(sizeof(No));
  novo->data = e;
  novo->prox = NULL;
  return novo;
}

void mostrar(Lista lista) {
  No* pi;
  for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
    printf("%s: %.2f\n", pi->data.nome, pi->data.nota);
  }
}

void inserir_fim(Lista *lista, estudante e) {
  No* novo = criaNo(e);
  if (lista->inicio == NULL) {
    lista->inicio = novo;
  }
  else {
    No* pi;
    for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
    }
    pi->prox = novo;
  }
}

No* pesquisar(Lista lista, int mat) {
  No * pi;
  for (pi = lista.inicio; pi != NULL && pi->data.mat != mat; pi = pi->prox) {
  }
  return pi;
}

void remover_fim(Lista *lista) {
  if (lista->inicio == NULL) {
    printf("A lista estah vazia\n");
  }
  else {
    No *pa = NULL;
    No *pi;
    for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox) {
      pa = pi;
    }
    if (pa == NULL) {
      lista->inicio = NULL;
    }
    else {
      pa->prox = NULL;
      free(pi);
    }
  }
}

int main(void) {
  Lista lista;
  lista.inicio = NULL;
  menu();
  int op;
  scanf("%d", &op);
  while (op != 10) {
    if (op == 1) {
      estudante e;
      ler(&e);
      inserir_fim(&lista, e);
    }
    else if (op == 2) {
      mostrar(lista);
    }
    else if (op == 3) {
      remover_fim(&lista);
    }
    else if (op == 4) {
      int mat;
      printf("Informe a matricula: ");
      scanf("%d", &mat);
      No* r = pesquisar(lista, mat);
      if (r == NULL) {
        printf("Estudante nao encontrado\n");
      }
      else {
        printf("%s: %.2f\n", r->data.nome, r->data.nota);
      }
    }
    menu();
    scanf("%d", &op);
  }
  return 0;
}