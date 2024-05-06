#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a class to represent a graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Breadth First Traversal
    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();
            cout << currentVertex << " ";

            for (int adjacentVertex : adj[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    queue.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    // Create a graph
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    cout << "Breadth First Traversal starting from vertex 0: ";
    graph.BFS(0);
    cout << endl;

    return 0;
}

