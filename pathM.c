#include <stdio.h>
#include <stdlib.h>
#include "basicF.h"

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

int* vAuxOld; 
int* vAuxNew;


int* CustoMinimo(struct vertice*** vetor, int vi){

  // for (int i=0;vetor[i]!=NULL;i++) printf("%i ", arrVOinddex);
      // for (int i=0;i<20;i++){
      //   for (int j=0;j<3;j++){
      //       printf("%.1f ", edges[i][j]);
      //   }
      //   printf("\n");
      // }
      // printf("\n");
  int i=0;
  // for(i=0;vetor[i]!=NULL;i++){
  //   if ((*vetor[i])->nameV != vi) (*vetor[i])->dist = INT_MAX;
  //   else (*vetor[i])->dist = 0;
  // } 

  int edgesQtd=0;

  for (i=0;vetor[i]!=NULL;i++) {
    edgesQtd += (*vetor[i])->neighbours;
  }
  int count = i-1;

  int a=0,b=0;
  for (size_t ui = 0; ui < edgesQtd; ui++) // extract max vertice number
  {
    for (size_t uj = 0; uj < 2; uj++)
    {
      b = (int)edges[ui][uj];
      if (a<b) a = b;
    }
    
  }
  
 
  double* distOld = (double*)malloc((a+1)*sizeof(double));
  for (i=0;i<a+1;i++) {
    distOld[i] = (double)INT_MAX;
    
  }
  distOld[vi] = 0;
  // for (size_t i = 0; i<a+1; i++)
  // {
  //   printf("%0.f ", distOld[i]);
  // }


  for (int indexI=0;indexI<edgesQtd;indexI++){
      // printf("%i ", (int)edges[indexI][0]);
      if ((int)edges[indexI][0] == vi){
        distOld[(int)edges[indexI][1]] = edges[indexI][2];
      }
  }

  // for (size_t i = 0; i<a+1; i++)
  // {
  //   printf("%0.f ", distOld[i]);
  // }
  
  
  // for (size_t index = 0; index<a+1; index++)
  // {
  //   printf("%.0f ", distOld[index]);
  // }    
  // printf("\n\n");
  // [inf, inf, 5, inf, 0, inf, 5, 4]
  // for (int x = 0; x < count; x++) distCurrent[x] = distOld[x];

  // for (int x=0;x<count;x++){
    for (int index=0;index<edgesQtd;index++){
      // printf("\n");
      // printf("edges[index][0]] = %i", (int)edges[index][0]);
      // printf("\n");
      // printf("edges[index][1]] = %i", (int)edges[index][1]);
      // printf("\n");  
      // printf("peso = %.0f",edges[index][2]);
      // printf("\n");
      if ( distOld[(int)edges[index][0]]>distOld[(int)edges[index][1]]+edges[index][2] && distOld[(int)edges[index][1]]!=INT_MAX){
        distOld[(int)edges[index][0]] = distOld[(int)edges[index][1]]+edges[index][2];
      }
      for (int k=0;k<index;k++){
        if ( distOld[(int)edges[k][0]]>distOld[(int)edges[k][1]]+edges[k][2] && distOld[(int)edges[k][1]]!=INT_MAX){
          distOld[(int)edges[k][0]] = distOld[(int)edges[k][1]]+edges[k][2];
        }
      }


    }  
    // for (int x = 0; x < count; x++) distOld[x]=distCurrent[x];
  // }

  // distOld = [inf, inf, 5, inf, 0, inf, 5, 4]
  // distCurrent = [inf, inf, 5, inf, 0, inf, 5, 4]

  // for (size_t index = 0; index<a+1; index++)
  // {
  //   printf("%.0f ", distOld[index]);
  // }   

  

}

int CaminhoMinimo(lista_vertices** vetor,int vi,int vj){
  

}