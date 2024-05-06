#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Define a structure to represent a vertex in the graph
struct Vertex {
    int parent;
    int key;
    bool mstSet;
};

// Define a class to represent a graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency matrix

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>(V, 0));
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        adj[src][dest] = weight;
        adj[dest][src] = weight; // For undirected graph
    }

    // Function to find the vertex with the minimum key value
    int minKey(vector<Vertex>& vertices) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (!vertices[v].mstSet && vertices[v].key < min) {
                min = vertices[v].key;
                min_index = v;
            }
        }

        return min_index;
    }

    // Function to print the Minimum Spanning Tree (MST)
    void printMST(vector<Vertex>& vertices) {
        cout << "Minimum Spanning Tree (MST) edges:" << endl;
        for (int i = 1; i < V; i++) {
            cout << vertices[i].parent << " - " << i << " : " << adj[i][vertices[i].parent] << endl;
        }
    }

    // Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
    void PrimMST() {
        vector<Vertex> vertices(V);
        
        for (int i = 0; i < V; i++) {
            vertices[i].parent = -1;
            vertices[i].key = INT_MAX;
            vertices[i].mstSet = false;
        }

        vertices[0].key = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(vertices);

            vertices[u].mstSet = true;

            for (int v = 0; v < V; v++) {
                if (adj[u][v] && !vertices[v].mstSet && adj[u][v] < vertices[v].key) {
                    vertices[v].parent = u;
                    vertices[v].key = adj[u][v];
                }
            }
        }

        // Print the MST
        printMST(vertices);
    }
};

int main() {
    // Create a graph
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Find and print the Minimum Spanning Tree (MST)
    graph.PrimMST();

    return 0;
}

