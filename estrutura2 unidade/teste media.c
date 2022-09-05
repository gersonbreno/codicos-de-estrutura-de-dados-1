#include <stdio.h>
#include <stdlib.h>


int main()
{
float n1, n2, n3, n4, media, rec,res;
printf("digite a nota 1 ");
scanf("%f", &n1);
printf("digite a nota 2 ");
scanf("%f", &n2);
printf("digite a nota 3 ");
scanf("%f", &n3);
printf("digite a nota 4 ");
scanf("%f", &n4);
media = (n1*2 + n2*3 + n3*4+ n4*1)	/ 10;
printf("a media foi %f \n", media);
if (media >= 7){
	printf("aluno aprovado \n");
}
else
{
	printf("aluno em recupecao \n");
	printf("digite a sua nota do exame final \n");
	scanf("%f", &rec);
	
res = media + rec / 2;
if(res >= 5){
	printf("aluno passou \n");
}
else
{
	printf("aluno reprovado!! \n");
}
printf("medi final %f \n", res);	
}
	return 0;
}