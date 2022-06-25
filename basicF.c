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
  int visited;
  struct vertice* next;
  struct vertice* back;
  int neighbours;
  struct vertice** neighboursLink;
  double* weightLink ;
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
  int*  arrVOinddex= (int*)malloc(qtdV*sizeof(int));
  putVerticeIndex(arrVOinddex); // array with all vertices indexes| CAUSE: to create adj list to disconnected vertices
  //   for (size_t i = 0; i < qtdV; i++)
  // {
  //   printf("%i ",arrVOinddex[i]);
  // }
  
  // v[0] ja esta na primeira posição, agora vamos preencher as posições restantes, iniciando uma lista para cada vértice
  // a ideia é criar um vetor, que armazena o numero do vertice que ja foi inserido na lista
  // ex vec = [1,-1,-1,-1,-1,-1,-1] o grafo tem 7 vertices, o primeiro é o 1
  // aqui não vamos montar a lista ainda, apenas colocar o vertice no início da lista
  int ok[qtdV];
  for (int i=0;i<qtdV;i++) ok[i] = -1;
  int indexOk=0;
  for (int i=0;i<qtdE;i++){
    if (verifyPosition(edgeM[0][i], ok, qtdV) == 0){ // if verifyPosition return 0, this vertice don't belong yet
      struct vertice* v_current = (struct vertice*)malloc(sizeof(struct vertice));
      v_current->back = NULL;
      v_current->next = NULL;
      v_current->nameV = edgeM[0][i];
      putVerticeName(v_current, v_current->nameV);
      v_current->weight = edgeM[2][i];
      v_current->visited = -1;
      v_current->neighbours = 0;
      lista_vertices* elemento_current = (lista_vertices*)malloc(sizeof(lista_vertices));
      *elemento_current = v_current;
      
      vetor[indexOk] = elemento_current;
      ok[indexOk] = edgeM[0][i];
      indexOk++;
      
    }
  

  } //end for
  
    for (int i=0;i<qtdE;i++){
      
      if (verifyPosition(edgeM[1][i], ok, qtdV) == 0){ // if verifyPosition return 0, this vertice don't belong yet
        printf("%f \n", edgeM[1][i]);
        struct vertice* v_current = (struct vertice*)malloc(sizeof(struct vertice));
        v_current->back = NULL;
        v_current->next = NULL;
        v_current->nameV = edgeM[1][i];
        putVerticeName(v_current, v_current->nameV);
        v_current->weight = 0.505303404;
        v_current->visited = -1;
        v_current->neighbours = 0;
        lista_vertices* elemento_current = (lista_vertices*)malloc(sizeof(lista_vertices));
        *elemento_current = v_current;
        ok[indexOk] = edgeM[1][i];
        vetor[indexOk] = elemento_current;
        indexOk++;
        
      }
  

  } //end for

  for (int index=0;index<qtdV;index++){
    if (verifyDiconVertex(qtdE, arrVOinddex[index], edgeM) > -1){
      struct vertice* v_current = (struct vertice*)malloc(sizeof(struct vertice));
      v_current->back = NULL;
      v_current->next = NULL;
      v_current->nameV = arrVOinddex[index];
      v_current->visited = -1;
      v_current->neighbours = 0;
      putVerticeName(v_current, v_current->nameV);
      v_current->weight = 0.505303404;
      lista_vertices* elemento_current = (lista_vertices*)malloc(sizeof(lista_vertices));
      *elemento_current = v_current;
      
      vetor[indexOk] = elemento_current;
      indexOk++;
    }
  }
  // agora a lista esta iniciada, cada vertice inserido na primeira posição
  // for (int i=0;i<qtdV;i++) printf("%i", (*vetor[i])->nameV);
  //creating adjacency list of each vertex
  int arrows = 0;
  
  // (*vetor[0])->next = (struct vertice*)malloc(sizeof(struct vertice)); // começo do loop
  // (*vetor[0])->next->nameV = 333;
  // store = (*vetor[0])->next;
  // store->next = (struct vertice*)malloc(sizeof(struct vertice));
  // store->next->nameV = 222;
  // for (int i=0;i<qtdV;i++) printf("%i ", (*vetor[i])->nameV);
  // printf("%i", (*vetor[0])->next->next->nameV);
  struct vertice* store = (struct vertice*)malloc(sizeof(struct vertice));
  for (int i = 0;i<qtdV;i++){ // abrindo espaço para listas
    arrows = arrowNumber((*vetor[i])->nameV, qtdE, edgeM); // inicio loop de vertices
    (*vetor[i])->neighboursLink = (struct vertice**)malloc(arrows*sizeof(struct vertice*));
    for (size_t space = 0; space < arrows; space++){
      (*vetor[i])->neighbours++;
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
for (int vertex=0;vertex<qtdV;vertex++){ 
  store = (*vetor[vertex])->next; 
  struct vertice* previous = (struct vertice*)malloc(sizeof(struct vertice));
  previous = (*vetor[vertex]);
    for (int i=0;i<qtdE || store!=NULL ;i++){  //esse 0 será dinâmico
      if (edgeM[0][i] == (*vetor[vertex])->nameV){
        store->back = previous;
        store->nameV = edgeM[1][i];
        putVerticeName(store, store->nameV);
        // store->visited = -1;
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

for (int index=0;index<qtdV;index++){ //neighboursLink to NULL
  struct vertice* store = (struct vertice*)malloc(sizeof(struct vertice));
  store = (*vetor[index]);
  if ((*vetor[index])->neighbours == 0) (*vetor[index])->neighboursLink[0] = NULL;
  for (int i=0;i<(*vetor[index])->neighbours;i++){
    store = store->next;
    int j=0;
    while (store->nameV != (*vetor[j])->nameV) {
      j++;
    }
    (*vetor[index])->neighboursLink[i] = NULL;

  }
}

for (int index=0;index<qtdV;index++){ // neighboursLink TO NEIGHBOURS
  struct vertice* store = (struct vertice*)malloc(sizeof(struct vertice));
  store = (*vetor[index]);
  for (int i=0;i<(*vetor[index])->neighbours;i++){
    store = store->next;
    int j=0;
    while (store->nameV != (*vetor[j])->nameV) {
      j++;
    }
    (*vetor[index])->neighboursLink[i] = (*vetor[j]);
    // printf("\nname: %i",(*vetor[index])->neighboursLink[i]->nameV);

  }

}

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
    printf("\n\n*v%i - n = %i\n",store->nameV,(*vetor[i])->neighbours);
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
  
  return conf;
  
}



int ExisteAresta(lista_vertices** vetor, int vi, int vj,double w, int qtdV){
  // -1 = não existe um dos vértices aresta vi->vj
  // 0 = os vértices existem, mas não a aresta
  // 1 = existe a aresta vi->vj, mas não com o peso w
  // 2 = existe a aresta vi->vj com peso
  if (Evertice(vetor, vi, qtdV) == 0 || Evertice(vetor, vj, qtdV) == 0) return -1;
  lista_vertices store = (lista_vertices)malloc(sizeof(struct vertice));
  int i= -1;
  int conf = 0;

  do{
    i++;
    store = (*vetor[i]);
  }while((*vetor[i])->nameV != vi);
  
  while (store->next!=NULL)
  {
    if (store->next->nameV == vj) {
      conf = 1;
      if (store->weight == w) conf = 2;
      return conf;
    } else store = store->next;
  }
  
  return conf;
}

int Eadj(lista_vertices** vetor, int vi, int vj, int qtdV){
  int conf = ExisteAresta(vetor, vi, vj, 0, qtdV);
  if ( conf > 0) return 1;
  return 0;
}

int AddAresta(lista_vertices** vetor, int vi, int vj,int w, int qtdV){
  if(Evertice(vetor,vi,qtdV) == 0 || Evertice(vetor, vj, qtdV) == 0) return -1;
  if(Evertice(vetor,vi,qtdV) == 1 && Evertice(vetor, vj, qtdV) == 1) {
    if (ExisteAresta(vetor, vi, vj, 0, qtdV) != 0) return 0;
  }
  
  lista_vertices store = (lista_vertices)malloc(sizeof(struct vertice));
  lista_vertices previous = (lista_vertices)malloc(sizeof(struct vertice));
  int i= -1;
  int conf = 0;

  do{
    i++;
    store = (*vetor[i]);
    previous = (*vetor[i]);
  }while((*vetor[i])->nameV != vi);
  
  (*vetor[i])->neighbours++; // update number of neighbours
  lista_vertices* NewlinkNeighbours = (lista_vertices*)malloc((*vetor[i])->neighbours*sizeof(lista_vertices)); 
  
  for (int index=0;index<(*vetor[i])->neighbours-1;index++) { // put all old neighbours in the new array
    NewlinkNeighbours[index] = (*vetor[i])->neighboursLink[index];
  }
  if (store->next == NULL){ // se só tiver um vértice na lista
    store->next = (struct vertice*)malloc(sizeof(struct vertice));
    store->next->back = (*vetor[i]);
    store->next->nameV = vj;
    putVerticeName(store->next, store->next->nameV);
    store->next->next = NULL;
    store->next->weight = w;
    NewlinkNeighbours[(*vetor[i])->neighbours-1] = store->next;
    free((*vetor[i])->neighboursLink);
    (*vetor[i])->neighboursLink = NewlinkNeighbours;
  } else {
    while (store->next->next!=NULL) { 
      previous = store;
      store = store->next;
      
    }
    store->next->next = (struct vertice*)malloc(sizeof(struct vertice));
    // printf("vertice name: %i\n", previous->nameV);
    store->next->next->back = previous->next;
    store->next->next->nameV = vj;
    putVerticeName(store->next->next, vj);
    store->next->next->next = NULL;
    store->next->next->weight = w;
    NewlinkNeighbours[(*vetor[i])->neighbours-1] = store->next->next;
    free((*vetor[i])->neighboursLink);
    (*vetor[i])->neighboursLink = NewlinkNeighbours;
  }
  
  // printf("\n\n");
  // printf("vertice number: %i\n", (*vetor[2])->next->nameV);
  // printf("vertice name: %s\n", (*vetor[2])->next->name);
  // printf("\n\n");
  // printf("\n\n");
  // printf("vertice number: %i\n", (*vetor[2])->next->next->back->nameV);
  // printf("vertice name: %s\n", (*vetor[2])->next->next->back->name);
  // printf("\n\n");

  return 1;
  

  // -1 = um dos vértices não existe
  // 0 = aresta ja existe
  // 1 = aresta adicionada
}


void Grafo2(lista_vertices** vetor, int qtdV){
  printf("\n\n");
  for (int i=0;i<qtdV;i++){
    printf("[v%i]->", (*vetor[i])->nameV);
    for(int j=0;j<(*vetor[i])->neighbours;j++){
      printf("[v%i]%i->", (*vetor[i])->neighboursLink[j]->nameV,(*vetor[i])->visited);
    }
    printf("\n\n");
  }
}


// void Grafo2(lista_vertices** vetor, int qtdV){
//   printf("\n\n");
//   for (int i=0;i<qtdV;i++){
//     printf("[v%i]->", (*vetor[0])->nameV);
//     printf("[v%i]->", (*vetor[0])->neighboursLink[0]->nameV);
//     printf("[v%i]->", (*vetor[0])->neighboursLink[0]->neighboursLink[0]->nameV);

//     printf("\n\n");
//   }
// }


