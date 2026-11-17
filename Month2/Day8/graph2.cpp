#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList; // Adjacency list to store edges
    bool isDirected;

public:
    // Constructor
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        isDirected = directed;
        adjList.resize(vertices);
    }

    // Add an edge between vertex u and vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u); // Add reverse edge for undirected graphs
        }
    }

    // Print the adjacency list representation
    void printGraph() {
        cout << "Graph Adjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    // Breadth-First Search (Level-by-level traversal)
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS starting from vertex " << startVertex << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // Depth-First Search Helper (Recursive)
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Depth-First Search (Explores as far as possible along each branch)
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << "\n";
    }
};

int main() {
    // Create an undirected graph with 5 vertices (0 to 4)
    Graph g(5, false);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    cout << "\n";

    g.BFS(0);
    g.DFS(0);

    return 0;
}