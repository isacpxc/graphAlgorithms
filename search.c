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

int DFS(struct vertice* v){
  printf("[v%i]", v->nameV);
  int vertice = v->nameV;
  int view = v->neighbours;
  v->visited = 0;
  for (int i=0;i<v->neighbours;i++){
    if (v->neighboursLink[i] != NULL){
      if (v->neighboursLink[i]->visited == -1){
        DFS(v->neighboursLink[i]);
      }
    }
    
    
  }
}

