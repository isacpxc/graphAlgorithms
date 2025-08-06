# Estruturas de Dados em Grafos (C)

Este projeto, desenvolvido em C, é uma implementação de estruturas de dados e algoritmos fundamentais para manipulação de grafos. O sistema é capaz de ler a definição de um grafo a partir de um arquivo de texto, construir uma representação em memória utilizando listas de adjacência e executar operações como remoção de arestas e algoritmos de busca.

## Visão Geral do Projeto

O objetivo principal é demonstrar a implementação e o funcionamento de um grafo. A aplicação lê um arquivo `entrada.txt` que define o nome do grafo, o número de vértices e arestas, e as conexões (com seus respectivos pesos). A partir desses dados, o programa constrói uma lista de adjacência para representar o grafo e realiza algumas operações básicas sobre ele.

## Estrutura do Projeto

O código-fonte está modularizado em vários arquivos para organizar melhor as funcionalidades:

  - **`main.c`**: Ponto de entrada do programa. É responsável por ler e interpretar o arquivo `entrada.txt`, extrair os dados do grafo (vértices, arestas e pesos), e orquestrar a criação da estrutura de dados. Ao final, demonstra a remoção de uma aresta.
  - **`basicF.c` / `basicF.h`**: Contém as funções essenciais para a manipulação do grafo. Define a estrutura `vertice` e implementa a criação da lista de adjacência (`create_adjList`) , a impressão do grafo (`Grafo`) , a adição (`AddAresta`) e remoção (`RemoveAresta`) de arestas, além de funções para verificar a existência de vértices e arestas.
  - **`search.c` / `search.h`**: Implementa os algoritmos de busca em grafos, incluindo a Busca em Profundidade (DFS) e a Busca em Largura (BFS).
  - **`pathM.c` / `pathM.h`**: Contém a lógica para algoritmos de caminho mínimo, como a função `CustoMinimo`.
  - **`helpers.c` / `helpers.h`**: Módulo com funções auxiliares utilizadas em outras partes do código, como `arrowNumber` (para contar o número de arestas de um vértice) e `verifyPosition` (para checar se um elemento já existe em um vetor).
  - **`entrada.txt`**: Arquivo de entrada que define o grafo a ser processado.

## Funcionalidades Implementadas

  - **Parsing de Arquivo**: O programa lê um arquivo `.txt` e extrai dinamicamente o nome do grafo, a quantidade de vértices e a quantidade de arestas.
  - **Criação de Lista de Adjacência**: Constrói um grafo em memória usando uma lista de adjacência a partir dos dados lidos do arquivo.
  - **Manipulação de Arestas**:
      - Adição de novas arestas ao grafo (`AddAresta`).
      - Remoção de arestas existentes (`RemoveAresta`), demonstrada na função `main`.
  - **Algoritmos de Busca**:
      - **DFS (Busca em Profundidade)**: Implementação do algoritmo para percorrer o grafo.
      - **BFS (Busca em Largura)**: Implementação do algoritmo para percorrer o grafo.
  - **Caminho Mínimo**:
      - Início da implementação de um algoritmo para encontrar o custo mínimo entre vértices (`CustoMinimo`).

## Como Compilar e Executar

## OBSERVAÇÃO

- evitar espaços após inserção de cada linha

1.  **Pré-requisitos**:

      * É necessário ter um compilador C (como o GCC) instalado.

O programa irá imprimir a lista de adjacência inicial, seguida pela lista após a remoção de uma aresta, e então pausar a execução.
