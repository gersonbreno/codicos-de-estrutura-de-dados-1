#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char login[40];
	char email[40];
	char endereco[40];
} cliente;

int main(){
	int n;
	printf("Digite o numeros de clientes: ");
	scanf("%d", &n);
	cliente v[n];
	int i;
	for(i = 0; i < n; i++){
        printf("Digite o login do cliente: ");
	        scanf("%s", v[i].login);	
	    printf("Digite a e-mail do cliente: ");
	        scanf("%s", v[i].email);
	    printf("Digite o endereço do cliente: ");
	        scanf("%s", v[i].endereco);
	}
	
	FILE *fd = fopen("./cliente.txt", "a");
	for(i = 0; i < n; i++){
		fprintf(fd,"%s \n", v[i].login);
		fprintf(fd,"%s \n", v[i].email);
		fprintf(fd,"%s \n", v[i].endereco);
		printf("\n");
	} 
	fclose(fd);
	
	FILE *fa = fopen("./cliente.txt", "r");
	cliente e;
	while (fscanf(fd, "%s %s %s",  e.login, e.email, e.endereco) != EOF){
		printf("Login do cliente: %s \n", e.login);
		printf("E-mail do cliente: %s \n", e.email);
		printf("Endereço do cliente: %s\n", e.endereco);
		printf("\n");
	}
	fclose(fa);
	
    return 0;
}