#include <stdio.h>

int main() {
    int n_linhas = 0;
    int c;

    FILE* fp = fopen("disciplinas.txt", "rt");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    while((c = fgetc(fp)) != EOF) {
        if(c == '\n')
            n_linhas++;
    }
    fclose(fp);
    printf("Numero de linhas = %d\n", n_linhas);
    return 0;
}