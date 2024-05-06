#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Define a class to represent a graph
class Graph {
    int V; // Number of vertices
    vector<Edge> edges; // Vector to store edges

public:
    Graph(int vertices) : V(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Utility function to find the set of an element i
    int find(vector<Subset>& subsets, int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    // Utility function to perform union of two sets
    void Union(vector<Subset>& subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        // Attach smaller rank tree under root of high rank tree
        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            // If ranks are the same, make one as root and increment its rank by one
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    // Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
    void KruskalMST() {
        vector<Edge> result; // Stores the edges of the MST
        int e = 0; // Index variable for result[]
        int i = 0; // Index variable for sorted edges[]
        
        // Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<Subset> subsets(V);
        for (int v = 0; v < V; v++) {
            subsets[v] = {v, 0};
        }

        // Number of edges to be taken is equal to V-1
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);

            // If including this edge does not cause cycle, include it in the result and increment the index
            if (x != y) {
                result.push_back(next_edge);
                Union(subsets, x, y);
                e++;
            }
        }

        // Print the MST
        cout << "Minimum Spanning Tree (MST) edges:" << endl;
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
    }
};

int main() {
    // Create a graph
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find and print the Minimum Spanning Tree (MST)
    graph.KruskalMST();

    return 0;
}

