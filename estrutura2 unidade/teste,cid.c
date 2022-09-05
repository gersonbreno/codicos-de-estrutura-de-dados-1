#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char login[20];
    int senha;
    char email[30];
} cliente;

typedef struct{
    char cidade[25];
    char estado[25];
    int cep;
} endereco_cliente;

typedef struct{
    float p1;
    float p2;
    float p3;
    cliente clit;
    endereco_cliente endereco;
} produtos_cliente;

void ler_cliente(produtos_cliente *pa){
    printf("Digite seu login: ");
    scanf("%s", pa->clit.login);
    
    printf("Digite seu senha: ");
    scanf("%d", &pa->clit.senha);

    printf("Digite seu e-mail: ");
    scanf("%s", pa->clit.email);

    printf("Digite o nome de sua cidade: ");
    scanf("%s", pa->endereco.cidade);
    
    printf("Digite o nome do seu estado: ");
    scanf("%s", pa->endereco.estado);

    printf("Digite seu CEP: ");
    scanf("%d", &pa->endereco.cep);

    printf("Digite o valordo 1º produto: ");
    scanf("%f", &pa->p1);

    printf("Digite o valor do 2º produto: ");
    scanf("%f", &pa->p2);

    printf("Digite o valor do 3ºproduto: ");
    scanf("%f", &pa->p3);
}

void imprimir_cliente(produtos_cliente pa){
    printf("=== Dados do Cliente ===\n");
    
    printf("Login do Usuario: %s\n", pa.clit.login);
    
    printf("Senha do Usuario: %d\n", pa.clit.senha);
    
    printf("E-mail do Usuario: %s\n", pa.clit.email);
    
    printf("Cidade do Usuario: %s\n", pa.endereco.cidade);
    
    printf("Estado do CLiente: %s\n", pa.endereco.estado);
    
    printf("Cep do Usuario: %d\n", pa.endereco.cep);
    
    printf("Valor do 1º Produto: %f\n", pa.p1);
    
    printf("Valor do 2º Produto: %f\n", pa.p2);
    
    printf("Valor do 3º Produto: %f\n", pa.p3);
}

void imprimir_clientPonteiro(produtos_cliente *pa){
    printf("=== Dados do Cliente === \n");
    
    printf("Login do Usuario: %s\n", pa->clit.login);
    
    printf("Senha do Usuario: %d\n", pa->clit.senha);
    
    printf("E-mail do Usuario: %s\n", pa->clit.email);
    
    printf("Cidade do Usuario: %s\n", pa->endereco.cidade);
    
    printf("Estado do CLiente: %s\n", pa->endereco.estado);
    
    printf("Cep do Usuario: %d\n", pa->endereco.cep);
    
    printf("Valor do 1º Produto: %f\n", pa->p1);
    
    printf("Valor do 2º Produto: %f\n", pa->p2);
    
    printf("Valor do 3º Produto: %f\n", pa->p3);
}

void menu(){
    printf("======Escolha umas das opcoes abaixo=============\n");
    printf("1 - Criar novo cadastro \n");
    printf("2 - Ver cadastro sem ponteiro\n");
    printf("3 - Ver cadastro com ponteiro\n");
    printf("4 - Sair\n");
}

int main(){
    int pb;
    produtos_cliente pa;
    do
	{
		
    menu();
    scanf("%d", &pb);

    if (pb == 1){
        ler_cliente(&pa);
    }

    else if (pb == 2){
        imprimir_cliente(pa);
    }

    else if(pb == 3){
        imprimir_clientPonteiro(&pa);
    }

    else if(pb == 4){
        printf("Voce esta saindo agora.");
    }
	} while(pb != 4);
return 0;
}
