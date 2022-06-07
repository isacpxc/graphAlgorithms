#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basicF.h"

// graph's basic functions and struct



struct vertice{
  int nameV;
  char* name;
  double weight;
  struct vertice* next;
  struct vertice* back;
};

lista_vertices* create_adjList(int qtdV,int qtdE, double edgeM[][qtdE]) {
  
  //
}


