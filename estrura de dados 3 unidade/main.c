#include <stdio.h>
#include <stdlib.h>
#include "tadpilhas/pilha.h"

int main()
{
    Pilha* pilha = pilha_cria();
    pilha_push(pilha, 3.5f);
    pilha_push(pilha, 2.5f);
    pilha_push(pilha, 4.5f);
    pilha_push(pilha, 5.5f);
    float e;
    while(!pilha_vazia(pilha)) {
        e = pilha_pop(pilha);
        printf("%f\n", e);
    }
    pilha_libera(pilha);
    return 0;
}
