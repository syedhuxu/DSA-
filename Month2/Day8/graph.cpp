#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;

    void dfsUtil(int vertex, std::vector<bool> &visited)
    {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Add an undirected edge between u and v
    void addEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            std::cout << "Invalid vertices: " << u << ", " << v << "\n";
        }
    }

    // Remove an undirected edge between u and v
    void removeEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            auto itU = std::find(adjList[u].begin(), adjList[u].end(), v);
            if (itU != adjList[u].end())
            {
                adjList[u].erase(itU);
            }

            auto itV = std::find(adjList[v].begin(), adjList[v].end(), u);
            if (itV != adjList[v].end())
            {
                adjList[v].erase(itV);
            }
        }
    }

    // Print the graph representation
    void printGraph() const
    {
        std::cout << "\n--- Adjacency List ---\n";
        for (int i = 0; i < numVertices; ++i)
        {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i])
            {
                std::cout << " -> " << neighbor;
            }
            std::cout << "\n";
        }
    }

    // Breadth-First Search (BFS)
    void bfs(int startVertex)
    {
        if (startVertex < 0 || startVertex >= numVertices)
        {
            std::cout << "Invalid start vertex.\n";
            return;
        }

        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        std::cout << "BFS starting from vertex " << startVertex << ": ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            std::cout << current << " ";

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }

    // Depth-First Search (DFS)
    void dfs(int startVertex)
    {
        if (startVertex < 0 || startVertex >= numVertices)
        {
            std::cout << "Invalid start vertex.\n";
            return;
        }

        std::vector<bool> visited(numVertices, false);
        std::cout << "DFS starting from vertex " << startVertex << ": ";
        dfsUtil(startVertex, visited);
        std::cout << "\n";
    }
};

int main()
{
    // Initialize graph with 5 vertices (0 to 4)
    Graph g(5);

    // 1. Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // 2. Display the graph
    g.printGraph();

    // 3. Perform Traversals
    std::cout << "\n--- Traversals ---\n";
    g.bfs(0);
    g.dfs(0);

    // 4. Remove an edge and re-display
    std::cout << "\nRemoving edge between 1 and 4...";
    g.removeEdge(1, 4);
    g.printGraph();

    return 0;
}