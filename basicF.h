
// WARNING, APENAS USE A MATRIZ PARA GERAR O GRAFO INICIAL, POIS SE FOREM REMOVIDAS/ ADICIONADAS ARESTAS, NÃO VAI DAR CERTO
typedef struct vertice* lista_vertices;
extern double** edges;
extern int*  arrVOinddex;
extern int vetorLen;
extern int* allVertices;

lista_vertices** create_adjList(int, int, double (*)[*]);
size_t lengthInt(int);

void Grafo(lista_vertices**);
int Evertice(lista_vertices**, int);
int ExisteAresta(lista_vertices** vetor, int vi, int vj,double w);
int Eadj(lista_vertices** vetor, int vi, int vj);
int AddAresta(lista_vertices** vetor, int vi, int vj,double w);
int RemoveAresta(lista_vertices** vetor, int vi, int vj , double w);
void Grafo2(lista_vertices** vetor);
// void teste(struct vertice** v);