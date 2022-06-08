#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basicF.h"
#include <string.h>

// graph's basic functions and struct
struct vertice{
  int nameV;
  char* name;
  double weight;
  struct vertice* next;
  struct vertice* back;
};

size_t lengthInt(int number){
  size_t tam = 0;
  // doublw
  for (int i=0, index = 0;i<1;index++){
    if ( ((double)number/pow(10, index)) >= 1) tam++;
    else i++;
  }

  return tam;
}

void putVerticeName(struct vertice* v,int number){
  size_t tam = lengthInt(number);
  
  char charN[tam];
  v->name = (char*)malloc((tam+2)*sizeof(char));

  sprintf(charN, "%d", number);  // put number on char vector
  

  for (int i=0;i<tam+1;i++){
    if (i == 0) v->name[i] = 'v';
    else v->name[i] = charN[i-1];
  }
  v->name[tam+2] = '\0';

  printf("%s \n", v->name);
  printf("aqui esta o nome: %x ", v->name);

}

void create_adjList(int qtdV,int qtdE, double edgeM[][qtdE]) { // por enquanto vai ficar void

  lista_vertices** vetor = (lista_vertices**)malloc(qtdV*sizeof(lista_vertices*));
  struct vertice* v = (struct vertice*)malloc(sizeof(struct vertice));
    v->back = NULL;
    v->next = NULL;
    v->nameV = edgeM[0][0];
    putVerticeName(v, v->nameV);
    v->weight = edgeM[2][0];


  lista_vertices* elemento = (lista_vertices*)malloc(sizeof(lista_vertices));

  // (**vetor) = v1; -> error segmentation
  vetor[0] = elemento;
  *elemento = v;

  // dava pra fazer:
  //vetor = &elemento;
  //elemento = &v1;

  printf("weight = %0.2f",(**vetor[0]).weight);

  // for (int x = 0; x<qtdV;x++){ //for all vertices
  //   for (int i = 0;i<qtdE;i++){ // search on the matrix
  //     if (x == 0){

  //     }
  //   }
  // }
}


