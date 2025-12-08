#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//min heap

void subirmin(int h[], int i) {
    while (i > 0 && h[i] < h[(i - 1) / 2]) {
        troca(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void descermin(int h[], int tam, int i) {
    int menor = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < tam && h[esq] < h[menor]) menor = esq;
    if (dir < tam && h[dir] < h[menor]) menor = dir;

    if (menor != i) {
        troca(&h[i], &h[menor]);
        descermin(h, tam, menor);
    }
}

void inserirmin(int h[], int *tam, int valor) {
    h[*tam] = valor;
    (*tam)++;
    subirmin(h, *tam - 1);
}

int removermin(int h[], int *tam) {
    int raiz = h[0];
    h[0] = h[*tam - 1];
    (*tam)--;
    descermin(h, *tam, 0);
    return raiz;
}

//max-heap

void subirmax(int h[], int i) {
    while (i > 0 && h[i] > h[(i - 1) / 2]) {
        troca(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void descermax(int h[], int tam, int i) {
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < tam && h[esq] > h[maior]) maior = esq;
    if (dir < tam && h[dir] > h[maior]) maior = dir;

    if (maior != i) {
        troca(&h[i], &h[maior]);
        descermax(h, tam, maior);
    }
}

void inserirmax(int h[], int *tam, int valor) {
    h[*tam] = valor;
    (*tam)++;
    subirmax(h, *tam - 1);
}

int removerMax(int h[], int *tam) {
    int raiz = h[0];
    h[0] = h[*tam - 1];
    (*tam)--;
    descermax(h, *tam, 0);
    return raiz;
}

//main

void imprimir(int h[], int tam) {
    for(int i = 0; i < tam; i++)
        printf("%d ", h[i]);
    printf("\n");
}

int main() {
    int min[50], max[50];
    int tamMin = 0, tamMax = 0;

    inserirmin(min, &tamMin, 10);
    inserirmin(min, &tamMin, 4);
    inserirmin(min, &tamMin, 15);
    inserirmin(min, &tamMin, 1);

    printf("Min-Heap: ");
    imprimir(min, tamMin);

    printf("Remove Min: %d\n", removermin(min, &tamMin));
    printf("Min depois: ");
    imprimir(min, tamMin);

    inserirmax(max, &tamMax, 10);
    inserirmax(max, &tamMax, 4);
    inserirmax(max, &tamMax, 15);
    inserirmax(max, &tamMax, 1);

    printf("\nMax-Heap: ");
    imprimir(max, tamMax);

    printf("Remove Max: %d\n", removerMax(max, &tamMax));
    printf("Max depois: ");
    imprimir(max, tamMax);

    return 0;
}