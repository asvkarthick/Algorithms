#include <iostream>
#include <stdlib.h>

#define MAXV 100

typedef struct Edgenode
{
    int y;
    int weight;
    struct Edgenode *next;
} Edgenode;

typedef struct Graph
{
    Edgenode *vertices[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
    bool directed;
} Graph;

void initializeGraph(Graph *g, bool directed)
{
    int i;

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for(i = 1; i <= MAXV; i++)
    {
        g->vertices[i] = nullptr;
        g->degree[i] = 0;
    }
}

void insertEdge(Graph *g, int x, int y, bool directed)
{
    Edgenode *node;

    node = (Edgenode*) malloc(sizeof(*node));
    node->y = y;
    node->weight = 0;
    node->next = g->vertices[x];
    g->vertices[x] = node;

    if(directed == false)
        insertEdge(g, y, x, true);
    else
        g->nedges++;
}

void printGraph(Graph *g)
{
    int i;
    Edgenode *node;

    for(i = 1; i <= g->nvertices; i++)
    {
        node = g->vertices[i];
        std::cout << i << " : ";
        while(node != nullptr)
        {
            std::cout << node->y << " -> ";
            node = node->next;
        }
        std::cout << "NULL" << std::endl;
    }
}

void buildGraph(Graph *g, bool directed = true)
{
    int x, y, i, edges;

    initializeGraph(g, directed);

    std::cout << "Enter the number of vertices : ";
    std::cin >> g->nvertices;

    std::cout << "Enter the number of edges : ";
    std::cin >> edges;

    for(i = 0; i < edges; i++)
    {
        std::cout << "Edge:" << std::endl;
        std::cin >> x >> y;

        insertEdge(g, x, y, directed);
    }
}

int main(void)
{
    Graph *g = new Graph();
    buildGraph(g, true);
    std::cout << "Printing Graph" << std::endl;
    std::cout << "--------------" << std::endl;
    printGraph(g);

    return 0;
}
