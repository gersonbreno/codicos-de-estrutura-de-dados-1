#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno
{
        int matricula;
        char nome[41];
        char telefone[15];
        char endereco[51];
};
typedef struct aluno Aluno;

//Passar um vetor para uma função é passar o endereço do primeiro elemento.

void inicializar (int n, Aluno** v)//vetor de ponteiros para estruturas.
{
        int i;
        for (i = 0; i < n; i++)
                v[i] = NULL;
}

void insere (int n, Aluno** v, int i, int mat, char* nome, char* tel, char* end)//i é a posiçã no vetor onde irá inserir o aluno.
{
        if (i < 0 || i >= n)
        {
                printf("Indice invalido. \n");
                exit(1);
        }
        if (v[i] == NULL)
        {
                v[i] = (Aluno*)malloc(sizeof(Aluno));
        }
        v[i]->matricula = mat;
        strcpy(v[i]->nome, nome);
        strcpy(v[i]->telefone, tel);
        strcpy(v[i]->endereco, end);
}

void retira (int n, Aluno** v, int i) // i = Posição do vetor onde quer remover o aluno
{
        if (i < 0 || i >= n)
        {
                printf("Indice invalido. \n");
                exit(1);
        }
        if (v[i] != NULL)
        {
                free(v[i]);//Libera o aluno.
                v[i] = NULL;//V[i] agora está vazio.
        }
}

void imprime (int n, Aluno** v, int i)
{
        if (i < 0 || i >= n)
        {
                printf("Indice invalido. \n");
                exit(1);
        }
        if (v[i] != NULL)
        {
                printf("Matricula: %d\n", v[i]->matricula);
                printf("Nome: %s\n", v[i]->nome);
                printf("Endereco: %s\n", v[i]->endereco);
                printf("Telefone: %s\n", v[i]->telefone);
        }
}

void imprime_todos (int n, Aluno** v)
{
        int i;
        for (i = 0; i < n; i++)
                imprime(n, v, i);
}

int main ()
{
        Aluno* vet[10];
        inicializar(10, vet);
        insere(10, vet, 0, 123, "Ana", "84 98888-8888", "Avenida Brasil");
        insere(10, vet, 1, 121, "Paula", "84 98888-8898", "Avenida Brasil");
        insere(10, vet, 2, 122, "Maria", "84 98888-8878", "Avenida Brasil");
        insere(10, vet, 3, 120, "Júlia", "84 98888-8088", "Avenida Brasil");
        insere(10, vet, 4, 120, "Sofia", "84 98888-8088", "Avenida Brasil");
        imprime(10, vet, 2);
        retira(10, vet, 2);
        imprime_todos(10, vet);
        return 0;
}