#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[6];
    float media;
} estudante;

void ler(estudante *pe) {
    printf("Nome: ");
    scanf("%s", pe->nome);
    printf("Media: ");
    scanf("%f", &pe->media);
}

void ordenarSelecao(int v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int i_menor = i;
        for (j = i - 1; j < n; j++) {
            if (v[i_menor] > v[j]) {
                i_menor = j;
            }
        }
        int temp = v[i];
        v[i] = v[i_menor];
        v[i_menor] = temp;
    }
}

void ordenarInsercao(int v[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int x = v[i];
        for (j = i - 1; j >= 0 && x < v[j]; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}


void ordenarBolha(int v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void ordenarPorMedia(estudante v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j].media > v[j + 1].media) {
                estudante temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void ordenarPorNome(estudante v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(v[j].nome, v[j + 1].nome) > 0)  {
                estudante temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


int main() {
    //! showMemory(start=65520)
    int n;
    printf("Informe a quantidade de estudantes:");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for (i = 0; i < n; i++) {
        ler(&v[i]);
    }
    //ordenarSelecao(v, 10);
    //ordenarInsercao(v, 10);
    //ordenarPorMedia(v, n);
    ordenarPorNome(v, n);
    for (i = 0; i < n; i++) {
      printf("%s: %.2f\n", v[i].nome, v[i].media);  
    }
    return 0;
}