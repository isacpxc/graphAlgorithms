

typedef struct vertice* lista_vertices;

lista_vertices** create_adjList(int, int, double (*)[*]);
size_t lengthInt(int);
void putVerticeName(struct vertice*,int);
void Grafo(lista_vertices**, int);
int Evertice(lista_vertices**, int, int);
int AddAresta(lista_vertices** graph, int vi, int vj, int w, int qtdV)