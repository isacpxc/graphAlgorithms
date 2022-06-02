#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

struct graph {
    int nameV;
    char* name;
    double weight;
    struct graph* next;
};



int main(){
    FILE *instructions;  //will receive the .txt
    char c = 'a';
    int qtdV = 0; // number of vertices
    int qtdE = 0; // number of edges



    instructions = fopen("entrada.txt","r");
    if (instructions == NULL) {
        printf("Erro ao abrir o arquivo");
        return -1;
    }

    int cont = 0; //count whitespaces
    int steps = 0; // steps in .txt
    int before = 0; //count number os steps until the number of vertex
    int i = 0;

    /*CATCHING NAME - START*/

    do {  // this will catch how many decimal places the number has
        c = fgetc(instructions);
        if (c!=' ') steps++;
    } while(c != ' ');   // while(c != ' ')?

    char* nameG = (char*)malloc((steps+1)*sizeof(char));
    if (nameG == NULL) {
        printf("Erro ao salvar nome do grafo!");
        return 0;
    }

    instructions = fopen("entrada.txt", "r"); // reset pointer to the start of the file

    while (i < steps) { // nV will receive an string with the number referent to the number of vertices
        c = getc(instructions);
        nameG[i] = c;
        i++;
    }
    nameG[i] = '\0';


    /*CATCHING NAME - END*/

    /*CATCHING NUMBER OF VERTICES - START*/

    steps = 0;
    i = 0;

    instructions = fopen("entrada.txt", "r"); // reset pointer to the start of the file

    do {  // this will catch how many decimal places the number has
        c = fgetc(instructions);
        if (c == ' ') cont++;
        if (cont == 1 && c!=' ') steps++;
        if (cont < 1) before++;
    } while(cont < 2);

    char nV[steps];
    before++;

    instructions = fopen("entrada.txt", "r"); // reset pointer to the start of the file

    while (i < before + steps) { // nV will receive an string with the number referent to the number of vertices
        if (i >= before) {
            c = getc(instructions);
            nV[i - before] = c;
        } else {
            c = getc(instructions);
        }
        i++;
    }


    for (int i=0, index = strlen(nV)-1;i<steps;i++, index--){
        qtdV+= pow(10, index)*((int)nV[i]-48);
    }

    /*CATCHING NUMBER OF VERTICES - END*/

    // RESETING VALUES OF VARIABLES
    cont = 0;
    steps = 0;
    before = 0;
    i = 0;

    instructions = fopen("entrada.txt", "r"); // olhar depois, tente aproveitar o fato de não precisar resetar

    /*CATCHING NUMBER OF EDGES - START*/
    do {  // this will catch how many decimal places the number has
        c = fgetc(instructions);
        if (c == ' ') cont++;
        if (cont == 2 && c!=' ') steps++;
        if (cont < 2) before++;
    } while(cont < 3);

    char nE[steps];
    before++;

    instructions = fopen("entrada.txt", "r"); // reset pointer to the start of the file

    while (i < before + steps) { // nE will receive an string with the number referent to the number of vertices
        if (i >= before) {
            c = getc(instructions);
            nE[i - before] = c;
        } else {
            c = getc(instructions);
        }
        i++;
    }

    for (int i=0, index = strlen(nE)-1;i<steps;i++, index--){
        qtdE+= pow(10, index)*((int)nE[i]-48);
    }

    /*CATCHING NUMBER OF EDGES - END*/



    printf("%s", nameG);

    fclose(instructions); // to close the file

    return 0;
}
