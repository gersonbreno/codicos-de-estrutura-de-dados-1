#include <stdio.h>

int main() {
   
    int a;
    int b;
    int prod;
    int *pa = &a;
    int *pb = &b;
    int *pprod = &prod;
    printf("Informe dois numeros\n");
    scanf("%d %d", pa, pb);
    
    *pprod = (*pa) * (*pb);
    
    printf("%d\n", *pprod);
    
    
    return 0;
}