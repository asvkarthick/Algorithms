/* Implementation of Graph
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>

class Graph
{
public:
    struct EdgeNode
    {
        EdgeNode(int yy, int w) : y(yy), weight(w)
        {
        }
        int y;
        int weight;
    };
    Graph(bool dir = true) : directed(dir), nVertices(0), nEdges(0)
    {
    }
    void insertNode()
    {
        int x, y;
        std::cout << "Enter x and y with spaces : ";
        std::cin >> x >> y;
        vertices[x].push_back(new EdgeNode(y, 0));
    }
    void buildGraph()
    {
        std::cout << "Enter number of vertices : ";
        std::cin >> nVertices;
        std::cout << "Enter number of edges : ";
        std::cin >> nEdges;
        for (int i = 0; i < nEdges; i++) {
            insertNode();
        }
    }
    void printGraph()
    {
        std::cout << "Contents of Graph" << std::endl;
        for (int i = 0; i < nVertices; i++) {
            std::cout << i << " : ";
            for (auto& x : vertices[i]) std::cout << x->y << " -> ";
            std::cout << "NULL" << std::endl;
        }
    }
private:
    std::map<int, std::list<EdgeNode*>> vertices;
    std::vector<int> degree;
    int nVertices;
    int nEdges;
    bool directed;
};

int main(void)
{
    Graph *g = new Graph();
    std::cout << "C++ implementation of Graph" << std::endl;
    g->buildGraph();
    g->printGraph();
    delete g;
    return 0;
}
