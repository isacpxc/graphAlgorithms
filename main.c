#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include "basicF.h"
#include "search.h"



int main(){

    setlocale(LC_ALL,"portuguese");

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
    int lengthV = 0;
    while (i < before + steps) { // nV will receive an string with the number referent to the number of vertices
        if (i >= before) {
            c = getc(instructions);
            nV[i - before] = c;
            lengthV++;
        } else {
            c = getc(instructions);
        }
        i++;
    }

    //strlen deu problema, por isso usei uma var lengthV
    for (int i=0, index = lengthV-1;i<steps;i++, index--){
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

    int lengthE = 0;
    while (i < before + steps) { // nE will receive an string with the number referent to the number of vertices
        if (i >= before) {
            c = getc(instructions);
            nE[i - before] = c;
            lengthE++;
        } else {
            c = getc(instructions);
        }
        i++;
    }
    
    for (int i=0, index = lengthE-1;i<steps;i++, index--){
        qtdE+= pow(10, index)*((int)nE[i]-48);
    }

    /*CATCHING NUMBER OF EDGES - END*/

    /*SEPARATING EDGES AND WEIGHTS IN 2 FILES .TXT - START*/


    c = fgetc(instructions);
    for (i=0;c==' ' || c == '\n';i++){  // move pointer to the start of the instructions of edges
        c = fgetc(instructions);
    }

    fopen("edges.txt", "a");  // creating .txt for the edges
    FILE* edges_instructions = fopen("edges.txt", "w+"); // pointer for the edge file
    char e = ' '; // receive char of the pointer of edges
    FILE* edges_instructionsEnd = fopen("edges.txt", "w+");
    char ee = ' '; 

    fopen("edgesW.txt", "a"); // creating .txt for the edges
    FILE* edges_weights = fopen("edgesW.txt", "w+"); // pointer for the edge file
    char w = ' '; // receive char of the pointer of weights

    int space_count = 0;

    for(i=0;c != EOF;){ // filter whats is edges and weights, sending to them respectives files
        if (space_count <= 3) fprintf(edges_instructions, "%c", c);
        if (space_count == 3) space_count = 0;
        if (space_count == 2) {
            c = fgetc(instructions);
            while (c != ' ' && c!='\n' && c != EOF) {
                fprintf(edges_weights, "%c", c);
                c = fgetc(instructions);
            }
            space_count++;
            fprintf(edges_instructions, "%c", '\n');
            fprintf(edges_weights, "%c", '\n');
        }
        c = fgetc(instructions);
        if (c == ' ') space_count++;
    }

    fclose(instructions); // close entrada.txt


    /*SEPARATING EDGES AND WEIGHT IN 2 FILES .TXT - END*/
    rewind(edges_instructions);
    rewind(edges_weights);


    // CATCHING ALL EDGES VALUES IN MATRIX - START

    space_count = 0;
    steps = 0;
    int current_position = 0;
    double edgesM[3][qtdE];
    fseek( edges_instructions, 0, SEEK_SET ); // 0 -> n-1
    e = fgetc(edges_instructions);
    int current_number = 0;
    int disconnect=0;
    // inserindo arestas na matriz
    for (int count_columns = 0;count_columns < qtdE;count_columns++){
        for (;space_count<2;space_count++){
            
            while (e != ' ' && e!='\n'){ // to the position of char 1 before -> after ' '
                current_position++;
                steps++;
                e = fgetc(edges_instructions);
            }
            if (e == '\n') disconnect++;
            else disconnect=0;
            
            current_number = 0;
            fseek(edges_instructions, (current_position-steps), SEEK_SET);

            for (i = 0;i<steps;i++){
                current_number+= pow(10, steps-i-1)*((int)fgetc(edges_instructions)-48);
            }
            
            
            if (!disconnect) edgesM[space_count][count_columns] = current_number;
            else {space_count++;count_columns--;current_position--;}

            current_position++;
            fseek(edges_instructions, current_position, SEEK_SET);
            steps = 0;
            e = fgetc(edges_instructions);



        }
        space_count=0;
        current_position+=2;
        e = fgetc(edges_instructions);
    }

    // inserindo pesos na matriz
    current_position = 0;
    steps = 0;
    e = fgetc(edges_weights);
    for (int count_line=0;count_line<qtdE;count_line++){
        while (e !='\n'){ // to the position of char 1 before -> after ' '                current_position++;
            current_position++;
            steps++;
            e = fgetc(edges_weights);
        }

        current_number = 0;
        fseek(edges_weights, (current_position-steps), SEEK_SET);
        e = fgetc(edges_weights);
        for (i = 0;i<steps;i++){
            current_number+= pow(10, steps-i-1)*((int)e-48);
        }
        edgesM[2][count_line] = current_number;

        current_position++;
        fseek(edges_weights, current_position, SEEK_SET);
        steps = 0;
        e = fgetc(edges_weights);
        e = fgetc(edges_weights);
        current_position++;
    }

    // imprimir matriz
    // for (i=0;i<3;i++){
    //     for (int j=0;j<qtdE;j++){
    //         printf("%0.2f ", edgesM[i][j]);
    //     }
    //     printf("%c",'\n');
    // }
    


    // CATCHING ALL EDGES VALUES IN MATRIX - END
    
    // creating adjacency list
    
    // lista_vertices** vetor;
    // vetor = create_adjList(qtdV, qtdE, edgesM); // ficar de olho no tipo recebido
    lista_vertices** vetor = create_adjList(qtdV, qtdE, edgesM);
    Grafo(vetor, qtdV);  // FUNCTION
    // Grafo2(vetor, qtdV);
    // printf("Insira o número do vértice: ");
    // int v = 0;
    // scanf("%d",&v);
    // printf("%i",Evertice(vetor, 3, qtdV)); // FUNCTION
    // printf("%i", ExisteAresta(vetor, 4, 2, 2, qtdV)); //FUNCTION
    // printf("%i", Eadj(vetor, 4, 2,qtdV));
    
    AddAresta(vetor, 6, 3, 2, qtdV);
    // qtdE++;
    printf("\n\nDEPOIS=========\n\n");
    // Grafo2(vetor, qtdV);
    Grafo(vetor, qtdV);
    RemoveAresta(vetor, 2, 4, 2, qtdV);
    // printf("\n\nDEPOISrem=========\n\n");
    Grafo(vetor, qtdV);
    // teste((vetor[0]));
    // DFS((*vetor[0]));
    system("pause");
    return 0;
}
