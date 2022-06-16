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

int arrowNumber(int current,int qtdE, double edgeM[][qtdE]){
  int arrows = 0;
  for (int i=0;i<qtdE;i++){
    if (current == (int)edgeM[0][i]){
      arrows++;
    }
  }

  return arrows;
}