#include <stdio.h>
#include <string.h>

int main() {
    char entrada[131];
    char substring[131];

    printf("Digite o nome do arquivo: ");
    scanf("%130s", entrada);

    printf("Digite a subcadeia: ");
    scanf("%130s", substring);

    FILE* fp = fopen(entrada, "rt");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }
int n = 0;
    int achou = 0;
    char linha[131];
    while(fgets(linha, 131, fp) != NULL) {
        n++;
        if(strstr(linha, substring) != NULL) {
            achou = 1;
            break;
        }
    }
    if(achou)
        printf("A substring foi encontrada na linha %d.\n", n);
    else
        printf("Substring nao encontrada.\n");

    fclose(fp);
    return 0;
}