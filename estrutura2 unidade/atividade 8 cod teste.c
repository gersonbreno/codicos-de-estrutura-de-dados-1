#include<stdio.h>

 struct cliente{
int cep;
char login[40];
char email[40];
char endereco[40];
};

void menu(){
printf("=====Escolha uma das opcoes a seguir===========: \n");
printf("1 - Lista de Clientes. \n");
printf("2 - Buscar cliente. \n");
printf("3 - Sair. \n");
printf("\n");
}

int buscalinear(struct cliente v[], int n, int cep){
    int i;
    for(i = 0; i < n; i++){
        if (v[i].cep == cep){
            return i;
        }
    }
    return -1;
}

void lista(struct cliente v[], int n){
    int i;
    printf("Clientes cadastrados no momento: \n");
    for (i=0; i<n; i++){
    		printf("seu cep: %d\n", v[i].cep);
    	   	printf("seu login: %s \n", v[i].login);
        	printf("seu email: %s \n", v[i].email);
        	printf("seu endereco: %s \n", v[i].endereco);
        	printf("\n");
      
    }
}

void ler(struct cliente *a){
	 printf("Informe o CEP do usuario: ");
    scanf("%d", &a->cep);
    printf("Informe o login do usuario: ");
    scanf("%s", a->login);
    
    printf("Informe o e-mail do usuario: ");
    scanf("%s", a->email);
    
    printf("Informe o endereco do usuario: ");
    scanf("%s", a->endereco);
    printf("\n");
}

int main(){
    int n;
    printf("Informe o numro de clientes a serem cadrastados: ");
    scanf("%d", &n);
    
    struct cliente v[n];
    int i;
    int op;
    for(i=0; i<n; i++){
        ler(&v[i]);
    }
		

    do
	{
    menu();
    scanf("%d", &op);
  
        if(op==1){
            lista(v, n);
        }
        
        if (op == 2){
        int cep;
        printf("Informe o cep para a busca: \n");
        scanf("%d", &cep);
            
        int index = buscalinear(v, n, cep);
        if(index == -1){
        	printf("\n");
            printf("Login nao encontrado tente novamente. \n");
            printf("\n");
        }
        else{
        	printf("\n");
        	printf("=======aqui esta resultado da sua busca ==================\n");
        	printf("seu CEP: %d\n", v[index].cep);
        	printf("seu login: %s \n", v[index].login);
        	printf("seu email: %s \n", v[index].email);
        	printf("seu endereco: %s \n", v[index].endereco);
        	printf("\n");
           
        }
    }
    
  
    
    if(op==3){
        printf("Programa finalizado!!! \n");
 }
 	} while(op != 3);

return 0;
}