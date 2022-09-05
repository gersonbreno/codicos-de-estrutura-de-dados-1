#include <stdio.h>

struct estudante {
  int mat;
  char nome[6];
  float media;
};

//5! = 5 * 4 * 3 * 2 * 1 = 120
//5! = 5 * 4!
int fatorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * fatorial(n - 1);
    }
}

void menu() {
    printf("== escolha uma opcao ==\n");
    printf("1 - listar\n");
    printf("2 - busca linear\n");
    printf("3 - busca binaria\n");
    printf("4 - fatorial\n");
    printf("5 - busca binaria recursiva\n");
    printf("10 - sair\n");
    printf("========================\n");
}

int buscalinear(struct estudante v[], int n, int mat) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i].mat == mat) {
            return i;
        }
    }
    return -1;
}

int buscabinaria(struct estudante v[], int n, int mat) {
    int i = 0;
    int f = n - 1;
    while (i <= f) {
        int m = (i + f)/2;
        if (v[m].mat == mat) {//acertou
            return m;
        }
        else if (v[m].mat < mat) { //para a direita
            i = m + 1;
        }
        else { //para a esquerda
            f = m - 1;
        }
    }
    return -1;
}

int buscabinariarecursiva(struct estudante v[], int i, int f, int mat) {
    if (i <= f) {
        int m = (i + f)/2;
        if (v[m].mat == mat) {//acertou
            return m;
        }
        else if (v[m].mat < mat) { //para a direita
            return buscabinariarecursiva(v, m + 1, f, mat);
        }
        else { //para a esquerda
            return buscabinariarecursiva(v, i, m - 1, mat);
        }
    }
    else {
        return -1;
    }
}

void listar(struct estudante v[], int n) {
    int i;
    printf("Usuarios cadastrados no sistema:\n");
    for (i = 0; i < n; i++) {
        printf("%d - %s: %.2f\n", v[i].mat, v[i].nome, v[i].media);
    }
}

void ler(struct estudante *e) {
    printf("Matricula: ");
    scanf("%d", &e->mat);
    printf("Nome: ");
    scanf("%s", e->nome);
    printf("Media: ");
    scanf("%f", &e->media);
}

int main() {
    //!showMemory(start=65520)
    int n;
    printf("Informe o numero de estudantes:\n");
    scanf("%d", &n);
    struct estudante v[n];
    int i;
    for (i = 0; i < n; i++) {
        ler(&v[i]);
    }
    menu();
    int op;
    scanf("%d", &op);
    while (op != 10) {
        if (op == 1) {
            listar(v, n);
        }
        if (op == 2) {
            int mat;
            printf("Informe a matricula: ");
            scanf("%d", &mat);
            int index = buscalinear(v, n, mat);
            if (index == -1) {
                printf("Matricula nao encontra\n");
            }
            else {
                printf("%d - %s: %.2f\n", v[index].mat, v[index].nome, v[index].media);
            }
        }
        
        if (op == 3) {
            int mat;
            printf("Informe a matricula: ");
            scanf("%d", &mat);
            int index = buscabinaria(v, n, mat);
            if (index == -1) {
                printf("Matricula nao encontra\n");
            }
            else {
                printf("%d - %s: %.2f\n", v[index].mat, v[index].nome, v[index].media);
            }
        }
        
        if (op == 4) {
            int fat;
            printf("Informe um numero: ");
            scanf("%d", &fat);
            int r = fatorial(fat);
            printf("Fatorial: %d\n", r);
        }
        
        if (op == 5) {
            int mat;
            printf("Informe a matricula: ");
            scanf("%d", &mat);
            int index = buscabinariarecursiva(v, 0, n - 1, mat);
            if (index == -1) {
                printf("Matricula nao encontra\n");
            }
            else {
                printf("%d - %s: %.2f\n", v[index].mat, v[index].nome, v[index].media);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!!!\n");
}