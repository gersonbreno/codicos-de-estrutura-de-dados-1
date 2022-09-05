#include <stdio.h>
#include <stdlib.h>
int main() {
 int *v = (int *) malloc(4);
 int n, x;
 int i;
 
 printf("Informe um número: \n");
 scanf("%d", &n);
 
 printf("Informe os valores do vetor: \n");
 for(i = 0; i < n; i++){
 scanf("%d", &v[i]);
 }
 
 printf("Informe um valor a ser avaliado: \n");
 scanf("%d", &x);
 
 int maior = 0;
 int igual = 0;
 
 for(i = 0; i < n; i++){
 if(v[i] > x) maior++;
 
 else igual++;
 }
  if(x > 0){
 printf("Os valores maiores ou iguais a %d são: \n", x);
 for(i = 0; i < n; i++){
 if(v[i] > x || v[i] == x)
 printf("%d\n", v[i]);
 }
 }
 }