#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basicF.h"
#include <string.h>
#include "helpers.h"
#include <stdbool.h>



// graph's basic functions and struct
struct vertice{
  int nameV;
  char* name;
  double weight;
  struct vertice* next;
  struct vertice* back;
}; // WARNING! se mudar aqui mude em todos os .c, onde struct vertice é definido



lista_vertices** create_adjList(int qtdV,int qtdE, double edgeM[][qtdE]) { // por enquanto vai ficar void

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

  //creating adjacency list of each vertex
  int arrows = 0;
  
  
  // (*vetor[0])->next = (struct vertice*)malloc(sizeof(struct vertice)); // começo do loop
  // (*vetor[0])->next->nameV = 333;
  // store = (*vetor[0])->next;
  // store->next = (struct vertice*)malloc(sizeof(struct vertice));
  // store->next->nameV = 222;
  // printf("%i", (*vetor[0])->next->nameV);
  // printf("%i", (*vetor[0])->next->next->nameV);
  struct vertice* store = (struct vertice*)malloc(sizeof(struct vertice));
  for (int i = 0;i<qtdV;i++){ // abrindo espaço para listas
    arrows = arrowNumber((*vetor[i])->nameV, qtdE, edgeM); // inicio loop de vertices
    for (size_t space = 0; space < arrows; space++){
      if (space == 0){
        (*vetor[i])->next = (struct vertice*)malloc(sizeof(struct vertice));
        store = (*vetor[i])->next;
      } else {
        store->next = (struct vertice*)malloc(sizeof(struct vertice));
        store = store->next;
      }

    }
    store->next = NULL;
  }
for (int vertex=0;vertex<qtdV;vertex++){ //quem é cu?
  store = (*vetor[vertex])->next; 
  struct vertice* previous = (struct vertice*)malloc(sizeof(struct vertice));
  previous = (*vetor[vertex]);
    for (int i=0;i<qtdE || store!=NULL ;i++){  //esse 0 será dinâmico
      if (edgeM[0][i] == (*vetor[vertex])->nameV){
        store->back = previous;
        store->nameV = edgeM[1][i];
        putVerticeName(store, store->nameV);

        if (store != NULL){
          int pass=i+1;
          for (int j=0;j==0;pass++){
            if (edgeM[0][pass] == (*vetor[vertex])->nameV){
              store->weight = edgeM[2][pass];
              
              j = 1;
            }
          }
        }
        if (store->next == NULL) store->weight = 0.505303404;
        previous = store;
        store = store->next; 
      }
    }
}

// for (size_t i=0;i<qtdV;i++){  // visualização
//   store = (*vetor[i]); 
//   printf("\n\n=====LISTA DE ADJ DO VÉRTICE %i=====", i+1);
//   for (;store != NULL;){
//     printf("\nDADOS:\n");
//     printf("name: %s\n",store->name);
//     printf("nameV: %i\n",store->nameV);
//     printf("weight: %0.2f\n\n",store->weight);
//     store = store->next;
//   }
// }

free(store);

return vetor;



  
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


void Grafo(lista_vertices** vetor, int qtdV){

  lista_vertices store = (lista_vertices)malloc(sizeof(struct vertice));
  printf("=====LISTAS DE ADJACÊNCIA=====");
  for (size_t i=0;i<qtdV;i++){
    store = (*vetor[i]);
    printf("\n\n*v%i\n",store->nameV);
    while (store!=NULL)
    {
      if (store->next != NULL) printf("[v%i]==>", store->nameV);
      else printf("[v%i]", store->nameV);
      store = store->next;
    }

  }
  printf("\n\n");
}


int Evertice(lista_vertices** vetor, int v, int qtdV){
  
  bool conf = false;
  int count = 0;
  while ( (count != qtdV) && (conf == false) )
  {
    if ((*vetor[count])->nameV == v) conf = true;
    else count++;
  }
  if (conf == true) 1;
  else 0;
  
}

int AddAresta(lista_vertices** vetor, int vi, int vj,int w, int qtdV){
  // will return 1 or 0; success or fail
}