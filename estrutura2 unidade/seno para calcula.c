#include <stdio.h>
#include <math.h>
#define PI 3.1416
int main(int argc, char** argv)
{
	double angulo, param , result;
	
	printf("digite o angulo seno que voce deseja calcula: ");
	scanf("%lf", &angulo);
	param = angulo;
	result = sin(param*PI/180);
	printf("seno do angulo %.2f e o resultado e %.3f \n", param, result);
	return 0;
}