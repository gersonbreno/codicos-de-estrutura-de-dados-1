int vetor[5] = {1, 2, 3, 4, 5};
    float vetor2[5] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    char vetor3[5] = {'a', 'b', 'c', 'd', 'e'};
    Ponto vetor4[2] = {{0.0f, 0.0f}, {3.4f, 5.0f}};
    vetor4[1].x = 2.0f;
    vetor4[1].y = 3.0f;
    
    Ponto p = {2.0f, 3.0f};
    Ponto p2;
    p2.x = 5.0f;
    p2.y = 6.0f;
    Ponto* pp = &p2;
    printf("usando p2 (%f, %f)\n", p2.x, p2.y);

    pp->x = 0.0f;
    pp->y = 0.0f;
    printf("usando pp (%f, %f)\n", pp->x, pp->y);