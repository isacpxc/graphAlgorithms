#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basicF.h"
#include <string.h>
#include "helpers.h"
#include <stdbool.h>

double** edges; // to store all edges
int*  arrVOinddex; // who are the vertices


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
  double dist;
  struct vertice* dad;
}; // WARNING! se mudar aqui mude em todos os .c, onde struct vertice é definido



lista_vertices** create_adjList(int qtdV,int qtdE, double edgeM[][qtdE]) { // por enquanto vai ficar void
  edges = (double**)malloc(qtdE*sizeof(double*));
  for(int i=0,k=0;i<qtdE;i++){
    edges[i] = (double*)malloc(3*sizeof(double));
    for(int j=0;j<3;j++){
      k++;
      edges[i][j] = 0/* k */;
    }
  }

  for (int iE=0;iE<qtdE;iE++) {
    
    for (int jE = 0; jE<3 ; jE++){
      // printf("%.1f ", edgeM[jE][iE]);
      edges[iE][jE] = edgeM[jE][iE];
    }

  }


  lista_vertices** vetor = (lista_vertices**)malloc((qtdV+1)*sizeof(lista_vertices*));
  lista_vertices* nullTemp = (lista_vertices*)malloc(sizeof(lista_vertices));
  // nullTempV = NULL;
  nullTemp = NULL;
  vetor[qtdV] = nullTemp;



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
        // printf("%f \n", edgeM[1][i]);
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
    if (verifyDiconVertex(qtdE, allVertices[index], edgeM) > -1){
      struct vertice* v_current = (struct vertice*)malloc(sizeof(struct vertice));
      v_current->back = NULL;
      v_current->next = NULL;
      v_current->nameV = allVertices[index];
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
  
  int arrows = 0;
  
  // criação lista para cada vertice em next
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
      // if (i == 0){ // putting edges on edges matrix
      //   for (int index=0;index<arrows;index++){
      //     if (index==0) edges
      //   }
      // }
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


// LISTA 2 criação
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
    

  }

}



free(store);

return vetor;



  
  //            -----vetor------
  //            |  |  |  |  |  |
  //            [**] [**] [**] [**] [**] [**] 
  
  //            cada posição recebe um ponteiro de ponteiro
  //            que por sua vez aponta para o cara que aponta para o struct


}


void Grafo(lista_vertices** vetor){

  lista_vertices store = (lista_vertices)malloc(sizeof(struct vertice));
  printf("=====LISTAS DE ADJACÊNCIA=====");
  for (size_t i=0;vetor[i]!=NULL;i++){
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


int Evertice(lista_vertices** vetor, int v){
  
  bool conf = false;
  int count = 0;
  while ( (vetor[count] != NULL) && (conf == false) )
  {
    if ((*vetor[count])->nameV == v) conf = true;
    else count++;
  }
  
  return conf;
  
}



int ExisteAresta(lista_vertices** vetor, int vi, int vj,double w){
  // -1 = não existe um dos vértices aresta vi->vj
  // 0 = os vértices existem, mas não a aresta
  // 1 = existe a aresta vi->vj, mas não com o peso w
  // 2 = existe a aresta vi->vj com peso w
  if (Evertice(vetor, vi) == 0 || Evertice(vetor, vj) == 0) return -1;
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

int Eadj(lista_vertices** vetor, int vi, int vj){
  int conf = ExisteAresta(vetor, vi, vj, 0);
  if ( conf > 0) return 1;
  return 0;
}

int AddAresta(lista_vertices** vetor, int vi, int vj,double w){
  if(Evertice(vetor,vi) == 0 || Evertice(vetor, vj) == 0) return -1;
  if(Evertice(vetor,vi) == 1 && Evertice(vetor, vj) == 1) {
    if (ExisteAresta(vetor, vi, vj, 0) != 0) return 0;
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
    store->weight = w;
    store->next->weight = 0.505303404;
    NewlinkNeighbours[(*vetor[i])->neighbours-1] = store->next;
    free((*vetor[i])->neighboursLink);
    (*vetor[i])->neighboursLink = NewlinkNeighbours;

  } else {
    while (store->next->next!=NULL) { 
      previous = store;
      store = store->next;
      (*vetor[i])->neighbours++;
    }
    store->next->next = (struct vertice*)malloc(sizeof(struct vertice));
    
    // printf("vertice name: %i\n", previous->nameV);
    store->next->next->back = previous->next;
    store->next->next->nameV = vj;
    putVerticeName(store->next->next, vj);
    store->next->next->next = NULL;
    store->next->weight = w;
    store->next->next->weight = 0.505303404;
    NewlinkNeighbours[(*vetor[i])->neighbours-1] = store->next->next;
    free((*vetor[i])->neighboursLink);
    (*vetor[i])->neighboursLink = NewlinkNeighbours;
    (*vetor[i])->neighbours++;
    
  }
  
  

  

  // -1 = um dos vértices não existe
  // 0 = aresta ja existe
  // 1 = aresta adicionada
}

int RemoveAresta(lista_vertices** vetor, int vi, int vj , double w){
  if (ExisteAresta(vetor, vi, vj, w) != 2) {printf("Não foi possível remover aresta!");return 0;}
  lista_vertices store = (lista_vertices)malloc(sizeof(struct vertice));
  
  int i=0;
  
  for (i=0;vi!=(*vetor[i])->nameV;i++) store=(*vetor[i]);
  store=(*vetor[i]); // current
  
  store = store->next; // first adj of (*vetor[i])
  lista_vertices previous = (lista_vertices)malloc(sizeof(struct vertice));
  previous = (*vetor[i]); // first adj of (*vetor[i])

  
  while (store->nameV != vj || store->back->weight!=w){
    store = store->next; //next of adj of (*vetor[i])
    previous = store->back; // laways 1 step back of store
    
  }

  // CHANGING LIST ADJ IN next - START
  if (store->next == NULL) { // last one of adj
    previous->next = NULL;
    previous->weight = 0.505303404;
  }
  else{ // previous receive next of store and his weight, and change back of the next of store
    previous->next = store->next;
    previous->weight = store->weight;
    store->next->back = previous;
  }
  // CHANGING LIST ADJ IN next - END
  

  if ((*vetor[i])->neighbours == 1){ // if adj has just 1 element
    lista_vertices* NewlinkNeighbours = (lista_vertices*)malloc(sizeof(lista_vertices));
    free((*vetor[i])->neighboursLink);
    (*vetor[i])->neighboursLink = NewlinkNeighbours;
    (*vetor[i])->neighbours--;
    (*vetor[i])->weight = 0.505303404;
    
    return 1;
  }


  lista_vertices* NewlinkNeighbours = (lista_vertices*)malloc((*vetor[i])->neighbours*sizeof(lista_vertices)); 

  // CHANGING LIST ADJ IN neighboursLink - START
  for (int index=0,indexNew=0;index<(*vetor[i])->neighbours;index++) { // put all old neighbours in the new array

    
    if ((*vetor[i])->neighboursLink[index]->nameV != vj) {
      NewlinkNeighbours[indexNew] = (*vetor[i])->neighboursLink[index];
      indexNew++;
    } 
  }
  free((*vetor[i])->neighboursLink);
  (*vetor[i])->neighboursLink = NewlinkNeighbours;
  // CHANGING LIST ADJ IN neighboursLink - END


  (*vetor[i])->neighbours--;



  // (*vetor[i])->neighboursLink[i]
  
  
}


void Grafo2(lista_vertices** vetor){
  printf("\n\n");
  for (int i=0;vetor[i]!=NULL;i++){
    printf("[v%i]->", (*vetor[i])->nameV);
    for(int j=0;j<(*vetor[i])->neighbours;j++){
      printf("[v%i]->", (*vetor[i])->neighboursLink[j]->nameV);
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


