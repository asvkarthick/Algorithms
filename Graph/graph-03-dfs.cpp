/* Implementation of Graph
 * Depth First Search (DFS)
 * Check if path exists between two nodes
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>

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
        for (int i = 0; i <= nVertices; i++) {
            std::cout << i << " : ";
            for (auto& x : vertices[i]) std::cout << x->y << " -> ";
            std::cout << "NULL" << std::endl;
        }
    }

    bool checkPath(int beg, int end)
    {
        enum NodeState
        {
            UNDISCOVERED,
            DISCOVERED,
            PROCESSED
        };
        std::queue<int> q;
        std::vector<NodeState> state(nVertices);
        q.push(beg);
        for (int i = 0; i < nVertices; i++)
            state[i] = UNDISCOVERED;
        state[beg] = DISCOVERED;
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            auto& l = vertices[d];
            auto it = l.begin();
            while (it != l.end()) {
                EdgeNode *node = *it;
                int y = node->y;
                if (y == end) return true;
                if (state[y] == UNDISCOVERED) {
                    q.push(y);
                    state[y] = DISCOVERED;
                }
                it++;
            }
            state[d] = PROCESSED;
        }
        return false;
    }

    void findPath()
    {
        int startPos, endPos;
        std::cout << "Enter starting position : ";
        std::cin >> startPos;
        std::cout << "Enter ending position : ";
        std::cin >> endPos;
        if (checkPath(startPos, endPos))
            std::cout << "Path found from " << startPos << " to " << endPos << std::endl;
        else
            std::cout << "There is no path from " << startPos << " and " << endPos << std::endl;
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
    g->findPath();
    delete g;
    return 0;
}
