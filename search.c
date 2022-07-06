#include <stdio.h>
#include <stdlib.h>

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
};

int t = 0;
int first = 0;
//MAKE RETURN DINAMIC ARRAY
void DFS(struct vertice* v, int* res){
  if (t==0) first = v->nameV;
  res[t] = v->nameV;
  t++;
  // printf("[v%i]", v->nameV);
  
  v->visited = 0;
  for (int i=0;i<v->neighbours;i++){
    if (v->neighboursLink[i] != NULL){
      if (v->neighboursLink[i]->visited == -1){ // se não visitado
        DFS(v->neighboursLink[i], res); // envia vizinhos
      }
    }
    
    
  }
  if (first == v->nameV) t = 0;
}

void BFS(struct vertice* v,int* res){
  if (t==0) first = v->nameV;
  v->visited = 1;
  if (t==0){/* printf("[v%i]", v->nameV); */res[t] = v->nameV;t++;}
  for (int i=0;i<v->neighbours;i++){
    if (v->neighboursLink[i]->visited == -1) // se o vertice não foi visitado
    {  /* if (v->neighboursLink[i]->visited == -1) printf("[v%i]", v->neighboursLink[i]->nameV); */

        res[t] = v->neighboursLink[i]->nameV; 
        v->neighboursLink[i]->visited = 0; // marca como visitado
        t++;
    }
  }

  for (int i =0;i<v->neighbours;i++){
    if (v->neighboursLink[i]->visited == 0) BFS(v->neighboursLink[i], res); // envia vertices que acabaram de ser marcados por recursão
  }
  if (first == v->nameV) t = 0;
}