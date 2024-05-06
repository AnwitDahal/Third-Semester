#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure to represent a vertex in the graph
struct Vertex {
    int id;
    int distance;
    bool visited;
};

// Define a structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Define a class to represent a graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>(V, 0));
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        adj[src][dest] = weight;
        adj[dest][src] = weight; // For undirected graph
    }

    // Function to find the vertex with the minimum distance
    int minDistance(vector<Vertex>& vertices) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (!vertices[v].visited && vertices[v].distance <= min) {
                min = vertices[v].distance;
                min_index = v;
            }
        }

        return min_index;
    }

    // Function to print the shortest path from source to destination
    void printShortestPath(int source, int dest, vector<Vertex>& vertices) {
        cout << "Shortest path from " << source << " to " << dest << " with distance " << vertices[dest].distance << ": ";
        int current = dest;
        vector<int> path;
        while (current != source) {
            path.push_back(current);
            current = vertices[current].id;
        }
        path.push_back(source);

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }

    // Function to find the shortest path using Dijkstra's algorithm
    void DijkstraShortestPath(int source) {
        vector<Vertex> vertices(V);
        
        for (int i = 0; i < V; i++) {
            vertices[i].id = i;
            vertices[i].distance = INT_MAX;
            vertices[i].visited = false;
        }

        vertices[source].distance = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(vertices);

            vertices[u].visited = true;

            for (int v = 0; v < V; v++) {
                if (!vertices[v].visited && adj[u][v] && vertices[u].distance != INT_MAX && vertices[u].distance + adj[u][v] < vertices[v].distance) {
                    vertices[v].distance = vertices[u].distance + adj[u][v];
                }
            }
        }

        // Print the shortest paths
        for (int i = 0; i < V; i++) {
            if (i != source && vertices[i].distance != INT_MAX) {
                printShortestPath(source, i, vertices);
            }
        }
    }
};

int main() {
    // Create a graph
    Graph graph(5);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 10);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 1);

    // Find and print the shortest paths from source vertex 0
    graph.DijkstraShortestPath(0);

    return 0;
}

