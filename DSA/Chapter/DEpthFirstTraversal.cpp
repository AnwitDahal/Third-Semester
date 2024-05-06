#include <iostream>
#include <vector>
#include <stack>
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

    // Depth First Traversal
    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(startVertex);
        visited[startVertex] = true;

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";

            for (int adjacentVertex : adj[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    stack.push(adjacentVertex);
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

    cout << "Depth First Traversal starting from vertex 0: ";
    graph.DFS(0);
    cout << endl;

    return 0;
}

