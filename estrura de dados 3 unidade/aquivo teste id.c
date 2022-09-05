#include <stdio.h>

struct cliente{
int cep;
char login[40];
};

void ler(struct cliente *a){
	printf("Informe o login do cliente: ");
	scanf("%s", a->login);
	
	printf("Informe o CEP do cliente: ");
	scanf("%d", &a->cep); 
	
	printf("\n");
}

int main(){
	int n;
	printf("Informe o numero de clientes a serem cadastrados: \n");
	scanf("%d", &n);
	// esqueceu o estrut aqui
	struct cliente v[n];
	int i, j;
	for(i = 0; i < n; i++){
		ler(&v[i]);
	}
	
   for (i = 0; i < n; i++) {
		int imenor = i;
        for (j = i + 1; j < n; j++) {
            if (v[j].cep < v[imenor].cep) {
                imenor = j;
            }
        }
        // esqueceu o strut aqui
      struct cliente temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp;
    }
	for(i = 0; i < n; i++){
		printf("%d: %s\n", v[i].cep, v[i].login);
	}   

return 0;
}