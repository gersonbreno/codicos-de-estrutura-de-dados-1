#include <stdio.h>

struct ponto {
    float x;
    float y;
};
typedef struct ponto Ponto;

Ponto centro_geometrico(int n, Ponto* v) {
    int i;
    Ponto cg = {0.0f, 0.0f};
    for(i = 0; i < n; i++) {
        cg.x += v[i].x;
        cg.y += v[i].y;
    }
    cg.x /= n;
    cg.y /= n;
    return cg;
}


int main() {
   Ponto vet[3] = {{0.0f, 3.0f}, {4.0, 4.0}, {8.0, 2.0}};
   Ponto centro = centro_geometrico(3, vet);
   printf("centro = (%f, %f)\n", centro.x, centro.y);
   return 0;


}