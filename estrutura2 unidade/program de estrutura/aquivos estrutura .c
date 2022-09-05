#include <stdio.h>


int main(int argc, char** argv)
{
 int n_linha = 0;
 int c;
  FILE* fp = fopen("teste.txt","rt");
  if (fp == NULL){
	  printf("erro na abertura");
        return 1;
  }
  while((c = fgetc(fp)) != EOF){
	  if(c == '\n')
	 n_linha++;
  }
  fclose(fp);
  printf("o numero de linha = %d \n", n_linha);
	return 0;
}