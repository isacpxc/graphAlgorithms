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

  // printf("%s \n", v->name);
  // printf("aqui esta o nome: %x ", v->name);

}

int verifyPosition(int current, int ok[], int tam){
  int check = 0;
  for (int i=0;i<tam;i++){
    if (ok[i] == current) return 1;
  }
  return 0;
}

void create_adjList(int qtdV,int qtdE, double edgeM[][qtdE]) { // por enquanto vai ficar void

  /* 
  ESTUDO DE PONTEIROS

  struct vertice** p = (struct vertice**)malloc(sizeof(struct vertice*));
  struct vertice* q = (struct vertice*)malloc(sizeof(struct vertice));
  struct vertice exemplo;

  *q=exemplo;
  *p = q;
  // nesse eu digo, quando acessar o que há em p, vai cair em q, mas p guarda um endereço que não é o que o malloc de q produziu,
  // mas funciona perfeitamene para caminhar
  printf("endereço = %i\n", p);
  printf("endereço = %i\n", *p);
  printf("endereço = %i\n", &q);
  printf("endereço = %i\n", q);
  printf("endereço = %x\n\n", *q);

  p = &q;
  //nesse eu digo, p vai receber o endereço de q, e quando acessado, vai cair lá
  printf("endereço = %i\n", p);
  printf("endereço = %i\n", *p);
  printf("endereço = %i\n", &q);
  printf("endereço = %i\n", q); */




  lista_vertices** vetor = (lista_vertices**)malloc(qtdV*sizeof(lista_vertices*));

  // printf("vertice: %d\n", (*vetor[1])->nameV);
  

  // v[0] ja esta na primeira posição, agora vamos preencher as posições restantes, iniciando uma lista para cada vértice
  // a ideia é criar um vetor, que armazena o numero do vertice que ja foi inserido na lista
  // ex vec = [1,-1,-1,-1,-1,-1,-1] o grafo tem 7 vertices, o primeiro é o 1
  // aqui não vamos montar a lista ainda, apenas colocar o vertice no início da lista
  int ok[qtdV];
  for (int i=0;i<qtdV;i++) ok[i] = -1;
  
  for (int i=0,indexOk=0;i<qtdE;i++){
    if (verifyPosition(edgeM[0][i], ok, qtdV) == 0){ // if verifyPosition return 0, this vertice don't belong yet
      struct vertice* v_current = (struct vertice*)malloc(sizeof(struct vertice));
      v_current->back = NULL;
      v_current->next = NULL;
      v_current->nameV = edgeM[0][i];
      putVerticeName(v_current, v_current->nameV);
      v_current->weight = edgeM[2][i];
      lista_vertices* elemento_current = (lista_vertices*)malloc(sizeof(lista_vertices));
      *elemento_current = v_current;
      
      vetor[indexOk] = elemento_current;
      ok[indexOk] = edgeM[0][i];
      indexOk++;
      
    }
  
  

  } //end for
  // agora a lista esta iniciada, cada vertice inserido na primeira posição
  // for (int i=0;i<qtdV;i++) {
  //   printf("vertice: %s\n", (*vetor[i])->name);
  //   printf("vertice numero: %d\n", (*vetor[i])->nameV);
  //   printf("vertice peso: %0.2f\n\n", (*vetor[i])->weight);
  // } verificação apenas

  
  //            -----vetor------
  //            |  |  |  |  |  |
  //            [] [] [] [] [] [] 
  //            cada posição recebe um ponteiro de ponteiro
  //            que por sua vez aponta para o cara que aponta para o struct

  // dava pra fazer: ??????
  // vetor = &elemento;
  // elemento = &v;
  // printf("endereço = %x\n", vetor);
  // printf("endereço = %x\n", *vetor);
  // printf("endereço = %x\n", &elemento);
  // printf("endereço = %x\n", elemento);
  // printf("\n u");
  // printf("\n u");

}


