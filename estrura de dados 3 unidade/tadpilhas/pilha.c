#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 10

struct pilha {
    int n;
    float vet[N];
};

Pilha* pilha_cria() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    p->n = 0;
    return p;
}

void pilha_push(Pilha* p, float v) {
    if(p->n == N) {
        printf("Capacidade estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

int pilha_vazia(Pilha* p) {
    if(p->n == 0)
        return 1;
    else
        return 0;
}

float pilha_pop(Pilha* p) {
    float v;
    if(pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

void pilha_libera(Pilha* p) {
    free(p);
}
