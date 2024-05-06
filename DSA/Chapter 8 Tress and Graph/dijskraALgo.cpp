#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of (weight, vertex)

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u)); // If graph is undirected
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->second;
                int weight = it->first;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Shortest distances from source " << src << " to all other vertices:\n";
        for (int i = 0; i < V; ++i)
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 5, 1);

    int src = 0; // Source vertex

    g.dijkstra(src);

    return 0;
}

