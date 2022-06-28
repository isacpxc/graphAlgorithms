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
};

int t = 0;
//MAKE RETURN DINAMIC ARRAY
void DFS(struct vertice* v, int* res){
  
  res[t] = v->nameV;
  t++;
  // printf("[v%i]", v->nameV);
  
  v->visited = 0;
  for (int i=0;i<v->neighbours;i++){
    if (v->neighboursLink[i] != NULL){
      if (v->neighboursLink[i]->visited == -1){
        DFS(v->neighboursLink[i], res);
      }
    }
    
    
  }
  
}

void BFS(struct vertice* v,int* res){
  v->visited = 1;
  if (t==0){/* printf("[v%i]", v->nameV); */res[t] = v->nameV;t++;}
  for (int i=0;i<v->neighbours;i++){
    if (v->neighboursLink[i]->visited == -1)
    {  /* if (v->neighboursLink[i]->visited == -1) printf("[v%i]", v->neighboursLink[i]->nameV); */
      if (i==0){
        
        res[t] = v->neighboursLink[i]->nameV;
        v->neighboursLink[i]->visited = 0;
        t++;
      } else {
        v->neighboursLink[i]->visited = 0;
        res[t] = v->neighboursLink[i]->nameV;
        t++;
      }
    }
  }

  for (int i =0;i<v->neighbours;i++){
    if (v->neighboursLink[i]->visited == 0) BFS(v->neighboursLink[i], res);
  }
}