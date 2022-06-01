#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct graph {
    int nameV;
    char name[5];
    struct graph* next;
};



int main(){
    FILE *instructions;  //will receive the .txt
    char c = 's';
    instructions = fopen("entrada.txt","r");
    if (instructions == NULL) {
        printf("Erro ao abrir o arquivo"); 
        return -1;
    }
    do {
        c = fgetc(instructions);
        printf("%c",c);
    } while(c != EOF);
    fclose(instructions);
    
    return 0;
}
