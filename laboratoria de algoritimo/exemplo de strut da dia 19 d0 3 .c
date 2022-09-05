#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[21];
    float nota;
};
typedef struct aluno Aluno;

void captura(int n, Aluno* vet) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Aluno [%d] - Digite um nome: ", i);
        scanf(" %20[^\n]", vet[i].nome);
        printf("Aluno [%d] - Digite uma nota: ", i);
        scanf("%f", &vet[i].nota);
    }
}


void imprime(int n, Aluno* vet) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%s\t%f\n", vet[i].nome,
void imprime(int n, Aluno* vet) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%s\t%f\n", vet[i].nome, vet[i].nota);
    }
}

int main() {
    Aluno alunos[3];
    captura(3, alunos);
    imprime(3, alunos);
    return 0;

}