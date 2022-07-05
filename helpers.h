#include <stdio.h>
#include <stdlib.h>

size_t lengthInt(int);
void putVerticeName(struct vertice*,int);
int verifyPosition(int, int[], int);
int arrowNumber(int,int, double (*)[]);
void putVerticeIndex(int* vet);
int verifyDiconVertex(int qtdE, int current, double (*)[]);
void setVisited(lista_vertices** vetor, int qtdV);
void putVerticeName(struct vertice*,int);