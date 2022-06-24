#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
  v->name = (char*)malloc((tam+1)*sizeof(char));

  sprintf(charN, "%d", number);  // put number on char vector
  

  for (int i=0;i<tam+1;i++){
    if (i == 0) v->name[i] = 'v';
    else v->name[i] = charN[i-1];
  }
  v->name[tam+2] = '\0';

  // printf("%s \n", v->name);
  // printf("aqui esta o nome: %x ", v->name);

}

int verifyPosition(int current, int* ok, int tam){
  int check = 0;
  
  for (int i=0;i<tam;i++){
    if (ok[i] == current) return 1;
  }
  return 0;
}

int arrowNumber(int current,int qtdE, double edgeM[][qtdE]){
  int arrows = 0;
  for (int i=0;i<qtdE;i++){
    if (current == (int)edgeM[0][i]){
      arrows++;
    }
  }

  return arrows;
}

void putVerticeIndex(int* vet){
  FILE* edges_instructions = fopen("edges.txt", "r");
  FILE* edges_instructionsEnd = fopen("edges.txt", "r");
  char e = fgetc(edges_instructions);
  char ee;
  int indexCurrent=1;
  int i,count,num=0,passage=0;
  char* numberString;
  
  while(e != EOF){
    if (e != ' ' && e != '\n'){
      for(i=0;(e!=' ' && e!='\n');i++) {
        e = fgetc(edges_instructions);  //counting decimal cases
        if (e == EOF) {
          i++;
          break;
        }
      }
      //after the last number(before EOF), there's just a '\n' and the EOF marker, diferent of the other 'ends' => space(" ") and then '\n'
      if (passage>0) fseek(edges_instructionsEnd,indexCurrent, SEEK_SET);
      ee = fgetc(edges_instructionsEnd);
      if (e == '\n') indexCurrent++;
      if (e == '\n' && ee == '\n') indexCurrent--;
      
      fseek(edges_instructions,indexCurrent-i, SEEK_SET);
      
      // e = fgetc(edges_instructions);
      // printf("%c", e);
      // e = fgetc(edges_instructions);
      // printf("%c", e);
      numberString = (char*)malloc((i+1)*sizeof(char));
      for(count=0;count<i;count++){
        e = fgetc(edges_instructions);
        numberString[count] = e;
        indexCurrent++;
      }
      numberString[count] = '\0';
      
      num=0;
      for (int iS=0, index = i-1;iS<count;iS++, index--){
        num+= pow(10, index)*((int)numberString[iS]-48);
      }
      e = fgetc(edges_instructions);
    } else {
      
      e = fgetc(edges_instructions);
      
      if (e != '\n')indexCurrent++;
      else indexCurrent+=2;
    }


    if ((passage == 0 || verifyPosition(num,vet,passage) == 0)){ // C vai ler os condicionais da esquerda para a direita, assim dessa forma é melhor
      vet[passage] = num;
      passage++;
    }
    
    

  }
  //   for (size_t i = 0; i < passage; i++)
  // {
  //   printf("%i ",vet[i]);
  // }
  
}


int verifyDiconVertex(int qtdE, int current, double edgeM[][qtdE]){
  int count=0;
  for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 0; j < qtdE; j++) if (edgeM[i][j] != current) count++;
  }
  if (count == 2*qtdE) return 1; // if the vertex doesn't exist in edgeM
  return -1;
  
}