int busca_linear(int n, int* v, int elem) {
    int i;
    for(i = 0; i < n; i++) {
        if(v[i] == elem)
            return i;
    }
    return -1;
}

int main() {
    int vet[8] = {12, 14, 7, 3, 0, 9, 15, 18};
    int e = 20;
    int pos = busca_linear(8, vet, e);
    if(pos == -1)
        printf("O elemento %d nao esta no vetor.\n", e);
    else
        printf("O elemento %d esta na posicao %d.\n", e, pos);
    return 0;
}