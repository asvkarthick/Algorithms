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

typedef struct Queue
{
    int data;
    struct Queue *next;

    Queue() = delete;

    Queue(int d) : data(d), next(nullptr) {}

} Queue;

void enqueue(Queue *head, int data)
{
    Queue *node = new Queue(data);
    Queue *tail = head;

    if(tail == nullptr)
        return;

    while(tail->next != nullptr)
        tail = tail->next;

    tail->next = node;
}

int dequeue(Queue *head)
{
    Queue *node;
    int data = -1;

    if(head != nullptr && head->next != nullptr)
    {
        node = head->next;
        data = node->data;
        head->next = node->next;
        delete node;
    }

    return data;
}

void initQueue(Queue **head)
{
    *head = new Queue(0);
}

bool isEmpty(Queue *head)
{
    return head->next == nullptr;
}

int parent[MAXV + 1];

enum class State { UNDISCOVERED, DISCOVERED, PROCESSED };
State vertex_state[MAXV + 1];

bool bfs(Graph *g, int s, int d)
{
    Queue *q;
    int i;

    initQueue(&q);

    if(s > g->nvertices)
    {
        std::cout << "Invalid start vertex" << std::endl;
        return false;
    }

    for(i = 1; i <= g->nvertices; i++)
    {
        parent[i] = -1;
        vertex_state[i] = State::UNDISCOVERED;
    }

    vertex_state[s] = State::DISCOVERED;
    parent[s] = -1;
    enqueue(q, s);

    while(!isEmpty(q))
    {
        int u = dequeue(q);
        Edgenode *node = g->vertices[u];
        while(node != nullptr)
        {
            if(vertex_state[node->y] == State::UNDISCOVERED)
            {
                enqueue(q, node->y);
                parent[node->y] = u;
                vertex_state[node->y] = State::DISCOVERED;
                if(node->y == d)
                    return true;
            }
            node = node->next;
        }
        vertex_state[u] = State::PROCESSED;
        std::cout << "Processed: " << u << std::endl;
    }

    return false;
}

bool findPath(Graph *g, int s, int d)
{
    bool isPathPresent;

    isPathPresent = bfs(g, s, d);
    std::cout << "BFS over" << std::endl;

    if(!isPathPresent)
        return false;

    while(d != -1)
    {
        std::cout << d << " -> ";
        d = parent[d];
    }
    std::cout << "STOP" << std::endl;

    return true;
}

int main(void)
{
    Graph *g = new Graph();
    int d, s = 1;

    buildGraph(g, true);
    std::cout << "Printing Graph" << std::endl;
    std::cout << "--------------" << std::endl;
    printGraph(g);

    std::cout << "Enter destination: ";
    std::cin >> d;
    std::cout << "d = " << d << std::endl;

    bool isPathFound = findPath(g, s, d);
    if(isPathFound)
        std::cout << "Path found from " << s << " to " << d << std::endl;
    else
        std::cout << "Path not found from " << s << " to " << d << std::endl;

    return 0;
}
